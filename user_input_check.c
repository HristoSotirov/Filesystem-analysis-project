#include "print_data.c"

// Проверка дали избраната директория съществува 
void open_dir_check(DIR* directory, const char* path, struct file_info* files, int* count, double* total_size){
    directory = opendir(path);
    if (directory == NULL) {
        printf("Error opening directory: %s\n", path);
        printf("Enter new directory path: ");
        scanf("%s", path);
        read_directory_recursive(path, files, count, total_size);
        return;
    }
    
}

// Проверка на въведените данни от потреботеля
void input_checks(char* parameter_1, char* parameter_2){
    while (strcmp(parameter_1, "t") != 0 && strcmp(parameter_1, "d") != 0 && strcmp(parameter_1, "b") != 0)
    {
        printf("Invalid format of analysis. Try again: ");
        scanf("%1s",parameter_1);
    }
    while (strcmp(parameter_2, "U") != 0 && strcmp(parameter_2, "D") != 0)
    {
        printf("Invalid order of analysis. Try again ");
        scanf("%1s", parameter_2);
    }
}

