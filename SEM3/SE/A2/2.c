#include<stdio.h>
#include<math.h>

int main(){
    FILE *fp=NULL;
    double time;
    printf("\nReliability for case 1: %lf",exp(-0.3*3));//e^-kt
    printf("\nReliability for case 2: %lf",exp(-0.5*0.9*5*5));//e^(-kt^2)/2
    printf("\nReliability for case 3: %lf",exp(-0.9 * pow(5,1.5))/1.5);//e^(-kt^(m+1)/(m+1))
    fp = fopen("f1.txt","w");// constant hazard
    for(time=1;time<=10;time++)
        fprintf(fp,"%lf\t%lf\n",time,exp(-0.3*time));
    fclose(fp);
    
    fp=fopen("f2.txt","w");//linear hazard
    for(time=1;time<=10;time++)
        fprintf(fp,"%lf\t%lf\n",time,exp(-0.5*0.9*time*time));
    fclose(fp);

    fp=fopen("f3.txt","w");//Weibul distribution
    for(time=1;time<=10;time++)
        fprintf(fp,"%lf\t%lf\n",time,exp(-0.9 * pow(time,1.5))/1.5);
    fclose(fp);
    return 0;
}