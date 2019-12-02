#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "windows.h"
#include "time.h"


#define WELCOME "����������� ����, ������!\n\n"
#define MENU "������ �����:\n\n1.���������� ��������\n2.���������� ���������� ��������\n3.�������� ��������\n4.������� ������ ���������\n5.�������� ������ �� �����\n6.�������� ������ �� ��������� �����\n7.�������� ������ � ����\n8.�������� ������ � �������� ����\n9.������� ���������� ���������\n10.�������� �� ������ ������������ ���������\n0.����� �� ���������\n"
#define LIST "%llu. %s %s\n�������: %hhu\n������: ����������� - %hhu, ������� - %hhu, ���.������ - %hhu, ������ - %hhu\n\n"
#define MARKS (2 + (uint8_t)rand() % 4)
#define NICE_MARKS ((Group->info[i].Object.Informatika + Group->info[i].Object.Algebra + Group->info[i].Object.Matanaliz + Group->info[i].Object.Fizika) / 4)

#define SUCCESS 0
#define EFOPEN -1


typedef struct __marks {
	uint8_t Informatika;
	uint8_t Algebra;
	uint8_t Matanaliz;
	uint8_t Fizika;
} Marks;

typedef struct __info {
	char *LastName;
	char *FirstName;
	uint8_t Age;
	Marks Object;
} Info;

typedef struct __student {
	Info *info;
	size_t count;
} Student;

typedef Student * Students;


/*Other Functions*/
char *ScanString(void);
errno_t FileCheck(FILE **file, const char filename[], const char mode[]);

/*Menu Functions*/
int MenuSelection(void);
void AddStudent(Students Group);
void RandomStudent(Students Group);
void DelStudent(Students Group);
void PrintStudents(Students Group);
void ReadFromFileStudents(Students Group);
void ReadFromBinFileStudents(Students Group);
void WriteInFileStudents(Students Group);
void WriteInBinFileStudents(Students Group);
void NiceStudents(Students Group);
void DelNotNiceStudents(Students Group);
#endif //HEADER_H