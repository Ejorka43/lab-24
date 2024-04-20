#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
// Сохранение в файл
void saveToFile(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Ошибка при открытии файла для записи.\n");
        return;
    }
    for (int i = 0; i < objectCount; i++) {
        fprintf(fp, "%s %f %d\n", objects[i].text, objects[i].floatValue, objects[i].intValue);
    }
    fclose(fp);
}

// Чтение из файла
void readFromFile(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Ошибка при открытии файла для чтения.\n");
        return;
    }
    objects = (Object*)realloc(objects, (objectCount + 1) * sizeof(Object));
    while(fscanf(fp, "%s %f %d", objects[objectCount].text, &objects[objectCount].floatValue, &objects[objectCount].intValue) != EOF) {
        objectCount++;
        objects = (Object*)realloc(objects, (objectCount + 1) * sizeof(Object));
    }
    fclose(fp);
}
