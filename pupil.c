//Структура «Школьник».
//Минимальный набор полей : фамилия, имя, пол, класс, дата рождения, адрес.
//Список : двусвязный стек.
//Поиск по фамилии, фильтр по дате рождения.
//#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pupil.h"


char to_lower_char(char);
time_t parse_date(string time_str);

const char UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
const char LOWER[] = "abcdefghijklmnopqrstuvwxyzабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
const char gender_text[][15] = { "Женский", "Мужской" };

char to_upper_char(char c) {
	for (int i = 0; i < sizeof(UPPER) / sizeof(char); i++) {
		if (c == LOWER[i]) return UPPER[i];
	}
	return c;
}

char* to_upper(char* string, int len) {
	char* string_up = (char*)malloc(len * sizeof(char));
	for (int i = 0; i < len; i++) string_up[i] = to_upper_char(string[i]);
	return string_up;
}

bool is_equal(char* str1, char* str2) {
	for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
		if (to_upper_char(str1[i]) != to_upper_char(str2[i])) return 0;
	return 1;
}

void InitElement(Pupil* p) {
	p->prev = NULL;
	p->next = NULL;
}

void InitName(Pupil* p, string first_name, string last_name) {
	strcpy(p->first_name, first_name);
	strcpy(p->last_name, last_name);
}

void InitGender(Pupil* p, Gender gender) {
	p->gender = gender;
}

void InitDate(Pupil* p, time_t date) {
	p->date_of_birth = date;
}

void InitAdress(Pupil* p, string adress) {
	strcpy(p->adress, adress);
}

void FillPupilInfo(Pupil* p) {
	string first_name, last_name, adress;
	time_t date_of_birth;
	string date_raw;
	Gender gender;
	char gender_c;
	char str_gender[][4] = { "цы", "ка" };
	first_name = (char*)malloc(64 * sizeof(char));
	last_name = (char*)malloc(64 * sizeof(char));
	adress = (char*)malloc(256 * sizeof(char));
	date_raw = (char*)malloc(10 * sizeof(char));

	while (true) {
		printf("\nВведите пол ученика(цы) (Букву М/Ж): ");
		scanf("%c", &gender_c);

		gender_c = to_lower_char(gender_c);
		if (gender_c == 'м') {
			gender = male;
			break;
		}
		else if (gender_c == 'ж') {
			gender = female;
			break;
		}
		else printf("Ошибка! Пол введён неправильно");
		scanf("%c", &gender_c);
	}

	InitGender(p, gender);
	gets(first_name);
	printf("Введите имя учени%s: ", str_gender[gender]);
	gets(first_name);
	printf("Введите фамилию учени%s: ", str_gender[gender]);
	gets(last_name);
	InitName(p, first_name, last_name);

	printf("Введите дату рождения учени%s (в формате DD/MM/YYYY): ", str_gender[gender]);
	gets(date_raw);
	InitDate(p, parse_date(date_raw));

	printf("Введите адрес учени%s: ", str_gender[gender]);
	gets(adress);
	InitAdress(p, adress);
}

void PrintPupilInfo(Pupil p) {
	printf("\n%s %s\t\t", p.first_name, p.last_name);
	printf("\nПол: %s", gender_text[p.gender]);
	printf("\nДата рождения: ");
	print_date(p.date_of_birth);
	printf("\nМесто проживания: %s\n", p.adress);
}

void InitPupilInfo(Pupil* p, char* first_name, char* last_name, Gender gender, time_t date_of_birth, char* adress) {
	InitName(p, first_name, last_name);
	InitGender(p, gender);
	InitDate(p, date_of_birth);
	InitAdress(p, adress);
}

Pupil* CopyElement(Pupil* p) {
	Pupil* p_copy = (Pupil*)malloc(sizeof(Pupil));
	InitElement(p_copy);
	strcpy(p_copy->adress, p->adress);
	strcpy(p_copy->first_name, p->first_name);
	strcpy(p_copy->last_name, p->last_name);
	p_copy->date_of_birth = p->date_of_birth;
	p_copy->gender = p->gender;
	p_copy->next = NULL;
	p_copy->prev = NULL;
	return p_copy;
}

time_t date_to_unix(int day, month month, int year) {
	struct tm date;
	date.tm_year = year - 1900;  // Year minus 1900
	date.tm_mon = month - 1;             // Month (0-11, so 0 represents January)
	date.tm_mday = day;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;
	time_t unix = mktime(&date);
	return unix;
}

void print_date(time_t unix) {
	struct tm* tm_info;
	tm_info = gmtime(&unix);
	printf("%02d/", tm_info->tm_mday);
	printf("%02d/", tm_info->tm_mon + 1);
	printf("%04d", tm_info->tm_year + 1900);
}

char to_lower_char(char c) {
	for (int i = 0; i < sizeof(UPPER); i++) {
		if (c == UPPER[i]) return LOWER[i];
	}
	return c;
}

time_t parse_date(string time_str) {
	char day_str[2];
	char month_str[2];
	char year_str[4];
	for (int i = 0; i < 10; i++) {
		if (i < 2) day_str[i] = time_str[i];
		else if (i > 2 && i < 5) month_str[i-3] = time_str[i];
		else if (i > 5) year_str[i-6] = time_str[i];
	}
	return date_to_unix(atoi(day_str), atoi(month_str), atoi(year_str));
}

void InitList(List* L) {
	L->First = NULL;
	L->Last = NULL;
}

void FillListWithPupils(List* L, size_t size) {
	Pupil* p;
	for (size_t i = 0; (long)i < (long)size; i++) {
		p = (Pupil*)malloc(sizeof(Pupil));
		InitElement(p);
		FillPupilInfo(p);
		Append(L, p);
	}
}

bool PrintList(List* L) {
	Pupil* current = L->First;
	if (current == NULL) {
		printf("\nError: the list is empty");
		return false;
	}
	while (current != NULL) {
		//printf("\n");
		PrintPupilInfo(*current);
		current = current->next;
	}
	return true;
}

void Append(List* L, Pupil* e) {
	if (L->First == NULL) {
		//пустой список
		L->First = e;
		L->Last = e;
		return;
	}
	Pupil* last = L->Last;
	last->next = e;
	e->prev = last;
	L->Last = e;
}

void Prepend(List* L, Pupil* e) {
	if (L->First == NULL) {
		//пустой список
		L->First = e;
		return;
	}
	Pupil* first = L->First;
	first->prev = e;
	e->next = first;
	L->First = e;
}

void Insert(List* L, size_t index, Pupil* e) {
	if (index > Size(L)) return;
	Pupil* insert = GetElement(L, index);
	if (L->First == NULL) {
		L->First = e;
		return;
	}
	e->next = insert->next;
	if (e->next) e->next->prev = e;
	e->prev = insert;
	insert->next = e;
}

//определить следующий элемент за e
Pupil* NextElem(Pupil* e) {
	return e->next;
}
//определить предыдущий элемент перед e
Pupil* PrevElem(Pupil* e) {
	return e->prev;
}

int Size(List* L) {
	int size = 0;
	Pupil* current = L->First;
	if (current == NULL) {
		return 0;
	}
	while (current != NULL) {
		current = current->next;
		size++;
	}
	return size;
}

Pupil* GetElement(List* L, size_t index) {
	Pupil* current = L->First;
	for (size_t i = 0; (long)i < (long)index; i = i + 1) {
		current = current->next;
		if (current == NULL) {
			printf("\nIndex out of bounds");
			return NULL;
		}
	}
	return current;
}

void Sort(List* l) {
	size_t len = Size(l);
	size_t i;
	Pupil* key;
	for (size_t j = 1; (long)j < (long)len; j++) {
		key = GetElement(l, j);
		i = j - 1;
		while (i >= 0 && ((GetElement(l, i)->date_of_birth) > key->date_of_birth)) {
			Swap(i+1, i, l);
			i -= 1;
		}
	}
}

void Swap(size_t index_1, size_t index_2, List* l) {
	Pupil* e1 = GetElement(l, index_1);
	Pupil* e2 = GetElement(l, index_2);
	Pupil* next_temp = NULL;
	Pupil* prev_temp = NULL;

	if (e1->next == e2) {
		e2->prev = e1->prev;
		if (e1->prev) e1->prev->next = e2;
		e1->next = e2->next;
		if (e2->next) e2->next->prev = e1;
		e1->prev = e2;
		e2->next = e1;
	}
	else if (e2->next == e1) {
		e1->prev = e2->prev;
		if (e2->prev) e2->prev->next = e1;
		e2->next = e1->next;
		if (e1->next) e1->next->prev = e2;
		e2->prev = e1;
		e1->next = e2;
	}

	else {
		if (e1->next) next_temp = e1->next;
		if (e1->prev) next_temp = e1->prev;
		if (prev_temp) prev_temp->next = e2;
		if (prev_temp) next_temp->prev = e2;
		if (e2->prev) e2->prev->next = e1;
		if (e2->next) e2->next->prev = e1;
		e1->next = e2->next;
		e1->prev = e2->prev;
		e2->next = next_temp;
		e2->prev = prev_temp;
	}
	if (e1->prev == NULL) l->First = e1;
	else if (e2->prev == NULL) l->First = e2;
	
	if (e1->next == NULL) l->Last = e1;
	else if (e2->next == NULL) l->Last = e2;
}

void Delete(Pupil* e) {
	Pupil* next = NULL;
	Pupil* prev = NULL;

	if (e->next) next = e->next;
	if (e->prev) prev = e->prev;

	if (prev) prev->next = next;
	if (next) next->prev = prev;

	e->prev = NULL;
	e->next = NULL;
}

void Free(Pupil* e) {
	Delete(e);
	free(e);
}

void FreeList(List* L) {
	Pupil* last = L->Last;
	Pupil* current = last->prev;
	while (current != NULL) {
		Free(last);
		last = current;
		current = current->prev;
	}
	Free(last);
	L->First = NULL;
	L->Last = NULL;
}

List CopyList(List* L) {
	Pupil* current = L->First;
	List* L_copy = (List*)malloc(sizeof(List));
	InitList(L_copy);

	while (current != NULL) {
		Append(L_copy, CopyElement(current));
		current = current->next;
	}
	return *L_copy;
}
List Search(List* L, string last_name) {
	Pupil* current = L->First;
	List* L_found = (List*)malloc(sizeof(List));
	InitList(L_found);
	if (current == NULL) return;
	while (current != NULL) {
		if (is_equal(current->last_name, last_name)) {
			Append(L_found, CopyElement(current));
		}
		current = current->next;
	}
	return *(L_found);
}

bool WriteToFile(List* l, char* path) {
	Pupil* current = l->First;
	if (current == NULL) {
		printf("\nError: The list is empty.");
		return false;
	}
	FILE* f_out = NULL;
	size_t size = Size(l);
	f_out = fopen(path, "wb");
	if (f_out == NULL) { 
		printf("\nError: Couldn't open the file at %s", path);
		fclose(f_out);
		return false; 
	}

	if (fwrite(&size, sizeof(size_t), 1, f_out) != 1) {
		printf("\nError: Coulnd't write the list size to file");
		fclose(f_out);
		return false;
	}

	while (current != NULL) {
		if (fwrite(current, sizeof(Pupil), 1, f_out) != 1) {
			printf("\nError: Coulnd't write an element to file");
			fclose(f_out);
			return false;
		}
		current = current->next;
	}

	printf("\nWritten to file successfully");
	fclose(f_out);
	return true;
}

bool LoadFile(List* l, char* path) {
	Pupil* current = l->First;
	if (current != NULL) {
		printf("\nError: Can't load to a non-empty list.");
		return false;
	}
	else {
		current = (Pupil*)malloc(sizeof(Pupil));
	}

	size_t size = 0;
	FILE* f_in = NULL;
	f_in = fopen(path, "rb");
	if (f_in == NULL) {
		printf("\nError: Couldn't open the file at %s", path);
		fclose(f_in);
		return false;
	}

	if (fread(&size, sizeof(size_t), 1, f_in) != 1) {
		printf("\nError: Coulnd't read the list size from file");
		fclose(f_in);
		return false;
	}

	for (size_t i = 0; (long)i < (long)size; i = i+ 1) {
		if (fread(current, sizeof(Pupil), 1, f_in) != 1) {
			printf("\nError: Coulnd't load an element to list");
			fclose(f_in);
			return false;
		}
		Append(l, current);
		current = (Pupil*)malloc(sizeof(Pupil));
	}
	printf("\nLoaded from file successfully");
	fclose(f_in);
	return true;

}