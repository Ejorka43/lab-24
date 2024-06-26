#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
// ���������� � ����
void saveToFile(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("������ ��� �������� ����� ��� ������.\n");
        return;
    }
    for (int i = 0; i < objectCount; i++) {
        fprintf(fp, "%s %f %d\n", objects[i].text, objects[i].floatValue, objects[i].intValue);
    }
    fclose(fp);
}

// ������ �� �����
void readFromFile(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("������ ��� �������� ����� ��� ������.\n");
        return;
    }
    objects = (Object*)realloc(objects, (objectCount + 1) * sizeof(Object));
    while(fscanf(fp, "%s %f %d", objects[objectCount].text, &objects[objectCount].floatValue, &objects[objectCount].intValue) != EOF) {
        objectCount++;
        objects = (Object*)realloc(objects, (objectCount + 1) * sizeof(Object));
    }
    fclose(fp);
}
