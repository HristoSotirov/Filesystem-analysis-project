#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

struct file_info {
    char name[100];
    double size;
    char directory[100];
    char full_path[200];
};

// Ракурсивно четена на директории
void read_directory_recursive(const char* path, struct file_info* files, int* count, double* total_size);

// Сортиране на масива във възходящ ред
void sort_files_by_size_asc(struct file_info* files, int count);

// Сортиране на масива в низходящ ред
void sort_files_by_size_desc(struct file_info* files, int count);

// Преобразуване на размера на паметта в нужния формат
void format_file_size(long size_in_bytes);

// Принтиране на таблица с резултатите от анализа
void print_table(struct file_info* files, int count, double total_size, char* order);

// Принтиране на диаграма с резултатите от анализа
void print_diagram();

// Принтира първичните данни от анализа 
void print_data_table(struct file_info* files, int count, double total_size);

// Принтиране на таблица за улеснение на потребителя при работа с програмата
void print_user_table();

// Проверка дали избраната директория съществува 
void open_dir_check(DIR* directory, const char* path, struct file_info* files, int* count, double* total_size);

// Проверка на въведените данни от потреботеля
void input_checks(char* parameter_1, char* parameter_2);

