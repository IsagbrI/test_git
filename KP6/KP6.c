#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "KP6.h"

Student* createStudent() {
    Student* student = (Student*)malloc(sizeof(Student));
    student->name;
    student->count_processor;
    student->name_processor;
    student->ram;
    student->type_of_video_controller;
    student->video_memory_capacity;
    student->type_of_hard_drive;
    student->count_of_hard_drives;
    student->capacity_of_hard_drives;
    student->count_of_external_devices;
    student->operating_system;

    student->count_incomplete_computers = 0;
}


void copy_string(char* string, char* new_string) {
    for (int i = 0; i < MAX_SIZE_OF_NAME; ++i) 
        new_string[i] = string[i];
}


bool isEmptyString(char* string) {
    for (int i = 0; i < MAX_SIZE_OF_NAME; ++i) 
        if (string[i] != ' ')
            return false;
    return true;
}


void clear_string(char* string) {
    for (int i = 0; i < MAX_SIZE_OF_NAME; ++i) 
        string[i] = ' ';
}


void print_string(char* string) {
    for (int i = 0; i < MAX_SIZE_OF_NAME; ++i)
        printf("%c", string[i]);
    printf("\n");
}


void clear_student(Student *student) {
	clear_string(student->name);
	clear_string(student->count_processor);
	clear_string(student->name_processor);
	clear_string(student->ram);
	clear_string(student->type_of_video_controller);
	clear_string(student->video_memory_capacity);
	clear_string(student->type_of_hard_drive);
	clear_string(student->count_of_hard_drives);
	clear_string(student->capacity_of_hard_drives);
	clear_string(student->count_of_external_devices);
	clear_string(student->operating_system);
}


int read_txt(FILE *in, Student *student) {

	int count_of_element = 0;
	char word[MAX_SIZE_OF_NAME];
	clear_string(word);
	int i = 0;
	char symbol = getc(in);

	student->count_incomplete_computers = 0;
	while (symbol != '\n') {
		if (feof(in))
			return 0;

		if (symbol == ',') {
			if (count_of_element == 0) {
				if (!isEmptyString(word)) 
					copy_string(word, student->name);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 1){
				if (!isEmptyString(word)) 
					copy_string(word, student->count_processor);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 2){
				if (!isEmptyString(word)) 
					copy_string(word, student->name_processor);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 3){
				if (isEmptyString(word)) 
					student->count_incomplete_computers++;
				copy_string(word, student->ram);
					
			} else if (count_of_element == 4){
				if (!isEmptyString(word)) 
					copy_string(word, student->type_of_video_controller);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 5){
				if (!isEmptyString(word)) 
					copy_string(word, student->video_memory_capacity);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 6){
				if (!isEmptyString(word)) 
					copy_string(word, student->type_of_hard_drive);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 7){
				if (!isEmptyString(word)) 
					copy_string(word, student->count_of_hard_drives);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 8){
				if (!isEmptyString(word)) 
					copy_string(word, student->capacity_of_hard_drives);
				else
					student->count_incomplete_computers++;
			} else if (count_of_element == 9){
				if (!isEmptyString(word)) 
					copy_string(word, student->count_of_external_devices);
				else
					student->count_incomplete_computers++;
			} 
			count_of_element++;
			clear_string(word);
			i = 0;
			
		} else {
			word[i] = symbol;
			i++;
		}

		symbol = getc(in);
	}
	if (!isEmptyString(word)) 
		copy_string(word, student->operating_system);
	else
		student->count_incomplete_computers++;
	// printf("+++++++++++\n");

}

void print_to_file(FILE *out, char* string, char symbol) {
	for (int i = 0; i < MAX_SIZE_OF_NAME; ++i) {
		if (string[i] == ' ' && string[i + 1] == ' ')
			break;
		fprintf(out, "%c", string[i]); 
	}
	fprintf(out, "%c", symbol);
}