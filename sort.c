#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
// Функция для сравнения двух объектов по текстовому полю
int compareText(const void *a, const void *b) {
    Object *obj1 = (Object *)a;
    Object *obj2 = (Object *)b;
    return strcmp(obj1->text, obj2->text);
}

// Функция для сравнения двух объектов по вещественному полю
int compareFloat(const void *a, const void *b) {
    Object *obj1 = (Object *)a;
    Object *obj2 = (Object *)b;
    return (obj1->floatValue > obj2->floatValue) - (obj1->floatValue < obj2->floatValue);
}

// Функция для сравнения двух объектов по целочисленному полю
int compareInt(const void *a, const void *b) {
    Object *obj1 = (Object *)a;
    Object *obj2 = (Object *)b;
    return obj1->intValue - obj2->intValue;
}

// Функция для обобщенной сортировки по выбранному полю и направлению
void sortObjectsByField(int field, int direction, int (*compareFunction)(const void *, const void *)) {
    qsort(objects, objectCount, sizeof(Object), compareFunction);
    if (direction == 2) {
        // Если направление сортировки - по убыванию, переворачиваем массив
        for (int i = 0; i < objectCount / 2; i++) {
            Object temp = objects[i];
            objects[i] = objects[objectCount - i - 1];
            objects[objectCount - i - 1] = temp;
        }
    }
}
