#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu
{
    char *name;
    int roll;
    int marks[5];
};
typedef struct stu student;
student input()
{
    student t;
    char *name = malloc(sizeof(char) * 200);
    int i, roll, marks[5], j;
    t.name = malloc(sizeof(char) * 200);
    printf("\nEnter name: ");
    getchar();
    fgets(t.name, 200, stdin);
    printf("\nEnter roll: ");
    scanf("%d", &t.roll);
    for (j = 0; j < 5; j++)
    {
        printf("\nEnter marks of subject %d: ", j + 1);
        scanf("%d", &t.marks[j]);
    }
    return t;
}

student sort(student *s, int *total, int n)
{
    int sorted[n], i, j, t;
    for (i = 0; i < n; i++)
        sorted[i] = i;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (total[j] > total[j + 1])
            {
                t = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = t;
                t = total[j];
                total[j] = total[j + 1];
                total[j + 1] = t;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\nName: %s\tTotal: %d", s[sorted[i]].name, total[i]);
    }
}

int main()
{
    student *st = NULL;
    int n, i, j, marks[5], roll, *total;
    float *avg;
    char name[200];
    printf("Enter no of students: ");
    scanf("%d", &n);
    total = calloc(n, sizeof(int));
    avg = calloc(n, sizeof(float));
    st = (student *)malloc(sizeof(student) * n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter student %d details: ", i + 1);
        st[i] = input();
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
            total[i] += st[i].marks[j];
    }
    for (i = 0; i < n; i++)
    {
        printf("\nTotal marks of student %d is: %d", i + 1, total[i]);
    }
    for (i = 0; i < n; i++)
    {
        avg[i] = total[i] / 5.0;
        printf("\nAverage Marks of student %d: %f", i + 1, avg[i]);
    }
    /*for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (total[j] > total[j + 1])
            {
                swap(&st[j], &st[j + 1]);
            }
        }
    }*/
    printf("\nSorted names:\n");
    sort(st, total, n);
    // printf("\nStudents:\n");
    // for (i = 0; i < n; i++)
    // {
    //     printf("\nStudent %d:\n", i + 1);
    //     printf("\n\tName: %s", st[i].name);
    //     printf("\n\tRoll: %d", st[i].roll);
    //     printf("\n\tMarks: ");
    //     for (j = 0; j < 5; j++)
    //     {
    //         printf("\n\t\tSubject %d: %d", j + 1, st[i].marks[j]);
    //     }
    // }
    // for (i = 0; i < n; i++)
    // {
    //     printf("\nName: %s Total: %d", st[i].name, total[i]);
    // }
    return 0;
}