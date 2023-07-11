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

    Menu menu ("Выберите пункт", menu_type::SIMPLE_MENU);

    menu.add_item(foo1, "Пункт первый");
    menu.add_item(foo2, "Пункт второй");
    menu.add_item(foo3, "Пункт третий");
    menu.add_item(foo4, "Пункт четвёртый");
    menu.add_item(foo5, "Пункт пятый");

    menu.exec();

    return 0;

}

void foo1 ()
{
    printw ("Выполнение foo1\n");
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
