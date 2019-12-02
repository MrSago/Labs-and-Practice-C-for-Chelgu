#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "windows.h"
#include "time.h"


#define WELCOME "Приветствую тебя, Юзверь!\n\n"
#define MENU "Выбери опцию:\n\n1.Добавление студента\n2.Добавление рандомного студента\n3.Удаление студента\n4.Вывести список студентов\n5.Загрузка списка из файла\n6.Загрузка списка из бинарного файла\n7.Выгрузка списка в файл\n8.Выгрузка списка в бинарный файл\n9.Вывести успевающих студентов\n10.Удаление из списка неуспевающих студентов\n0.Выход из программы\n"
#define LIST "%llu. %s %s\nВозраст: %hhu\nОценки: Информатика - %hhu, Алгебра - %hhu, Мат.Анализ - %hhu, Физика - %hhu\n\n"
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