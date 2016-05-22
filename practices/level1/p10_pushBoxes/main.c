#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void init();
void prestart();
void chooseLevel();
void getMap();
void showMap();
void inputJduge();
int completeCheck();
void saveScore();

char line[100],map[7][100];
int m=3,n=12,step=0;
FILE *fp,*sp;

int main()
{
    while(1)
    {
        init();
        prestart();
        chooseLevel();
        getMap();
        showMap();
        while(1)
        {
            inputJduge();
            system("cls");
            showMap();
            int b;
            ++step;
            if(b=completeCheck()==4)
            {
                saveScore();
                break;
            }
        }
    }
    return 0;
}

void init()
{
    m=3;
    n=12;
    step=0;
}

void prestart()
{
    printf("please choose a level to start:\n");
    printf("0:level0     1:level1     2:level2\n");
}

void chooseLevel()
{
    int i;
    scanf("%d",&i);
    system("cls");
    switch(i)
    {
        case 0:fp=fopen("D:\\LEVEL0.txt","rt");sp=fopen("D:\\LEVEL0_SCORE.txt","wt+");break;
        case 1:fp=fopen("D:\\LEVEL1.txt","rt");sp=fopen("D:\\LEVEL1_SCORE.txt","wt+");break;
        case 2:fp=fopen("D:\\LEVEL2.txt","rt");sp=fopen("D:\\LEVEL2_SCORE.txt","wt+");break;
        default:printf("please input right number,press any key to exit\n");getch();exit(1);
    }
}

void getMap()
{
    int i=0;
    while(fgets(line,100,fp)!=NULL)
    {
        strcpy(map[i++],line);
    }
}

void showMap()
{
    int i;
    for(i=0;i<7;i++)
        printf("%s",map[i]);
}

void inputJduge()
{
    char a=getch();
    if(a=='w')
    {
        if(map[m-1][n]==' ')
        {
            map[m][n]=' ';
            map[m-1][n]='P';
            m--;
        }
        if(map[m-1][n]=='B')
        {
            if(map[m-2][n]==' ')
            {
                map[m][n]=' ';
                map[m-1][n]='P';
                map[m-2][n]='B';
                m--;
            }
            if(map[m-2][n]=='X')
            {
                map[m][n]=' ';
                map[m-1][n]='P';
                map[m-2][n]='+';
                m--;
            }
        }
    }
    if(a=='s')
    {
        if(map[m+1][n]==' ')
        {
            map[m][n]=' ';
            map[m+1][n]='P';
            m++;
        }
        if(map[m+1][n]=='B')
        {
            if(map[m+2][n]==' ')
            {
                map[m][n]=' ';
                map[m+1][n]='P';
                map[m+2][n]='B';
                m++;
            }
            if(map[m+2][n]=='X')
            {
                map[m][n]=' ';
                map[m+1][n]='P';
                map[m+2][n]='+';
                m++;
            }
        }
    }
    if(a=='a')
    {
        if(map[m][n-1]==' ')
        {
            map[m][n]=' ';
            map[m][n-1]='P';
            n--;
        }
        if(map[m][n-1]=='B')
        {
            if(map[m][n-2]==' ')
            {
                map[m][n]=' ';
                map[m][n-1]='P';
                map[m][n-2]='B';
                n--;
            }
            if(map[m][n-2]=='X')
            {
                map[m][n]=' ';
                map[m][n-1]='P';
                map[m][n-2]='+';
                n--;
            }
        }
    }
    if(a=='d')
    {
        if(map[m][n+1]==' ')
        {
            map[m][n]=' ';
            map[m][n+1]='P';
            n++;
        }
        if(map[m][n+1]=='B')
        {
            if(map[m][n+2]==' ')
            {
                map[m][n]=' ';
                map[m][n+1]='P';
                map[m][n+2]='B';
                n++;
            }
            if(map[m][n+2]=='X')
            {
                map[m][n]=' ';
                map[m][n+1]='P';
                map[m][n+2]='+';
                n++;
            }
        }
    }
}

int completeCheck()
{
    int i,j,sum=0;
    for(i=0;i<7;i++)
    {
        for(j=0;j<100;j++)
        {
            if(map[i][j]=='+')
            {
                sum++;
            }
        }
    }
    return sum;
}

void saveScore()
{
    system("cls");
    printf("you got it with %d steps.press any key to continue\n",step);
    fprintf(sp,"%d",step);
    fclose(sp);
    fclose(fp);
    getch();
    system("cls");
}
