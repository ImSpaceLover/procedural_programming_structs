#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef enum { female, male } Gender;
typedef char* string;
typedef enum month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec } month;

char to_lower_char(char);
time_t parse_date(string time_str);

struct Pupil {
	char first_name[64];
	char* last_name[64];
	Gender gender;
	time_t date_of_birth;
	char adress[256];

	struct Pupil* prev;
	struct Pupil* next;
};
typedef struct Pupil Pupil;

void InitElement(Pupil* p);

void InitName(Pupil* p, string first_name, string last_name);

void InitGender(Pupil* p, Gender gender);

void InitDate(Pupil* p, time_t date);

void InitAdress(Pupil* p, string adress);

Pupil* CopyElement(Pupil* p);

void FillPupilInfo(Pupil* p);

void PrintPupilInfo(Pupil p);

void InitPupilInfo(Pupil* p, char* first_name, char* last_name, Gender gender, time_t date_of_birth, char* adress);

time_t date_to_unix(int day, month month, int year);

void print_date(time_t unix);

typedef struct {
	Pupil* First;
	Pupil* Last;
} List;

Pupil* GetElement(List* L, size_t index);

void InitList(List* L);

List CopyList(List* L);

void FillListWithPupils(List* L, size_t size);

bool PrintList(List* L);

void Append(List* L, Pupil* e);

void Prepend(List* L, Pupil* e);

void Insert(List* L, size_t index, Pupil* e);

int Size(List* L);

void Swap(size_t index_1, size_t index_2, List* l);

void Delete(Pupil* e);

void Free(Pupil* e);

void FreeList(List* L);

void Sort(List* L);

List Search(List* L, string last_name);

bool LoadFile(List* l, char* path);

bool WriteToFile(List* l, char* path);