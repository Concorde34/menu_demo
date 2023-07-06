// file: main.cpp
#include <iostream>
#include "menu.hpp"
#include <ncurses.h>

using namespace std;

void foo1 ();
void foo2 ();
void foo3 ();
void foo4 ();
void foo5 ();
void foo6 ();

int main ()
{

    Menu menu1 (6, "Главное меню программы:");

    menu1.add_item(foo1, 0, "Первый пункт");
    menu1.add_item(foo2, 1, "Второй пункт");
    menu1.add_item(foo3, 2, "Третий пункт");
    menu1.add_item(foo4, 3, "Четвёртый пункт");
    menu1.add_item(foo5, 4, "Пятый пункт");
    menu1.add_item(foo6, 5, "Шестой пункт");

    menu1.exec();

    return 0;

}

void foo1 ()
{
    printw ("Выполнение foo1\n");
    char name [100];
}

void foo2 ()
{
    printw ("Выполнение foo2\n");
    refresh ();
}

void foo3 ()
{
    printw ("Выполнение foo3\n");
    refresh ();
}

void foo4 ()
{
    printw ("Выполнение foo4\n");
    refresh ();
}

void foo5 ()
{
    printw ("Выполнение foo5\n");
    refresh ();
}

void foo6 ()
{
    printw ("Выполнение foo6\n");
    refresh ();
}
