#ifndef _KP_6_
#include <stdio.h>
#include <stdbool.h>
#define _KP_6_


#define MAX_SIZE_OF_NAME 128


typedef struct Student {
    char name[MAX_SIZE_OF_NAME];
    char count_processor[MAX_SIZE_OF_NAME];
    char name_processor[MAX_SIZE_OF_NAME];
    char ram[MAX_SIZE_OF_NAME];
    char type_of_video_controller[MAX_SIZE_OF_NAME];
    char video_memory_capacity[MAX_SIZE_OF_NAME];
    char type_of_hard_drive[MAX_SIZE_OF_NAME];
    char count_of_hard_drives[MAX_SIZE_OF_NAME];
    char capacity_of_hard_drives[MAX_SIZE_OF_NAME];
    char count_of_external_devices[MAX_SIZE_OF_NAME];
    char operating_system[MAX_SIZE_OF_NAME];

    int count_incomplete_computers;
} Student;


Student* createStudent();


void copy_string(char* string, char* new_string);


bool isEmptyString(char* string);


void clear_string(char* string);


void print_string(char* string);


void clear_student(Student *student);


int read_txt(FILE *in, Student *student);


void print_to_file(FILE *out, char* string, char symbol);


#endif