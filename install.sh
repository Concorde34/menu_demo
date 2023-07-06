#!/bin/sh

export LANG=ru_RU.UTF-8

# Установка библиотек и компилятора C++

sudo apt update
sudo apt install libncurses6 libstdc++6 libncurses5-dev libncursesw5-dev libgcc1 libc6 g++

# Скачивание исходного кода

sudo apt install git
sudo apt install wget
wget https://github.com/Concorde34/menu_demo/archive/refs/heads/main.zip

# Распаковка архива с исходным кодом

unzip main.zip
cd menu_demo-main

# Сборка

sudo apt install make
make
cd .. && mv menu_demo-main/main .
chmod +x main

# Очистка
rm -rf main.zip menu_demo-main
sudo apt autoremove

echo "Исполняемый файл программы находится в текущей дерриктории и называется main"
