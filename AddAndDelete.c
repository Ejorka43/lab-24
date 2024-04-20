#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
// Функция для добавления элемента
void addObject() {
    // Увеличение размера массива
    objects = (Object*)realloc(objects, (objectCount + 1) * sizeof(Object));
    // Ввод данных с клавиатуры
    printf("Введите текст: ");
    scanf("%s", objects[objectCount].text);
    printf("Введите вещественное число: ");
    scanf("%f", &objects[objectCount].floatValue);
    printf("Введите целое число: ");
    scanf("%d", &objects[objectCount].intValue);
    objectCount++;
    printf("%d\n", objectCount);
}
// Функция для удаления элемента по номеру
void deleteObject(int index) {
    if (index < 0 || index >= objectCount) {
        printf("Неверный номер\n");
        return;
    }
    // Сдвиг всех элементов после удаляемого
    for (int i = index; i < objectCount - 1; i++) {
        objects[i] = objects[i + 1];
    }
    // Уменьшение размера массива
    objects = (Object*)realloc(objects, (objectCount - 1) * sizeof(Object));
    objectCount--;
}
