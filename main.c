#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "base.h"
#include "AddDel.h"
#include "graph.h"
#include "SaveRead.h"
#include "Sorth.h"
#include <graphics.h>
int main() {
    setlocale(LC_CTYPE, "Russian");
    int choice, index, field, direction, chartType, file;
    char filename[50]; // Максимальная длина имени файла
    while (1) {
        displayMenu();
        printf("\nВведите свой выбор: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printTable(); // Вывод таблицы на экран
                break;
            case 2:
                addObject(); // Добавление элемента
                break;
            case 3: // Удаление элемента
                printf("Введите индекс для удаления: ");
                scanf("%d", &index);
                deleteObject(index);
                break;
            case 4: // Сохранение в файл
                printf("Выберите: 1-сохранить в заданный файл, 2-ввести имя файла\n");
                scanf("%d", &file);
                switch (file) {
                    case 1:
                        saveToFile("objects.txt");
                        break;
                    case 2:
                        printf("Введите имя файла: ");
                        scanf("%s", filename);
                        saveToFile(filename);
                        break;
                    default:
                        printf("Неверный выбор\n");
                }
                break;
            case 5: // Чтение из файла
                printf("Выберите: 1-читать из заданного файла, 2-ввести имя файла\n");
                scanf("%d", &file);
                switch (file){
                    case 1:
                        readFromFile("objects.txt");
                        break;
                    case 2:
                        printf("Введите имя файла: ");
                        scanf("%s", filename);
                        readFromFile(filename);
                        break;
                    default:
                        printf("Неверный выбор\n");
                }
                break;
            case 6: // Сортировка
                printf("Выберите поле для сортировки (1 - текст, 2 - вещественное, 3 - целое): ");
                scanf("%d", &field);
                printf("Выберите направление сортировки (1 - по возрастанию, 2 - по убыванию): ");
                scanf("%d", &direction);
                if (direction>2){
                    printf("Неверный выбор\n");
                    break;
                }
                switch (field) {
                    case 1:
                        sortObjectsByField(1, direction, compareText);
                        break;
                    case 2:
                        sortObjectsByField(2, direction, compareFloat);
                        break;
                    case 3:
                        sortObjectsByField(3, direction, compareInt);
                        break;
                    default:
                        printf("Неверный выбор поля для сортировки\n");
                }
                break;
            case 7: // Вывод диаграмм
                printf("Выберите числовое поле для построения диаграммы (1 - вещественное, 2 - целое): ");
                scanf("%d", &field);
                if (field>2){
                    printf("Неверный выбор\n");
                    break;
                }
                printf("Выберите тип диаграммы (1 - столбчатая, 2 - круговая): ");
                scanf("%d", &chartType);
                switch (chartType) {
                    case 1:
                        drawBarChart(field);
                        break;
                    case 2:
                        drawPieChart(field);
                        break;
                    default:
                        printf("Неверный выбор типа диаграммы\n");
                }
                break;
            case 8:
                exit(0);
            default:
                printf("Неверный выбор\n");
        }
    }
    return 0;
}
