#include "user_input_check.c"

int main() {
    struct file_info files[1000];
    int count = 0;
    double total_size = 0;
    char path[200];
    DIR* directory;
    char option[3];
    char parameter_1[2];
    char parameter_2[2];
    char running[10] = "yes";
    
    while (strcmp(running, "yes") == 0 )
    {
        printf("\n");
        printf("Enter the directory path (C:\Users\Hristo\Desktop\MyFolder): ");
        scanf("%s", path);
        open_dir_check(directory, path, files, &count, &total_size);

        read_directory_recursive(path, files, &count, &total_size);

        print_data_table(files, count, total_size);
        
        print_user_table();

        printf("%s", "Enter format and order of analysis: ");
        scanf("%1s%1s", parameter_1, parameter_2);
        
        input_checks(parameter_1, parameter_2);

        printf("\n");

        if (strcmp(parameter_1, "t") == 0) {
            print_table(files, count, total_size, parameter_2);
        }
        else if (strcmp(parameter_1, "d") == 0) {
            print_diagram(files, count, total_size, parameter_2);
        }
        else if (strcmp(parameter_1, "b") == 0) {
            print_table(files, count, total_size, parameter_2);
            print_diagram(files, count, total_size, parameter_2);
        }
        
        printf("Do you want to do new analysis (yes/no): ");
        scanf("%s", running);
        printf("\n");
    }

    return 0;
}
