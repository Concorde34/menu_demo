// file: menu.cpp

#include "menu.hpp"
#include <cstdio>
#include <curses.h>
#include <cwchar>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <system_error>
#include <ncurses.h>
#include <locale>

#define K_ENTER 10

//typedef unsigned short ushort;

Menu::Menu (ushort size, std::string menu_header, menu_type mtype)
{
    size > 0 ? this->size = size : throw std::invalid_argument ("Неверные размер меню");
    menu_header.empty () ? this->menu_header = "Меню:" : this->menu_header = menu_header;
    menu = new menu_item [size];
    this->mtype = mtype;
    //is_size_init = true;

}

void Menu::add_item (void (*exec) (), int inum , std::string item_str)
{

    if (inum >= 0 and inum < size)
    {
        // Починить.
        menu[inum].exec = exec;
        menu[inum].str = item_str;
        menu[inum].is_init = true;
    }
    else
    {
        throw std::out_of_range("Неправильный номер пункта меню");
    }
}

bool Menu::is_all_init () const
{
    for (ushort i = 0; i < size; ++i)
    {
        if ( not menu[i].is_init)
            return false;
    }
    return true;
}

void Menu::exec () const
{
    if (!is_all_init())
    {
        throw std::logic_error ("Не все элементы меню инициализированы");
    }
    // Будет реализовано потом
    // if (mtype != menu_type::SIMPLE_MENU)
    // {
    //
    // }
    // Инициализация ncurses

    setlocale (LC_ALL, "ru_RU.UTF-8");

    initscr();
    cbreak();
    noecho();

    // Отключаю мигающий курсор
    curs_set (0);

    keypad(stdscr, true); // Включение режима обработки командных клавиш

    // Иначе, продолжается выполнение метода:

    ushort selected = 0;
    int input;

    // Запуск цикла меню
    do
    {
        clear ();
        printw ( "\t%s\n" , this->menu_header.c_str()); printw ("\n");

        // Вывод пунктов меню в моменте

        for (ushort i = 0; i < size; ++i)
        {
            if (i == selected)
            {
                printw ("\t==>%s", menu[i].str.c_str());
            }
            else
            {
                printw ("\t\t%s", menu[i].str.c_str());
            }
            printw ("\n");
        }
        printw ("\n\t\tДля выхода нажмите кнопку 'Q'\n");
        refresh ();

        // Ожидание нажатия клавиши пользователем
        input = getch ();

        switch (input)
        {
        case KEY_UP:
            selected == 0 ? selected = size - 1 : --selected;
            break;
        case KEY_DOWN:
            selected == size - 1 ? selected = 0 : ++selected;
            break;
        case K_ENTER:
            clear ();
            menu[selected].exec();

            getch ();
        }

    } while (input != KEY_q and input != KEY_Q);

    refresh();

    endwin ();
}

// void Menu::print_menu () const
// {
//
// }

Menu::~Menu ()
{
    delete[] menu;
}
