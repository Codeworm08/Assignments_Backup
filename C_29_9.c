#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
    char name[200];
    int roll;
    int marks;
    char DOB[30];
};
typedef struct student student;
void create(FILE **fp)
{
    char name[200], path[200];
    printf("\nEnter filename: ");
    strcpy(path, "./");
    fflush(stdin);
    scanf("%[^\n]s", name);
    strcat(path, name);
    *fp = fopen(path, "wb+");
    if (*fp == NULL)
    {
        printf("\nCannot open file %s\n", path);
        exit(1);
    }
}
void write(FILE **fp)
{
    student s;
    getchar();
    printf("\nEnter name:");
    scanf("%[^\n]s", s.name);
    printf("Enter roll: ");
    scanf("%d", &s.roll);
    printf("\nEnter marks: ");
    scanf("%d", &s.marks);
    getchar();
    printf("\nEnter date-of-birth: ");
    scanf("%[^\n]s", s.DOB);
    fwrite(&s, 1, sizeof(s), *fp);
}
void print(FILE **fp)
{
    student t;
    rewind(*fp);
    while (fread(&t, sizeof(t), 1, *fp) != 0)
    {
        printf("%s", t.name);
        printf("\nRoll: %d", t.roll);
        printf("\nMarks: %d", t.marks);
        printf("\nDOB: %s", t.DOB);
    }
}
void delete(FILE **fp, int roll)
{
    FILE *fw;
    fw = fopen("./temp.bin", "wb+");
    rewind(*fp);
}
void modify(FILE **fp)
{
    FILE *fw;
    fw = fopen("./temp.bin", "wb+");
    rewind(*fp);
    student x;
    while (fread(&x, sizeof(x), 1, *fp) != 0)
    {
        if (x.marks < 50 && x.marks > 40)
        {
            x.marks += 10;
        }
        fseek(*fp, -sizeof(x), SEEK_CUR);
        fwrite(&x, sizeof(x), 1, *fp);
    }
}
int main()
{
    FILE *fp;
    int i;
    create(&fp);
    write(&fp);
    modify(&fp);
    print(&fp);
    return 0;
}