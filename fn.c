#include <unistd.h>
#include <stdio.h>

int count_lines(FILE *fp) {
    long start_pos = ftell(fp);
    int n = 0;
    int chr = 'd';
    while ((chr = fgetc(fp)) != EOF) {
        if (chr == '\n') n++;
    }
    fseek(fp, start_pos, SEEK_SET);
    return n;
}

void delete_line(FILE* fp, int n) {
    long start_pos = ftell(fp);
    char byte;
    while (n) {
        fread(&byte, 1, 1, fp);
        if (byte == '\n') n--;
    }
    long write_pos = ftell(fp);
    byte = 0;
    while (byte != '\n') { fread(&byte, 1, 1, fp); }
    long read_pos = ftell(fp);
    while (fread(&byte, 1, 1, fp)) {
        read_pos = ftell(fp);
        fseek(fp, write_pos, SEEK_SET);
        fwrite(&byte, 1, 1, fp);
        write_pos = ftell(fp);
        fseek(fp, read_pos, SEEK_SET);
    }
    ftruncate(fileno(fp), write_pos);
    fseek(fp, start_pos, SEEK_SET);
}
