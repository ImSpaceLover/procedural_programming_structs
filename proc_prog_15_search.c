//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include "pupil.h"
//
//int main() {
//	system("chcp 1251 >> null");
//	char path_in[] = "./ListOfPupils.bin";
//	char path_out[] = "./ListSorted.bin";
//	char* last_name = (char*)malloc(64);
//
//	List list_1;
//	List list_2;
//	InitList(&list_1);
//	LoadFile(&list_1, path_in);
//	PrintList(&list_1);
//	
//	printf("\n\n¬ведите фамилию: ");
//	gets(last_name);
//	
//	list_2 = Search(&list_1, last_name);
//	//list_2 = CopyList(&list_1);
//	//printf("\n\nSorted List:");
//	//Sort(&list_2);
//	printf("\nЋюди с фамилией %s:", last_name);
//	PrintList(&list_2);
//	//WriteToFile(&list_2, path_out);
//
//	//printf("\n\nOriginal List:");
//	//PrintList(&list_1);
//
//	
//	return 0;
//}
