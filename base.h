#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

// Структура для хранения данных объекта
typedef struct {
    char text[50]; // Текстовое поле фиксированной вместимости
    float floatValue; // Вещественное поле
    int intValue; // Целочисленное поле
} Object;

// Динамический массив структур
extern Object* objects;
extern int objectCount;

// Меню
void displayMenu();

// Функция для вывода таблицы на экран
void printTable();

#endif // BASE_H_INCLUDED
