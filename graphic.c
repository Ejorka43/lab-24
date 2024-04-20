#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include "base.h"
void drawBarChart(int field) {
    objects = (Object*)realloc(objects, (objectCount) * sizeof(Object));
    int gd = CUSTOM;
    int gm = CUSTOM_MODE(900,600);
    initgraph(&gd, &gm,"C:\\TC\\BGI");

    const int chartHeight = 400; // Высота диаграммы
    const int barWidth = 50; // Ширина столбца
    const int startX = 100; // Начальная координата X
    const int startY = 450; // Начальная координата Y
    const int legendX = 100 + (objectCount * 2 * barWidth); // Координата X для легенды
    const int legendY = 100; // Координата Y для легенды

    // Создаем цветовую палитру для столбчатой диаграммы
    int colors[objectCount];
    for (int i = 0; i < objectCount; i++) {
        colors[i] = i + 1;
    }

    if (field==1){
        // Находим максимальное значение вещественного поля
        float maxFieldValue = objects[0].floatValue;
        for (int i = 1; i < objectCount; i++) {
            if (objects[i].floatValue > maxFieldValue) {
                maxFieldValue = objects[i].floatValue;
            }
        }
        // Рисуем столбцы диаграммы
        for (int i = 0; i < objectCount; i++) {
            int barHeight = (objects[i].floatValue / maxFieldValue) * chartHeight;
            setfillstyle(SOLID_FILL, colors[i]); // Цвет столбца
            bar(startX + i * 2 * barWidth, startY, startX + (i * 2 + 1) * barWidth, startY - barHeight);

            // Выводим легенду
            setfillstyle(SOLID_FILL, colors[i]);
            bar(legendX, legendY + i * 30, legendX + 20, legendY + i * 30 + 20);
            settextstyle(BOLD_FONT, HORIZ_DIR, 6);
            setcolor(colors[i]);
            outtextxy(legendX + 30, legendY + i * 30, objects[i].text);
        }
    }
    if (field==2){
        // Находим максимальное значение выбранного поля
        float maxFieldValue = objects[0].intValue;
        for (int i = 1; i < objectCount; i++) {
            if (objects[i].intValue > maxFieldValue) {
                maxFieldValue = objects[i].intValue;
            }
        }
        // Рисуем столбцы диаграммы
        for (int i = 0; i < objectCount; i++) {
            int barHeight = (objects[i].intValue / maxFieldValue) * chartHeight;
            setfillstyle(SOLID_FILL, colors[i]); // Цвет столбца
            bar(startX + i * 2 * barWidth, startY, startX + (i * 2 + 1) * barWidth, startY - barHeight);

            // Выводим легенду
            setfillstyle(SOLID_FILL, colors[i]);
            bar(legendX, legendY + i * 30, legendX + 20, legendY + i * 30 + 20);
            settextstyle(BOLD_FONT, HORIZ_DIR, 6);
            setcolor(colors[i]);
            outtextxy(legendX + 30, legendY + i * 30, objects[i].text);
        }
    }
    getch();
    closegraph();
}

// Функция для вывода круговой диаграммы
void drawPieChart(int field) {
    objects = (Object*)realloc(objects, (objectCount) * sizeof(Object));
    int gd = CUSTOM;
    int gm = CUSTOM_MODE(900,600);
    initgraph(&gd, &gm,"C:\\TC\\BGI");

    // Создаем цветовую палитру для круговой диаграммы
    int colors[objectCount];
    for (int i = 0; i < objectCount; i++) {
        colors[i] = i+1;
    }

    // Рисуем круговую диаграмму
    float startAngle = 0.0;
    if (field==1){
        // Находим сумму значений вещественного поля
        float totalValue = 0.0;
        for (int i = 0; i < objectCount; i++) {
            totalValue += objects[i].floatValue;
        }
        for (int i = 0; i < objectCount; i++) {
            float sweepAngle = (objects[i].floatValue / totalValue) * 360.0;
            setfillstyle(SOLID_FILL, colors[i]); //Цвет сектора
            setcolor(colors[i]);
            pieslice(300, 300, startAngle, startAngle + sweepAngle, 200);
            startAngle += sweepAngle;

            // Выводим легенду
            setfillstyle(SOLID_FILL, colors[i]);
            bar(560, 100 + i * 30, 580, 120 + i * 30);
            settextstyle(BOLD_FONT, HORIZ_DIR, 6);
            setcolor(colors[i]);
            outtextxy(600, 100 + i * 30, objects[i].text);
        }
    }
    if (field==2){
        // Находим сумму значений целочисленного поля
        float totalValue = 0.0;
        for (int i = 0; i < objectCount; i++) {
            totalValue += objects[i].intValue;
        }
        for (int i = 0; i < objectCount; i++) {
            float sweepAngle = (objects[i].intValue / totalValue) * 360.0;
            setfillstyle(SOLID_FILL, colors[i]-1); // Цвет сектора
            setcolor(colors[i]);
            pieslice(300, 300, startAngle, startAngle + sweepAngle, 200);
            startAngle += sweepAngle;

            // Выводим легенду
            setfillstyle(SOLID_FILL, colors[i]);
            bar(560, 100 + i * 30, 580, 120 + i * 30);
            settextstyle(BOLD_FONT, HORIZ_DIR, 6);
            setcolor(colors[i]);
            outtextxy(600, 100 + i * 30, objects[i].text);
        }
    }
    // Проверяем, чтобы круг замкнулся
    if (startAngle < 360.0) {
        float remainingAngle = 360.0 - startAngle;
        setfillstyle(SOLID_FILL, colors[0]); // Используем первый цвет для заполнения оставшейся части
        pieslice(300, 300, startAngle, startAngle + remainingAngle, 200);
    }
    getch();
    closegraph();
}
