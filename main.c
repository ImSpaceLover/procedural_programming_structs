//��� ������ ��������� ������������ ������������ ������� gets, scanf � �.�. (������� �� ����� ����������)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pupil.h"

int main() {
	//��� ������ ������������� ������� ���� ��� ����� � ������ � ������� (������� �� ����� ����������)
	system("chcp 1251 >> null");

	//��������� ���� ����� � ���������� ������� ���������� � ���� ����� ���� ������� ��������������� ������
	char path_in[] = "./ListOfPupils.bin";
	char path_out[] = "./ListModified.bin";

	//������ ���������� ������ � ������� ���� ��������
	List list;
	Pupil pupil;

	//�������������� ������ � ������� ��������
	InitList(&list);
	InitElement(&pupil);
	//��������� ������ �� �����
	LoadFile(&list, path_in);
	//������ ������ ��������� � ����������
	FillPupilInfo(&pupil);

	printf("������ ������: \n");

	PrintList(&list);

	//��������� ������� � ������ �� �������
	Insert(&list, 5, &pupil);
	// ������ ������� 2 �������� �� �������
	Swap(4, 6, &list);
	// ������� ������� �� �������
	DeleteElem(&list, 3);

	printf("\n������ ������: \n");

	PrintList(&list);
	

	FreeList(&list);
	return 0;
}
