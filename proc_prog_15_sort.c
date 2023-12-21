#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pupil.h"

int main() {
	system("chcp 1251 >> null");
	char path_in[] = "./ListOfPupils.bin";
	char path_out[] = "./ListSorted.bin";

	List list_1;
	List list_2;
	InitList(&list_1);
	LoadFile(&list_1, path_in);
	PrintList(&list_1);


	list_2 = CopyList(&list_1);
	printf("\n\nSorted List:");
	Sort(&list_2);
	PrintList(&list_2);
	WriteToFile(&list_2, path_out);

	//orintf("\n\nOriginal List:");
	


	return 0;
}
