# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void print(double a[100][100],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
            printf("%.3lf ",a[i][j]);
        printf("\n");
    }
}
void mul(double a[100][100],double b[100][100],double c[100][100],int m,int n,int t)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<t;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }
}
int main()
{
    int i,j,n,p;
    double M[100][100],R[100][100],T[100][100],new_R[100][100],sum=0;
    srand(time(0));
    printf("\nEnter dimension: ");
    scanf("%d",&n);
    printf("\nEnter p= ");
    scanf("%d",&p);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            M[i][j]=rand()%100;
            T[i][j]=M[i][j];//A copy of M
            sum+=M[i][j];
        }
        M[i][j]=1-sum;
        T[i][j]=M[i][j];
        sum=0;
    }
    print(M,n,n);
    for(i=0;i<n;i++)
        R[i][0]=(float)1/n;
    printf("\nVector R:\n");
    print(R,n,1);
    for(i=1;i<p;i++)
    {
        mul(M,M,T,n,n,n);
    }
    mul(T,R,new_R,n,1,n);
    printf("\nNew Vector R:\n");
    print(new_R,n,1);
    return 0;
}