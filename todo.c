#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    if (argc < 2) { goto help; }

    const char *filename = strcat(getenv("HOME"), "/.TODO");

    if (!strcmp(argv[1], "add")) {
        FILE* file = fopen(filename , "a");
        for (int i = 2; i < argc; ++i) fprintf(file, "%s\n", argv[i]);
        fclose(file);
        return 0;
    }

    if (!strcmp(argv[1], "list")) {
        /* fixme */
        FILE *file = fopen(filename, "a+");
        char c = fgetc(file);
        int num = 0;
        printf("0 ");
        while (c != EOF) {
            if(c != '\n') printf("%c", c);
            else printf("\n%d ", ++num);
            c = fgetc(file);
        }
        printf("\b\b");
        fclose(file);
        return 0;
    }

    if (!strcmp(argv[1], "rm")) {
        /* todo */
    }

    if ((!strcmp(argv[1], "clear")) || (!strcmp(argv[1], "clean"))) {
        remove(filename);
        return 0;
    }

    help:
    printf("list - lists tasks\nadd - adds task\nrm - removes task\n"
           "clear/clean - removes ~/.TODO\n");
    return 0;
}
