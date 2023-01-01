#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fp, *fw;
    int i, j, r = 0, c = 0, *rows;
    char ch;
    fp = fopen("./matrix.txt", "r");
    if (fp == NULL)
    {
        printf("Failed to open file!");
        return 1;
    }
    fw = fopen("./6out.txt", "w");
    ch = fgetc(fp);
    while (ch != EOF)
    {
        if (ch == 10)
            r++;
        ch = fgetc(fp);
    }
    r--;
    rewind(fp);
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == 48 || ch == 49)
            c++;
        if (ch == 10)
            break;
    }
    printf("Rows: %d Cols: %d", r, c);
    rows = (int *)malloc(r * sizeof(int));
    rewind(fp);
    i = 0;
    rows[0] = 0;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == 48 || ch == 49)
            rows[i] += (int)(ch - 48);
        if (ch == 10)
        {
            putc(48 + i + 1, fw);
            putc(':', fw);
            putc(' ', fw);
            putc(48 + rows[i], fw);
            putc('\n', fw);
            i++;
            rows[i] = 0;
        }
    }
    fclose(fp);
    fclose(fw);
    free(rows);
    return 0;
}
