//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//
//#define SIZE 1
//
//void LoadFile(FILE* fp);
//
//struct Elem {
//	int ID;
//	char Name[256];
//};
//
//typedef struct Elem Elem;
//
//void EnterName(Elem* el) {
//	char* name = (char*)malloc(256);
//	gets(name);
//	printf("\nВведите имя элемента: ");
//	gets(name);
//	strcpy(el->Name, name);
//}
//
//void InitElem(Elem* el) {
//	printf("Введите ID элемента: ");
//	scanf_s("%d", &el->ID);
//	EnterName(el);
//}
//
//void PrintElem(Elem* el) {
//	printf("\nЭлемент: %s ID: %d", el->Name, el->ID);
//}
//
//int main() {
//	system("chcp 1251 >> null");
//	Elem elem_1, elem_2;
//	char path[] = "./test.bin";
//
//	InitElem(&elem_1, 42);
//	PrintElem(&elem_1);
//	WriteToFile(&elem_1, path);
//
//	LoadFile(&elem_2, path);
//	//WriteToFile(&elem_1, path);
//	PrintElem(&elem_2);
//
//	return 0;
//}
//
//int WriteToFile(Elem* el, char* path) {
//	FILE* f_out;
//	size_t size = 0;
//	f_out = fopen(path, "wb");
//	if (!f_out) return NULL;
//
//	fwrite(el, sizeof(Elem), 1, f_out);
//
//	fclose(f_out);
//	
//	return 1;
//}
//
////int LoadFile(Elem* el, char* path) {
////	FILE* f_in;
////	f_in = fopen(path, "r");
////	if (f_in == 0) return NULL;
////
////	fread(&el->Name, sizeof(el->Name), 1, f_in);
////	fread(&el->ID, sizeof(el->ID), 1, f_in);
////}
//
//void LoadFile(Elem* el, char* path) {
//
//	FILE* f_in = fopen(path, "rb");
//
//	fread(el, sizeof(Elem), 1, f_in);
//
//	fclose(f_in);
//
//}