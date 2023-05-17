#include "data_processing.c"

// Принтира първичните данни от анализа 
void print_data_table(struct file_info* files, int count, double total_size){
    printf("\n");
    printf("Found %d files:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s\\%s ", files[i].directory, files[i].name);
        printf("(");
        format_file_size(files[i].size);
        printf(")");
        printf("\n");
    }
    printf("Total size: ");
    format_file_size(total_size);
    printf("\n");
    printf("\n");
}

// Принтиране на таблица с резултатите от анализа
void print_table(struct file_info* files, int count, double total_size, char* order) {
    // Сортиране според избраният ред
    if (strcmp(order, "U") == 0){
        sort_files_by_size_asc(files, count);
    }
    else if (strcmp(order, "D") == 0){
        sort_files_by_size_desc(files, count); 
    }

    // Принтиране на заглавие
    printf("%-30s|%20s|%20s|\n", "File name", "Size", "Percentage %");
    for (int i = 1; i <= 30; i++) {
        printf("-");
    }
    printf("+");
    for (int i = 1; i <= 20; i++) {
        printf("-");
    }
    printf("+");
    for (int i = 1; i <= 20; i++) {
        printf("-");
    }
    printf("|");
    printf("\n");

    // Принтиране на редовете
    double total_size_percentage = 0;
    for (int i = 0; i < count; i++) {
        int len_name = strlen(files[i].name);
        int len_directory = 27 - len_name;
        double size_percentage = files[i].size / total_size * 100;
        char directory_and_name[200] = {};
        strcpy(directory_and_name, files[i].directory);
        strcat(directory_and_name, "\\");
        strcat(directory_and_name, files[i].name);

        // Минимизиране на пълната пътека до фаила и името на файла ако общо са с дължина по-голяма от 30 символа
        if (len_name > 30) {
            for (int j = 0; j < 27; j++) {
                printf("%c", files[i].name[j]);
            }
            printf("...");
        } 
        else if (len_name < 30){
            if (strlen(directory_and_name) < 30){
                printf("%s", directory_and_name);
            }
            else if (strlen(directory_and_name) > 30){
                
                for (int k = 0; k < len_directory; k++){
                    printf("%c", files[i].directory[k]);
                }
                printf("...%s", files[i].name);
            }
        }
        printf("|");

        // Форматиране на размера на файла така че да е дясно подравнен в таблицата
        printf("%13s", " ");
        format_file_size(files[i].size);
        printf("|");

        // Форматиране на процента на заета памет от целвата папка така че да е дясно подравнен в таблицата
        printf("%19.2f%%", size_percentage);
        printf("|\n");
    }

    // Принтиране на последния ред
    for (int i = 1; i <= 72; i++) {
        printf("-");
    }
    printf("+");
    printf("\n\n");
}

// Принтиране на диаграма с резултатите от анализа
void print_diagram(struct file_info* files, int count, double total_size, char* order) {
    
    // Извличане на размера на най-големия файл
    sort_files_by_size_desc(files, count);
    double bigest_size_percentage = files[0].size / total_size * 100;
    // Изчисляване на пропорция за изчертаването на диаграмата
    double proportion = 50 / bigest_size_percentage;
    
    // Сортиране според избрания ред
    if (strcmp(order, "U") == 0){
        sort_files_by_size_asc(files, count);
    }
    else if (strcmp(order, "D") == 0){
        sort_files_by_size_desc(files, count); 
    }

    // Принтиране на заглавие
    printf("%-30s|%-50s|\n", "File name", "Memory usage %");
    for (int i = 1; i <= 30; i++) {
        printf("-");
    }
    printf("+");
    for (int i = 1; i <= 50; i++) {
        printf("-");
    }
    printf("|");
    printf("\n");
    
    // Принтиране на редовете
    for (int i = 0; i < count; i++) {
        int len_name = strlen(files[i].name);
        int len_directory = 27 - len_name;
        double size_percentage = files[i].size / total_size * 100;
        char directory_and_name[200] = {};
        strcpy(directory_and_name, files[i].directory);
        strcat(directory_and_name, "\\");
        strcat(directory_and_name, files[i].name);

        // Минимизиране на пълната пътека до фаила и името на файла ако общо са с дължина по-голяма от 30 символа
        if (len_name > 30) {
            for (int j = 0; j < 27; j++) {
                printf("%c", files[i].name[j]);
            }
            printf("...");
        } 
        else if (len_name < 30){
            if (strlen(directory_and_name) < 30){
                printf("%-30s", directory_and_name);
            }
            else if (strlen(directory_and_name) > 30){
                
                for (int k = 0; k < len_directory; k++){
                    printf("%c", files[i].directory[k]);
                }
                printf("...%s", files[i].name);
            }
        }
        printf("|");

        // Принтиране на диаграмата
        int chart_lenght = size_percentage * proportion;
        for (int j = 0; j < chart_lenght; j++) {
            printf("=");
            
        }
        for (int k = chart_lenght; k < 50; k++) {
            printf(" ");
        }

        printf("|\n");
        }

    for (int i = 0; i < 81; i++) {
    printf("-");
    }

    printf("+");
    printf("\n");
    printf("\n\n");
}

// Принтиране на таблица за улеснение на потребителя при работа с програмата
void print_user_table(){
    printf("\n%-30s|%-30s|\n", "Format of analysis", "Order of analysis");
    for (int i = 0; i < 2; i++)
    {
        for (int i = 0; i < 30; i++) {
        printf("-");
        }
        printf("+");
    }
    printf("\n");
    printf("%-30s|%-30s|\n", "t - Table", "U - Ascending visualization");
    printf("%-30s|%-30s|\n", "d - Diagram", "D - Descending order");
    printf("%-30s|%-30s|\n", "b - Both", " ");
    for (int i = 0; i < 61; i++) {
    printf("-");
    }

    printf("+");
    printf("\n\n");
    printf("%s\n\n", "Examples: tU, dD, bD ...");
}

