#include "functions.h"

// Ракурсивно четена на директории
void read_directory_recursive(const char* path, struct file_info* files, int* count, double* total_size) {
    DIR* directory;
    struct dirent* entry;
    struct stat file_stat;

    // Отваряне на директорията
    directory = opendir(path);

    // Прочитане на информацията за всеки файл в директорията
    while ((entry = readdir(directory)) != NULL) {
        // Пропускане на "." и ".." директориите
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Създаване на пълното име на файла
        char full_path[200];
        strcpy(full_path, path);
        strcat(full_path, "\\");
        strcat(full_path, entry->d_name);

        // Прочитане на информацията за текущия елемент
        if (stat(full_path, &file_stat) != 0) {
            printf("Error getting file info: %s\n", full_path);
            continue;
        }

        // Проверка дали текущият елемент е директория
        if (S_ISDIR(file_stat.st_mode)) {
            // Ако текущият елемент е директория, функцията за четене на директории се извиква рекурсивно
            read_directory_recursive(full_path, files, count, total_size);
        } else {
            // Ако текущият елемент е файл, информацията за него се прочита и записва в масива от структури "file_info"
            struct file_info file_info;
            strcpy(file_info.name, entry->d_name);
            file_info.size = file_stat.st_size;
            strcpy(file_info.directory, path);

            files[*count] = file_info;
            (*count)++;

            // Увеличаване на общия размер на паметта с размера на текущия файл
            (*total_size) += file_stat.st_size;
        }
    }

    closedir(directory);
}
