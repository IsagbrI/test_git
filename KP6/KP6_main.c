#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "KP6.h"


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
    return 0;
}