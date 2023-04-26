#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char ch;
    FILE *fp, *fw;
    fp = fopen("./f1.txt", "r");
    fw = fopen("./f2.txt", "a");
    ch = fgetc(fp);
    while (ch != EOF)
    {
        putc(ch, fw);
        ch = fgetc(fp);
    }
    fclose(fp);
    fclose(fw);
    return 0;
}

