#include<stdio.h>
void readMatrix(int M[200][200],int r, int c)
{
    int i,j;
    printf("\nEnter array: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",&M[i][j]);
    }
}
void transpose(int A[200][200],int T[200][200],int r1,int c1)
{
    int i,j;
    for(i=0;i<c1;i++)
        for(j=0;j<r1;j++)
            T[i][j]=A[j][i];
}
void mul(int A[200][200],int B[200][200],int C[200][200],int r1,int c1,int r2,int c2)
{
    int i,j,k;
    if(c1!=r2)
    {
        printf("\nMultiplication not possible!");
        return;
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            C[i][j]=0;
            for(k=0;k<r2;k++)
                C[i][j]+=(A[i][k]*B[k][j]);
        }
    }
}

int main()
{
    int r,c,A[200][200],T[200][200],I[200][200],i,orth=1;
    printf("\nEnter row and column dimensions of the Matrix: ");
    scanf("%d%d",&r,&c);
    readMatrix(A,r,c);
    transpose(A,T,r,c);
    if(r!=c)
        printf("\nNot Orthogonal since not square matrix!");
    else
    {
        mul(A,T,I,r,c,r,c);
        for(i=0;i<r;i++)
        {
            if(I[i][i]!=1)
                orth=0;
        }
        if(orth)
            printf("\nMatrix is Orthogonal.");
        else
            printf("\nMatrix is not Orthogonal.");
    }
    return 0;
}