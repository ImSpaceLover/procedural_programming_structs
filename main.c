//эта строка позволяет использовать небезопасные функции gets, scanf и т.д. (зависит от среды разработки)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pupil.h"

int main() {
	//эта строка устанавливает русский язык для ввода и вывода в консоли (зависит от среды разработки)
	system("chcp 1251 >> null");

	//объявляем путь файла с записанным списком школьников и путь файла куда запишем отсортированный список
	char path_in[] = "./ListOfPupils.bin";
	char path_out[] = "./ListModified.bin";

	//создаём двусвязный список и элемент типа Школьник
	List list;
	Pupil pupil;

	//инициализируем список и элемент Школьник
	InitList(&list);
	InitElement(&pupil);
	//загружаем список из файла
	LoadFile(&list, path_in);
	//Вводим данные Школьника с клавиатуры
	FillPupilInfo(&pupil);

	printf("Первый список: \n");

	PrintList(&list);

	//Вставляем элемент в список по индексу
	Insert(&list, 5, &pupil);
	// Меняем местами 2 элемента по индексу
	Swap(4, 6, &list);
	// Удаляем элемент по индексу
	DeleteElem(&list, 3);

	printf("\nВторой список: \n");

	PrintList(&list);
	

	FreeList(&list);
	return 0;
}
