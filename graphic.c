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

    const int chartHeight = 400; // ������ ���������
    const int barWidth = 50; // ������ �������
    const int startX = 100; // ��������� ���������� X
    const int startY = 450; // ��������� ���������� Y
    const int legendX = 100 + (objectCount * 2 * barWidth); // ���������� X ��� �������
    const int legendY = 100; // ���������� Y ��� �������

    // ������� �������� ������� ��� ���������� ���������
    int colors[objectCount];
    for (int i = 0; i < objectCount; i++) {
        colors[i] = i + 1;
    }

    if (field==1){
        // ������� ������������ �������� ������������� ����
        float maxFieldValue = objects[0].floatValue;
        for (int i = 1; i < objectCount; i++) {
            if (objects[i].floatValue > maxFieldValue) {
                maxFieldValue = objects[i].floatValue;
            }
        }
        // ������ ������� ���������
        for (int i = 0; i < objectCount; i++) {
            int barHeight = (objects[i].floatValue / maxFieldValue) * chartHeight;
            setfillstyle(SOLID_FILL, colors[i]); // ���� �������
            bar(startX + i * 2 * barWidth, startY, startX + (i * 2 + 1) * barWidth, startY - barHeight);

            // ������� �������
            setfillstyle(SOLID_FILL, colors[i]);
            bar(legendX, legendY + i * 30, legendX + 20, legendY + i * 30 + 20);
            settextstyle(BOLD_FONT, HORIZ_DIR, 6);
            setcolor(colors[i]);
            outtextxy(legendX + 30, legendY + i * 30, objects[i].text);
        }
    }
    if (field==2){
        // ������� ������������ �������� ���������� ����
        float maxFieldValue = objects[0].intValue;
        for (int i = 1; i < objectCount; i++) {
            if (objects[i].intValue > maxFieldValue) {
                maxFieldValue = objects[i].intValue;
            }
        }
        // ������ ������� ���������
        for (int i = 0; i < objectCount; i++) {
            int barHeight = (objects[i].intValue / maxFieldValue) * chartHeight;
            setfillstyle(SOLID_FILL, colors[i]); // ���� �������
            bar(startX + i * 2 * barWidth, startY, startX + (i * 2 + 1) * barWidth, startY - barHeight);

            // ������� �������
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

// ������� ��� ������ �������� ���������
void drawPieChart(int field) {
    objects = (Object*)realloc(objects, (objectCount) * sizeof(Object));
    int gd = CUSTOM;
    int gm = CUSTOM_MODE(900,600);
    initgraph(&gd, &gm,"C:\\TC\\BGI");

    // ������� �������� ������� ��� �������� ���������
    int colors[objectCount];
    for (int i = 0; i < objectCount; i++) {
        colors[i] = i+1;
    }

    // ������ �������� ���������
    float startAngle = 0.0;
    if (field==1){
        // ������� ����� �������� ������������� ����
        float totalValue = 0.0;
        for (int i = 0; i < objectCount; i++) {
            totalValue += objects[i].floatValue;
        }
        for (int i = 0; i < objectCount; i++) {
            float sweepAngle = (objects[i].floatValue / totalValue) * 360.0;
            setfillstyle(SOLID_FILL, colors[i]); //���� �������
            setcolor(colors[i]);
            pieslice(300, 300, startAngle, startAngle + sweepAngle, 200);
            startAngle += sweepAngle;

            // ������� �������
            setfillstyle(SOLID_FILL, colors[i]);
            bar(560, 100 + i * 30, 580, 120 + i * 30);
            settextstyle(BOLD_FONT, HORIZ_DIR, 6);
            setcolor(colors[i]);
            outtextxy(600, 100 + i * 30, objects[i].text);
        }
    }
    if (field==2){
        // ������� ����� �������� �������������� ����
        float totalValue = 0.0;
        for (int i = 0; i < objectCount; i++) {
            totalValue += objects[i].intValue;
        }
        for (int i = 0; i < objectCount; i++) {
            float sweepAngle = (objects[i].intValue / totalValue) * 360.0;
            setfillstyle(SOLID_FILL, colors[i]-1); // ���� �������
            setcolor(colors[i]);
            pieslice(300, 300, startAngle, startAngle + sweepAngle, 200);
            startAngle += sweepAngle;

            // ������� �������
            setfillstyle(SOLID_FILL, colors[i]);
            bar(560, 100 + i * 30, 580, 120 + i * 30);
            settextstyle(BOLD_FONT, HORIZ_DIR, 6);
            setcolor(colors[i]);
            outtextxy(600, 100 + i * 30, objects[i].text);
        }
    }
    // ���������, ����� ���� ���������
    if (startAngle < 360.0) {
        float remainingAngle = 360.0 - startAngle;
        setfillstyle(SOLID_FILL, colors[0]); // ���������� ������ ���� ��� ���������� ���������� �����
        pieslice(300, 300, startAngle, startAngle + remainingAngle, 200);
    }
    getch();
    closegraph();
}
