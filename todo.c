#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void delete_line(FILE* fp, int n);
extern int count_lines(FILE *fp);

int cmpfunc(const void *a, const void *b) {
   return (*(int*)b - *(int*)a);
}

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
        FILE *file = fopen(filename, "r+");
        int *to_delete = malloc(sizeof *to_delete * (argc-2));
        int num_lines = count_lines(file);

        for (int i = 0; i < argc-2; ++i) {
            to_delete[i] = atoi(argv[i+2]);
            if (to_delete[i] < 0 || to_delete[i] >= num_lines){
                fprintf(stderr, "file doesnt have line %d\n", to_delete[i]);
                goto rm_end;
            }
        }

        qsort(to_delete, argc-2, sizeof *to_delete, cmpfunc);
        for (int i = 0; i < argc-2; ++i) {
            delete_line(file, to_delete[i]);
        }

        rm_end:
        free(to_delete);
        fclose(file);
        return 0;
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
