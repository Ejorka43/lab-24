#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

// ��������� ��� �������� ������ �������
typedef struct {
    char text[50]; // ��������� ���� ������������� �����������
    float floatValue; // ������������ ����
    int intValue; // ������������� ����
} Object;

// ������������ ������ ��������
extern Object* objects;
extern int objectCount;

// ����
void displayMenu();

// ������� ��� ������ ������� �� �����
void printTable();

#endif // BASE_H_INCLUDED
