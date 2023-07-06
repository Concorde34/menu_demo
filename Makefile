# menu Makefile
# Объявление переменных
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBS = -lncurses
CPP = main.cpp menu.cpp

# Версия
VERSION := 1.1

# Определение флага компилятора с версией
CPPFLAGS := -DVERSION=\"$(VERSION)\"

# Правило сборки исполняемого файла
EXECUTABLE = main_$(VERSION)
main: $(CPP)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(EXECUTABLE) $^ $(LIBS)
	@echo "Сборка завершена! Исполняемый файл: $(EXECUTABLE)"

# Правило очистки
clean:
	rm -f $(EXECUTABLE)
