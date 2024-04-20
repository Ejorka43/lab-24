#ifndef SORTH_H_INCLUDED
#define SORTH_H_INCLUDED

// Функция для сравнения двух объектов по текстовому полю
int compareText(const void *a, const void *b);

// Функция для сравнения двух объектов по вещественному полю
int compareFloat(const void *a, const void *b);

// Функция для сравнения двух объектов по целочисленному полю
int compareInt(const void *a, const void *b);

// Функция для обобщенной сортировки по выбранному полю и направлению
void sortObjectsByField(int field, int direction, int (*compareFunction)(const void *, const void *));

#endif // SORTH_H_INCLUDED
