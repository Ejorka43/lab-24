#ifndef SORTH_H_INCLUDED
#define SORTH_H_INCLUDED

// ������� ��� ��������� ���� �������� �� ���������� ����
int compareText(const void *a, const void *b);

// ������� ��� ��������� ���� �������� �� ������������� ����
int compareFloat(const void *a, const void *b);

// ������� ��� ��������� ���� �������� �� �������������� ����
int compareInt(const void *a, const void *b);

// ������� ��� ���������� ���������� �� ���������� ���� � �����������
void sortObjectsByField(int field, int direction, int (*compareFunction)(const void *, const void *));

#endif // SORTH_H_INCLUDED
