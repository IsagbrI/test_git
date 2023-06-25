#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


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

int main() {
	Student *student = createStudent();
	int choice = 0;
    bool work = true;
    while (work) {
        printf("Select an option:\n");
        printf("1. Do you want to read from a binary file and write to a binary file?\n");
        printf("2. Do you want to read from a binary file and write to a text file?\n");
        printf("3. Do you want to read from a text file and write to a text file?\n");
        printf("4. Do you want to read from a text file and write to a binary file?\n");
        printf("5. Exit.\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                FILE *in_binary = fopen("data.bin", "rb");
            	if (in_binary == NULL) {;
            		FILE *in_binary = fopen("data.bin", "wb");
            		fclose(in_binary);
            	}
				FILE *out_binary = fopen("result.bin", "wb");

				student = createStudent();
				clear_student(student);
				while (fread(student->name, sizeof(student->name), 1, in_binary)) {
					if (student->count_incomplete_computers != 0) {
						fwrite(student->name, sizeof(student->name), 1, out_binary);
						fwrite(student->count_processor, sizeof(student->count_processor), 1, out_binary);
						fwrite(student->name_processor, sizeof(student->name_processor), 1, out_binary);
						fwrite(student->ram, sizeof(student->ram), 1, out_binary);
						fwrite(student->type_of_video_controller, sizeof(student->type_of_video_controller), 1, out_binary);
						fwrite(student->video_memory_capacity, sizeof(student->video_memory_capacity), 1, out_binary);
						fwrite(student->type_of_hard_drive, sizeof(student->type_of_hard_drive), 1, out_binary);
						fwrite(student->count_of_hard_drives, sizeof(student->count_of_hard_drives), 1, out_binary);
						fwrite(student->capacity_of_hard_drives, sizeof(student->capacity_of_hard_drives), 1, out_binary);
						fwrite(student->count_of_external_devices, sizeof(student->count_of_external_devices), 1, out_binary);
						fwrite(student->operating_system, sizeof(student->operating_system), 1, out_binary);
					}
					clear_student(student);
				}

			    free(student);
			    fclose(in_binary);
			    fclose(out_binary);
                break;
            }
            case 2: {
			    FILE *in_binary = fopen("result.bin", "rb");
            	if (in_binary == NULL) {
            		FILE *in_binary = fopen("result.bin", "wb");
            		fclose(in_binary);
            	}
			    FILE *out = fopen("result.txt", "w");
                student = createStudent();
                clear_student(student);
			    while (fread(student->name, sizeof(student->name), 1, in_binary)) {
			    	print_to_file(out, student->name, ',');
			    	fread(student->count_processor, sizeof(student->count_processor), 1, in_binary);
					print_to_file(out, student->count_processor, ',');
					fread(student->name_processor, sizeof(student->name_processor), 1, in_binary);
					print_to_file(out, student->name_processor, ',');
					fread(student->ram, sizeof(student->ram), 1, in_binary);
					print_to_file(out, student->ram, ',');
					fread(student->type_of_video_controller, sizeof(student->type_of_video_controller), 1, in_binary);
					print_to_file(out, student->type_of_video_controller, ',');
					fread(student->video_memory_capacity, sizeof(student->video_memory_capacity), 1, in_binary);
					print_to_file(out, student->video_memory_capacity, ',');
					fread(student->type_of_hard_drive, sizeof(student->type_of_hard_drive), 1, in_binary);
					print_to_file(out, student->type_of_hard_drive, ',');
					fread(student->count_of_hard_drives, sizeof(student->count_of_hard_drives), 1, in_binary);
					print_to_file(out, student->count_of_hard_drives, ',');
					fread(student->capacity_of_hard_drives, sizeof(student->capacity_of_hard_drives), 1, in_binary);
					print_to_file(out, student->capacity_of_hard_drives, ',');
					fread(student->count_of_external_devices, sizeof(student->count_of_external_devices), 1, in_binary);
					print_to_file(out, student->count_of_external_devices, ',');
					fread(student->operating_system, sizeof(student->operating_system), 1, in_binary);
					print_to_file(out, student->operating_system, '\n');
					clear_student(student);
			    }

			    free(student);
			    fclose(in_binary);
			    fclose(out);
                break;
            }
            case 3: {
                FILE *in = fopen("data.txt", "r");
				FILE *out = fopen("result.txt", "w");
				student = createStudent();
				clear_student(student);
				while (read_txt(in, student)) {
					if (student->count_incomplete_computers != 0) {
						print_to_file(out, student->name, ',');
						print_to_file(out, student->count_processor, ',');
						print_to_file(out, student->name_processor, ',');
						print_to_file(out, student->ram, ',');
						print_to_file(out, student->type_of_video_controller, ',');
						print_to_file(out, student->video_memory_capacity, ',');
						print_to_file(out, student->type_of_hard_drive, ',');
						print_to_file(out, student->count_of_hard_drives, ',');
						print_to_file(out, student->capacity_of_hard_drives, ',');
						print_to_file(out, student->count_of_external_devices, ',');
						print_to_file(out, student->operating_system, '\n');
	    			}
	    			clear_student(student);
			    }
				free(student);
				fclose(in);
				fclose(out);
                break;
            }
            case 4: {
                FILE *in = fopen("data.txt", "r");
				FILE *out_binary = fopen("result.bin", "wb");
				student = createStudent();
				clear_student(student);
				while (read_txt(in, student)) {
					if (student->count_incomplete_computers != 0) {
						fwrite(student->name, sizeof(student->name), 1, out_binary);
						fwrite(student->count_processor, sizeof(student->count_processor), 1, out_binary);
						fwrite(student->name_processor, sizeof(student->name_processor), 1, out_binary);
						fwrite(student->ram, sizeof(student->ram), 1, out_binary);
						fwrite(student->type_of_video_controller, sizeof(student->type_of_video_controller), 1, out_binary);
						fwrite(student->video_memory_capacity, sizeof(student->video_memory_capacity), 1, out_binary);
						fwrite(student->type_of_hard_drive, sizeof(student->type_of_hard_drive), 1, out_binary);
						fwrite(student->count_of_hard_drives, sizeof(student->count_of_hard_drives), 1, out_binary);
						fwrite(student->capacity_of_hard_drives, sizeof(student->capacity_of_hard_drives), 1, out_binary);
						fwrite(student->count_of_external_devices, sizeof(student->count_of_external_devices), 1, out_binary);
						fwrite(student->operating_system, sizeof(student->operating_system), 1, out_binary);
					}
					clear_student(student);
				}

				free(student);
				fclose(in);
				fclose(out_binary);
                break;
            }
        	case 5: {
                printf("Exiting program...\n");
                work = false;
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } 
    
	// FILE *in = fopen("data.txt", "r");
	// FILE *out_binary = fopen("result.bin", "wb");
	// Student *student = createStudent();
	// while (read_txt(in, student)) {
	// 	if (student->count_incomplete_computers != 0) {
	// 		fwrite(student->name, sizeof(student->name), 1, out_binary);
	// 		fwrite(student->count_processor, sizeof(student->count_processor), 1, out_binary);
	// 		fwrite(student->name_processor, sizeof(student->name_processor), 1, out_binary);
	// 		fwrite(student->ram, sizeof(student->ram), 1, out_binary);
	// 		fwrite(student->type_of_video_controller, sizeof(student->type_of_video_controller), 1, out_binary);
	// 		fwrite(student->video_memory_capacity, sizeof(student->video_memory_capacity), 1, out_binary);
	// 		fwrite(student->type_of_hard_drive, sizeof(student->type_of_hard_drive), 1, out_binary);
	// 		fwrite(student->count_of_hard_drives, sizeof(student->count_of_hard_drives), 1, out_binary);
	// 		fwrite(student->capacity_of_hard_drives, sizeof(student->capacity_of_hard_drives), 1, out_binary);
	// 		fwrite(student->count_of_external_devices, sizeof(student->count_of_external_devices), 1, out_binary);
	// 		fwrite(student->operating_system, sizeof(student->operating_system), 1, out_binary);
	// 	}
	// }

	// free(student);
	// fclose(in);
	// fclose(out_binary);
	

	// student = createStudent();
    // FILE *in_binary = fopen("result.bin", "rb");
    // FILE *out = fopen("result.txt", "w");

    // printf("TEST\n");
    // char operating_system[MAX_SIZE_OF_NAME];
    // while (fread(student->name, sizeof(student->name), 1, in_binary)) {
	// 	fread(student->count_processor, sizeof(student->count_processor), 1, in_binary);
	// 	fread(student->name_processor, sizeof(student->name_processor), 1, in_binary);
	// 	print_string(student->name_processor);
    // 	for (int i = 0; i < MAX_SIZE_OF_NAME; ++i) 
    // 		fprintf(out, "%c", student->name_processor[i]); 
	// 	fread(&copy, sizeof(student->ram), 1, in_binary);
	// 	fread(&copy, sizeof(student->type_of_video_controller), 1, in_binary);
	// 	fread(&copy, sizeof(student->video_memory_capacity), 1, in_binary);
	// 	fread(&copy, sizeof(student->type_of_hard_drive), 1, in_binary);
	// 	fread(&copy, sizeof(student->count_of_hard_drives), 1, in_binary);
	// 	fread(&copy, sizeof(student->capacity_of_hard_drives), 1, in_binary);
	// 	fread(&copy, sizeof(student->count_of_external_devices), 1, in_binary);
	// 	fread(&copy, sizeof(student->operating_system), 1, in_binary);
    // }

    // free(student);
    // fclose(in_binary);
    // fclose(out);


	return 0;
}









































// int main() {
// 	int y = 2;
// 	float x = 34.5;
// 	FILE *file_write = fopen("result.bin", "wb");
// 	fwrite(&y, sizeof(y), 1, file_write);
// 	fwrite(&x, sizeof(x), 1, file_write);

// 	fclose(file_write);

// 	int a;
// 	float b;
// 	FILE *file_read = fopen("result.bin", "rb");
// 	fread(&a, sizeof(a), 1, file_read);
// 	fread(&b, sizeof(b), 1, file_read);
// 	printf("%d %f\n", a, b);
// 	fclose(file_read);

// 	return 0;
// }



// int main() {
// 	int y[5] = {1, 20000000, 3, 2, 1};
// 	FILE *file_write = fopen("result.bin", "wb");
// 	fwrite(y, sizeof(int), 5, file_write);
// 	fwrite(&y, sizeof(int), 5, file_write);
// 	fwrite(y, sizeof(y[0]), 5, file_write);
// 	fwrite(y, sizeof(y), 1, file_write);

// 	fclose(file_write);

// 	int x[5] = {}; 
// 	FILE *file_read = fopen("result.bin", "rb");
// 	fread(x, sizeof(int), 5, file_read);
// 	printf("%d %d\n", x[0], x[3]);
// 	fclose(file_read);


// 	int a; 
// 	float b;
// 	FILE *file_read = fopen("result.bin", "rb");
// 	fread(&a, sizeof(a), 1, file_read);
// 	printf("%d\n", a);
// 	fread(&a, sizeof(a), 1, file_read);
// 	printf("%d\n", a);
// 	fclose(file_read);

// 	return 0;
// }


// typedef struct Student {
//     char name[MAX_SIZE_OF_NAME];
//     int count_processor;
//     char name_processor[MAX_SIZE_OF_NAME];
//     int ram;
//     char type_of_video_controller[MAX_SIZE_OF_NAME];
//     int video_memory_capacity;
//     char type_of_hard_drive[MAX_SIZE_OF_NAME];
//     int count_of_hard_drives;
//     char capacity_of_hard_drives[MAX_SIZE_OF_NAME];
//     int count_of_external_devices;
//     char operating_system[MAX_SIZE_OF_NAME];
// } Student;


// Student* createStudent() {
//     Student* student = (Student*)malloc(sizeof(Student));
//     student->name;
//     student->count_processor;
//     student->name_processor;
//     student->ram;
//     student->type_of_video_controller;
//     student->video_memory_capacity;
//     student->type_of_hard_drive;
//     student->count_of_hard_drives;
//     student->capacity_of_hard_drives;
//     student->count_of_external_devices;
//     student->operating_system;
// }


// void copy_string(char* new_string, char* string) {
//     for (int i = 0; i < MAX_SIZE_OF_NAME; ++i) 
//         new_string[i] = string[i];
// }


// void clear_string(char* string) {
//     for (int i = 0; i < MAX_SIZE_OF_NAME; ++i) 
//         string[i] = ' ';
// }

// void print_string(char* string) {
//     for (int i = 0; i < MAX_SIZE_OF_NAME; ++i)
//         printf("%c", string[i]);
//     printf("\n");
// }

// int main() {
// 	// Student student = {"Alice", 23, "Intel"};
// 	// FILE *file_write = fopen("result.bin", "wb");
// 	// fwrite(&student, sizeof(student), 1, file_write);
// 	// fclose(file_write);


// 	Student student2;
// 	FILE *file_read = fopen("result.bin", "rb");
// 	fread(&student2, sizeof(student2), 1, file_read);
// 	print_string(student2.name);
// 	print_string(student2.name_processor);
// 	fclose(file_read);

// 	return 0;
// }





// int main() {
// 	char array[5] = {};
// 	int count;
// 	Student* student;
// 	student = createStudent();
// 	copy_string(student->name, "Alice");
//     student->count_processor = 13;
//     copy_string(student->name_processor, "AMDel");
// 	print_string(student->name_processor);

// 	FILE *file_write = fopen("result.bin", "wb");
// 	copy_string(array, student->name); 
// 	fwrite(&array, sizeof(student->name), 1, file_write);
// 	count = student->count_processor;
// 	fwrite(&count, sizeof(int), 1, file_write);
// 	copy_string(array, student->name_processor); 
// 	fwrite(&array, sizeof(student->name_processor), 1, file_write);
// 	fclose(file_write);
// 	free(student);
// 	print_string(student->name_processor);


// 	Student* student2;
// 	student2 = createStudent();
// 	FILE *file_read = fopen("result.bin", "rb");
// 	fread(&array, sizeof(array), 1, file_read);
// 	copy_string(student2->name, array);
// 	fread(&count, sizeof(int), 1, file_read);
// 	student2->count_processor = count;
// 	fread(&array, sizeof(array), 1, file_read);
// 	copy_string(student2->name_processor, array);
// 	print_string(student2->name);
// 	printf("%d\n", student2->count_processor);
// 	print_string(student2->name_processor);
// 	free(student2);
// 	fclose(file_read);

// 	return 0;
// }