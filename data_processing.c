#include "structure.c"

// Сортиране на масива във възходящ ред
void sort_files_by_size_asc(struct file_info* files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (files[i].size > files[j].size) {
                // swap the two files
                struct file_info temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

// Сортиране на масива в низходящ ред
void sort_files_by_size_desc(struct file_info* files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (files[i].size < files[j].size) {
                // Размяна на двата файла
                struct file_info temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

// Преобразуване на размера на паметта в нужния формат
void format_file_size(long size_in_bytes) {
    char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int index = 0;
    double size = (double)size_in_bytes;
    
    while (size >= 1024 && index < 4) {
        size /= 1024;
        index++;
    }
    
    printf("%4.0f %2s", size, units[index]);
}
