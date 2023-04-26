#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct library
{
    int acn;
    char *title;
    char *aname;
    float price;
    int issued;
};
typedef struct library library;
void addInfo(library *b)
{
    b->title=(char*)malloc(sizeof(char)*200);
    b->aname=(char*)malloc(sizeof(char)*200);
    printf("\nEnter accession number: ");
    scanf("%d",&b->acn);
    printf("\nEnter title of book: ");
    getchar();
    fgets(b->title,200,stdin);
    getchar();
    printf("\nEnter author name: ");
    fgets(b->aname,200,stdin);
    printf("\nEnter price: ");
    scanf("%f",&b->price);
    printf("\n0:Not issued.\t1:Issued");
    scanf("%d",&b->issued);
}
void displayBook(library *b)
{
    printf("\nAccession number: %d",b->acn);
    printf("\nTitle of book: %s",b->title);
    printf("Author name: %s",b->aname);
    printf("Price: %.2f",b->price);
    if(b->issued)
        printf("\nISSUED");
    else
        printf("\nNOT ISSUED");
}
void displayLibA(library *l,int n,char a[200])
{
    int i;
    printf("\nBooks of Author %s",a);
    for(i=0;i<n;i++)
    {
        if(!strcmp(a,l[i].aname))
            displayBook(&l[i]);    
    }    
}
void dispTitle(int acn,library *l,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(l[i].acn==acn)
        {
            printf("\nTitle: %s",l[i].title);
            return;
        }
    }
    printf("\nBook Not Found!");
}
void dispCount(library *l,int n)
{
    printf("\nNo of books in library: %d",n);    
}
void dispAccn(int acn,library *l,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(l[i].acn==acn)
            displayBook(&l[i]);
    }
}
void dispOrder(library *l,int n)
{
    int *an;
    int i,j,t;
    an=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        an[i]=l[i].acn;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(an[j]>an[j+1])
            {
                t=an[j];
                an[j]=an[j+1];
                an[j+1]=t;
            }
        }
    }
    for(i=0;i<n;i++)
        dispAccn(an[i],l,n);
}

int main()
{
    library *l;
    int n,i=0,an;
    char ch,name[200],title[200];
    printf("\nEnter no. of books: ");
    scanf("%d",&n);
    l = (library*)malloc(sizeof(library)*n);
    do
    {
        getchar();
        printf("\n\nEnter:\na.Add Book\nb.Display Book Info\nc.List all books of given author.\nd.List title of specified book.\ne.Count of books in the Library.\nf.List books in order of succession number\ng.Quit.");
        scanf("%c",&ch);
        switch (ch)
        {
        case 'a':
            addInfo(&l[i]);
            i++;
            break;
        case 'b':
            printf("\nEnter accession number of book to disp: ");
            scanf("%d",&an);
            dispAccn(an,l,i);
            break;
        case 'c':
            printf("\nAuthor name: ");
            getchar();
            fgets(name,200,stdin);
            displayLibA(l,i,name);
            break;
        case 'd':
            printf("\nEnter accession number of book: ");
            scanf("%d",&an);
            dispTitle(an,l,i);
            break;
        case 'e':
            dispCount(l,i);
            break;
        case 'f':
            dispOrder(l,i);
            break;
        case 'g':
            printf("\n__________THANK YOU__________\n");
            break;
        default:
            printf("\nInvalid Input!!");
            break;
        }
    } while (ch!='g');
  
    return 0;
}