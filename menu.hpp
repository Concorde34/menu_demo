
// file: menu.hpp

#pragma once

#include <cstring>
#include <iostream>

#define KEY_ESCAPE 27
#define KEY_Q 81
#define KEY_q 113
//#define K_ENTER 10

//constexpr char KEY_RETURN = '\n';

typedef unsigned short ushort;

    enum menu_type
    {
        SIMPLE_MENU,
        SIMPLE_CONTEXT_MENU,
        // Будет реализовано в будущем
        ADVANCED_MENU,
        ADVANCED_CONTEXT_MENU
    };

class Menu
{
    class menu_item
    {
    public:
        std::string str = "не инициализирован";
        bool is_init = false;
        void (*exec) ();
    };



    menu_item* menu;
    std::string menu_header;
    unsigned short size;
    menu_type mtype;
    //bool is_size_init = false;

public :
    Menu (unsigned short, std::string, menu_type mtype = menu_type::SIMPLE_MENU);
    void add_item (void (*) (), int, std::string);
    bool is_all_init () const;

    // Запустить меню
    void exec () const;

    // Деструктор
    ~Menu ();

};
