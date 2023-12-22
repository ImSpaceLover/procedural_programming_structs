//эта строка позвол€ет использовать небезопасные функции gets, scanf и т.д. (зависит от среды разработки)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pupil.h"

int main() {
	//эта строка устанавливает русский €зык дл€ ввода и вывода в консоли (зависит от среда разработки)
	system("chcp 1251 >> null");

	//объ€вл€ем путь файла с записанным списком школьников и путь файла куда запишем отсортированный список
	char path_in[] = "./ListOfPupils.bin";
	char path_out[] = "./ListSorted.bin";

	//создаЄм два двусв€зных списка
	List list_1;
	List list_2;

	//инициализируем первый список, устанавлива€ значени€ указателей первого и последнего элемента на NULL
	InitList(&list_1);
	//загружаем список из файла
	LoadFile(&list_1, path_in);

	PrintList(&list_1);
	
	//копируем список в новый
	list_2 = CopyList(&list_1);
	//сортируем новый список на месте 
	Sort(&list_2);
	
	printf("\nќтсортированный список:\n");
	PrintList(&list_2);

	WriteToFile(&list_2, path_out);
	
	return 0;
}
