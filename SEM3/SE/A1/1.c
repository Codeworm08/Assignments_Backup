#include <stdio.h>
#include <math.h>
void basic()
{
    int kloc;
    float a, b, c, d1, e, d;
    printf("\nEnter size of project in KLOC(kilo lines of code): ");
    scanf("%d", &kloc);
    if (0 <= kloc && kloc < 50)
    {
        printf("\nOrganic");
        a = 2.4;
        b = 1.05;
        c = 2.5;
        d1 = 0.38;
    }
    else if (50 <= kloc && kloc < 300)
    {
        printf("\nSemi-Detached");
        a = 3.0;
        b = 1.12;
        c = 2.5;
        d1 = 0.35;
    }
    else if (kloc >= 300)
    {
        printf("\nEmbedded");
        a = 3.6;
        b = 1.20;
        c = 2.5;
        d1 = 0.32;
    }
    else
    {
        printf("\nInvalid Input");
        return;
    }
    e = a * pow(kloc, b);
    d = c * pow(e, d1);
    printf("\nEffort: %f person-months", e);
    printf("\nDuration: %f months", d);
    printf("\nPeople: %g persons", ceil(e / d));
}
void intermediate()
{
    int kloc, model;
    float costdrivers[15][6] = {

        {0.75, 0.88, 1, 1.15, 1.40, -1},

        {-1, 0.94, 1, 1.08, 1.16, -1},

        {0.70, 0.85, 1, 15, 1.30, 1.65},

        {-1, -1, 1, 1.11, 1.30, 1.66},

        {-1, -1, 1, 1.06, 1.21, 1.56},

        {-1, 0.87, 1, 1.15, 1.30, -1},

        {-1, 0.87, 1, 1.07, 1.15, -1},

        {1.46, 1.19, 1, 0.86, 0.71, -1},

        {1.29, 1.13, 1.00, 0.91, 0.82, -1},

        {1.42, 1.17, 1, 0.86, 0.70, -1},

        {1.21, 1.10, 1, 0.90, -1, -1},

        {1.14, 1.07, 1, 0.95, -1, -1},

        {1.24, 1.10, 1.00, 0.91, 0.82, -1},

        {1.24, 1.10, 1, 0.91, 0.83, -1},

        {1.23, 1.08, 1, 1.04, 1.10, -1}

    };
    printf("\nChoose Reliability of Cost Drivers:\n");
    printf("\nVery Low:0\tLow:1\t:Nominal:2\tHigh:3\tVery High:4\tExtra High:5");
    float table[3][4] = {3.2, 1.05, 2.5, 0.38, 3.0, 1.12, 2.5, 0.35, 2.8, 1.20, 2.5, 0.32};
    char mode[][15] = {"Organic", "Semi-Detached", "Embedded"};
    char driver[15][6] = {"RELY", "DATA", "CPLX", "TIME", "STOR", "VIRT", "TURN", "ACAP", "AEXP", "PCAP",
                          "VEXP", "LEXP", "MODP", "TOOL", "SCED"};
    printf("\nEnter size of project in KLOC(kilo lines of code): ");
    scanf("%d", &kloc);
    if (kloc >= 2 && kloc <= 50)
        model = 0;
    else if (kloc > 50 && kloc <= 300)
        model = 1;
    else if (kloc > 300)
        model = 2;
    float eaf = 1,a,effort,time,staff,productivity;
    int rating;
    for (int i = 0; i < 15; i++)
    {
        do
        {
            printf("\nRate Cost Driver %s on scale of [0-5]: ",driver[i]);
            scanf("%d",&rating);
            a = costdrivers[i][rating];
            if(a==-1)
                printf("\nDriver has no value for this rating. Please choose another rating!\n");
        }while(a==-1);
        eaf*=a;        
    }
    effort = table[model][0] * pow(kloc, table[model][1]) * eaf;
    time = table[model][2] * pow(effort, table[model][3]);
    staff = effort / time;
    productivity = kloc / effort;
    printf("\nEAF: %f",eaf);
    printf("\nEffort: %f person-months", effort);
    printf("\nTime: %f months",time);
    printf("\nStaff: %f persons",staff);
    printf("\nProductivity: %f KLOC/person-months",productivity);
}
int main()
{
    int ch;
    do
    {
        printf("\nEnter:\n0 Quit\n1 for Basic COCOMO\n2 for Intermediate COCOMO");
        scanf("%d", &ch);
        switch (ch)
        {
            case 0:
                break;
            case 1:
                basic();
                break;
            case 2:
                intermediate();
                break;
            default:
                printf("\nInvalid Input");
                break;
        }
    } while (ch!=0);
    
    
    return 0;
}