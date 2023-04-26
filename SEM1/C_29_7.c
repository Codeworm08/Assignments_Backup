#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;
    FILE *fp, *fw;
    fp = fopen("./inp.txt", "r");
    fw = fopen("./out.txt", "w");
    ch = fgetc(fp);
    while (ch != EOF)
    {
        putc(toupper(ch), fw);
        ch = fgetc(fp);
    }
    fclose(fp);
    fclose(fw);
    return 0;
}