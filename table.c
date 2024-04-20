#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

// Инициализируем
Object* objects = NULL;
int objectCount = 0;

void displayMenu() {
    printf("\n1. Показать базу данных\n");
    printf("2. Добавить элемент\n");
    printf("3. Удалить элемент по номеру\n");
    printf("4. Сохранить в файл\n");
    printf("5. Чтение из файла\n");
    printf("6. Сортировка по полю\n");
    printf("7. Отображение диаграмм\n");
    printf("8. Выход\n");
}
// Функция для вывода таблицы на экран
void printTable() {
    // Вывод таблицы объектов
    for (int i = 0; i < objectCount; i++) {
        printf("Номер элемента %d: Текстовое: %s, Вещественное: %f, Целочисленное: %d\n", i, objects[i].text, objects[i].floatValue, objects[i].intValue);
    }
}
