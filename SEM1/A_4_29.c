#include<stdio.h>
#include<string.h>
void indian(int n)
{
    char d[][200]={"X","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char p[][200]={"X","X","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    char w[200]="";char s[200]="";
    int core=0,tl=0,l=0,tt=0,th=0,h=0,nt=0,o=0;
    core=n/10000000;
    //printf("%s Crore ",d[core]);
    //printf("%s",s);
    n %=10000000;
    tl=n/100000;
    if(tl<20)
    {
        l= tl;
        tl=0;
    }
    else
    {
        l=tl%10;
        tl/=10;
    }
    n %=100000;
    tt= n/1000;
    if(tt<20)
    {
        th=tt;
        tt=0;
    }
    else
    {
        th=tt%10;
        tt/=10;
    }
    n=n%1000;
    h=n/100;
    //printf("%d",h);
    n%=100;
    //printf("%d",n);
    if(n<20)
    {
        nt=0;
        o=n;
    }
    else
    {
        nt=n/10;
        o=n%10;
    }

    //Store crore
    if(core>0)
    {
        strcpy(s,d[core]);
        strcat(s," crore ");
        strcat(w,s);
    }
    // Store lakh 
    if(tl>0 && l>0)
    {
        strcpy(s,p[tl]);
        strcat(s," ");
        strcat(s,d[l]);
        strcat(s," lakh ");
        strcat(w,s);
    }
    else if(tl>0 && l==0)
    {
        strcpy(s,p[tl]);
        strcat(s," lakh ");
        strcat(w,s);
    }
    else if (tl==0 && l>0)
    {
        strcpy(s,d[l]);
        strcat(s," lakh ");
        strcat(w,s);
    }
    //Store thousand
    if(tt>0 && th>0)
    {
        strcpy(s,p[tt]);
        strcat(s," "); 
        strcat(s,d[th]);
        strcat(s," thousand ");
        strcat(w,s);
    }
    else if (tt>0 && th==0 )
    {
        strcpy(s,p[tt]);
        strcat(s, " thousand ");
        strcat(w,s);
    }
    else if (tt==0 && th>0)
    {
        strcpy(s,d[th]);
        strcat(s," thousand ");
        strcat(w,s);
    }
    //Store hundred
    if(h>0)
    {
        strcpy(s,d[h]);
        strcat(s," hundred ");
        strcat(w,s);
    }
    if(nt>0 && o>0)
    {
        strcpy(s,p[nt]);
        strcat(s, " ");
        strcat(s,d[o]);
        strcat(w,s);
    }
    else if (nt>0 && o==0)
    {
        strcpy(s,p[nt]);
        strcat(w,s);
    }
    else if (nt==0 && o>0)
    {
        strcpy(s,d[o]);
        strcat(w,s);
    }
    
    printf("\n%s",w);
}
void international(int n)
{
    char d[][200]={"X","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    char p[][200]={"X","X","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    char w[200]="";char s[200]="";
    int tm=0,m=0,ht=0,tt=0,th=0,h=0,nt=0,o=0;
    tm=n/1000000;
    if(tm<20)
    {
        m=tm;
        tm=0;
    }
    else
    {
        m=tm%10;
        tm/=10;
    }
    n%=1000000;
    ht=n/100000;
    n%=100000;
    tt=n/1000;
    if(tt<20)
    {
        th=tt;
        tt=0;
    }
    else
    {
        th=tt%10;
        tt/=10;
    }
    n%=1000;
    h=n/100;
    n%=100;
    if(n<20)
    {
        nt=0;
        o=n;
    }
    else
    {
        o=n%10;
        nt=n/10;
    }
    
    //Store million
    if(tm>0 && m>0)
    {
        strcpy(s,p[tm]);
        strcat(s," ");
        strcat(s,d[m]);
        strcat(s," million ");
        strcat(w,s);
    }
    else if (tm>0 && m==0)
    {
        strcpy(s,p[tm]);
        strcat(s," million ");
        strcat(w,s);
    }
    else if (tm==0 && m>0)
    {
        strcpy(s,d[m]);
        strcat(s," million ");
        strcat(w,s);
    }

    //Store thousand
    if(ht>0)
    {
        strcpy(s,d[ht]);
        strcat(s," hundred ");
        if(tt==0 && th==0)
        {
            strcat(s," thousand ");
        }
        strcat(w,s);
    }
    if(tt>0 &&th>0)
    {
        strcpy(s,p[tt]);
        strcat(s," ");
        strcat(s,d[th]);
        strcat(s," thousand ");
        strcat(w,s);
    }
    else if (tt==0 && th>0)
    {
        strcpy(s,d[th]);
        strcat(s," thousand ");
        strcat(w,s);
    }
    else if (tt>0 && th==0)
    {
        strcpy(s,p[tt]);
        strcat(s," thousand ");
        strcat(w,s);
    }
    
    //Store hundred
    if(h>0)
    {
        strcpy(s,d[h]);
        strcat(s," hundred ");
        strcat(w,s);
    }
    if(nt>0 && o>0)
    {
        strcpy(s,p[nt]);
        strcat(s, " ");
        strcat(s,d[o]);
        strcat(w,s);
    }
    else if (nt>0 && o==0)
    {
        strcpy(s,p[nt]);
        strcat(w,s);
    }
    else if (nt==0 && o>0)
    {
        strcpy(s,d[o]);
        strcat(w,s);
    }
    
    printf("\n%s",w);

}
int main()
{
    
    int n;
    printf("\nEnter 8 digit number: ");
    scanf("%d",&n);
    printf("\nIndian: ");
    indian(n);
    printf("\nInternational: ");
    international(n);
    return 0;
}