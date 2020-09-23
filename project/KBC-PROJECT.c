#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<Windows.h>
#include<string.h>
#include<dos.h>

#define MAX_OPTION 3
#define MAX_OPTION1 5
char pass1[11]={"GAMEMASTER"};
char user[11]={"gamemaster"};
COORD c= {0,0};
void gotoxy(int x, int y);
void enter_hscore(char username[],int n);
void hscore();
void enter_hscore(char username[],int n);
void addquestions();
void show_level(int lev,int x);
void level(char username[]);
void startgame();
void login();
void help();
int menuhandler();


void gotoxy(int x, int y)
{
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
struct highscore
{
    char name[50];
    int num;
};
typedef struct highscore highscore;

void enter_hscore(char username[],int n)
{
    FILE *hs;
    hs=fopen("highscores.txt","a");
    fprintf(hs,"%s",username);
    fputc('\n',hs);
    fwrite(&n,sizeof(n),1,hs);
    fclose(hs);
    return;
}

void hscore()
{
    FILE *hs;
    highscore arr[100];
    char c[50],h;
    int i,j,k,number,n;
    hs=fopen("highscores.txt","r");
    i=0;
    while(fgets(c,50, hs) != NULL)
    {
        strcpy(arr[i].name,c);
        int x=strlen(arr[i].name);
        arr[i].name[x-1]='\0';
        fread(&n,sizeof(n),1,hs);
        arr[i].num=n;
        i++;
    }
    highscore temp;
    for(int k=0;k<(i-1);k++)
    {
        for(int q=k+1;q<i;q++)
        {
            if(arr[k].num<arr[q].num)
            {
                temp=arr[k];
                arr[k]=arr[q];
                arr[q]=temp;
            }
            else if(arr[k].num==arr[q].num)
            {
                if(strcmp(arr[k].name,arr[q].name)>0)
                {
                    temp=arr[k];
                    arr[k]=arr[q];
                    arr[q]=temp;
                }
            }
        }
    }
    gotoxy(57,1);
    printf("***** HIGHSCORES *****\n\n\n");
    printf("\t\t\t\t\t\t    Position    Username\tPoints");
    printf("\n\n");
    for(k=0;k<i;k++)
    {
        printf("\t\t\t\t\t\t\t");
        printf("%d.\t",k+1);
        printf("%s\t",arr[k].name);
        int x=strlen(arr[k].name);
        if(x<=7)
            printf("\t");
        printf("%d\n\n",arr[k].num);
    }
    fclose(hs);
    getch();
    return ;

}

void addquestions()
{
    FILE *fq,*fo,*fa;
    char ques[150]={},add[3]={},options[100]={},ans,ch;
    system("cls");
    gotoxy(5,5);
    printf("DO YOU WANT TO ADD QUESTION?YES/NO\t");
    fflush(stdin);
    gets(add);
    if(add[0]=='Y'|| add[0]=='y')
    {
        printf("\n\tType your question:\n\t");
        gets(ques);
        fq=fopen("questions.txt","a");
        fputs(ques,fq);
        fputc('\n',fq);
        fclose(fq);
        printf("\tType your options:\n\t");
        gets(options);
        fo=fopen("options.txt","a");
        fputs(options,fo);
        fputc('\n',fo);
        fclose(fo);
        printf("\tType your answer:\n\t");
        fa=fopen("answers.txt","a");
        scanf(" %c",&ans);
        fputc(ans,fa);
        fclose(fa);
        addquestions() ;
    }
    else
        return;
}
void show_level(int lev,int x)
{

    system("cls");
    gotoxy(60,15);
    printf("GREAT!!! YOU'RE NOW ON LEVEL %d",lev);
    gotoxy(60,16);
    printf("EACH QUESTION CARRIES %d POINTS NOW",x);
    gotoxy(55,18);
    printf("Press any key to continue.....");
    getch();
    return;
}
void level(char username[])
{
        FILE *fq,*fo,*fa;
        char ques[150]= {},add[3]= {},options[100]= {},ans,ch,x=5;
        int n=1,points=0,lev=1;
        fq=fopen("questions.txt","r");
        fo=fopen("options.txt","r");
        fa=fopen("answers.txt","r");
        while(fgets(ques, 100, fq) != NULL)
        {

            system("cls");
            system("color 5E");
            gotoxy(63,5);
            printf("YOU ARE ON LEVEL %d",lev);
            gotoxy(50,8);
            printf("QUESTION No. : %d",n);
            gotoxy(75,8);
            printf("TOTAL POINTS: %d",points);
            gotoxy(45,12);
            printf("QUESTION :\t");
            printf("%s", ques);
            gotoxy(45,14);
            printf("Options:");
            gotoxy(45,16);
            fgets(options, 100, fo);
            printf("\t%s", options);
            gotoxy(45,17);
            fgets(options, 100, fo);
            printf("\t%s", options);
            gotoxy(45,18);
            fgets(options, 100, fo);
            printf("\t%s", options);
            gotoxy(45,19);
            fgets(options, 100, fo);
            printf("\t%s", options);
            gotoxy(50,21);
            printf("Enter your answer: ");
            scanf(" %c",&ch);
            char r=fgetc(fa);
            if (ch==r)
            {
                system("cls");
                system("color 5A");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\a  Verdict:\tCORRECT ANSWER!\n");
                printf("\n\t\t\t\t\t\t  Press any key to continue to next question...");
                getch();
                points+=x;
                if(n==10)
                    {
                        lev++;
                        n=0;
                        x=x+5;
                        show_level(lev,x);
                    }
                n++;
            }
            else
            {
                fclose(fq);
                fclose(fo);
                fclose(fa);
                enter_hscore(username,points);

                for(int i=1; i<=5; i++)
                {
                system("cls");
                system("color 5C");
                Beep(700,350);
                gotoxy(60,8);
                printf("Verdict: WRONG ANSWER!\n");
                gotoxy(62,12);
                printf("\tGAME OVER!!!");
                gotoxy(64,16);
                printf("YOUR SCORE: %d",points);
                gotoxy(50,20);
                printf("Press any key to continue to go back...");
                Sleep(300);
                system("cls");
                Sleep(300);
                }
                break;
            }
        }
        return;
}

void startgame()
{
    system("cls");
    gotoxy(45,15);
    char username[100];
    printf("Enter Username:\t");
    scanf("%s",username);
    system("cls");
    gotoxy(60,15);
    printf("WELCOME %s !!!",username);
    gotoxy(55,17);
    printf("Press any key to continue.....");
    getch();
    level(username);
    return;
}

void login()
{
    char username[50]={},password[25]={};
    char ch;
    int i=0,j;
    gotoxy(50,10);
    for(int i=0;i<10;i++)
    {
    printf("*");
    }
    printf("PASSWORD PROTECTED");
    for(int i=0;i<10;i++)
    {
    printf("*");
    }
    gotoxy(60,15);
    printf("Enter username:\t");
    scanf("%s",username);
    gotoxy(60,18);
    printf("Enter password:\t");
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
        putch('*');
        password[i] = ch;
        i++;
        }
    }
    password[i]='\0';
    if(strcmp(username,user)==0 && strcmp(password,pass1)==0)
    {
        system("cls");
        gotoxy(60,10);
        printf("WELCOME!");
        gotoxy(60,15);
        printf("PRESS ANY KEY TO CONTINUE....");
        getch();
        addquestions();
        return;
    }
    else
    {
        gotoxy(50,25);
        printf("Warning!! Incorrect Password! Try again...");
        getch();
        system("cls");
        login();
    }
}

void help()
{
    system("cls");
    gotoxy(70,4);
    printf("HELP");
    gotoxy(37,5);
    printf("---------------------------------------------------------------------");
    gotoxy(37,9);
    printf("............................ QUIZ GAME...............................");
    gotoxy(37,12);
    printf("1.   There will be 10 rounds each consisting of 10 questions.");
    gotoxy(37,13);
    printf("2.   Difficulty level and score will increase after every level");
    gotoxy(37,14);
    printf("3.   You will be given 4 options and you will have to press A,B,C or D");
    gotoxy(37,15);
    printf("     for the right option");
    gotoxy(37,16);
    printf("4.   After each right answer you will proceed to the next question and gain");
    gotoxy(37,17);
    printf("     scores accordingly");
    gotoxy(37,18);
    printf("5.   If you give a wrong answer you will get scores of the last level you");
    gotoxy(37,19);
    printf("     played successfully");
    gotoxy(37,20);
    printf("     And it will be GAME OVER.");
    gotoxy(37,21);
    printf("6.   No negative marking for wrong answers");
    gotoxy(37,22);
    printf("7.   You can see the highest scores in the HIGHEST SCORES section");
    gotoxy(37,23);
    printf("\t                       BEST OF LUCK\n");
    gotoxy(60,30);
    printf("Press any key to continue...");
    getch();
    return;

}

int menuhandler()
{
    int option=1;
    int i;
    char ch='\0';
    while(ch!=13)
    {
        system("cls");
        system("color 5F");
        gotoxy(55,8);
        for( i=0; i<10; i++)
        {
            printf("*");
        }
        printf(" MAIN MENU ");
        for( i=0; i<10; i++)
        {
            printf("*");
        }
        printf("\n\n\n");

        if(option==1)
            printf("\t\t\t\t\t\t\t==>\t1.START GAME\n\n");
        else
            printf("\t\t\t\t\t\t\t   \t1.Start game\n\n");
        if(option==2)
            printf("\t\t\t\t\t\t\t==>\t2.HIGHEST SCORES\n\n");
        else
            printf("\t\t\t\t\t\t\t   \t2.Highest Scores\n\n");
        if(option==3)
            printf("\t\t\t\t\t\t\t==>\t3.GAME MASTER\n\n");
        else
            printf("\t\t\t\t\t\t\t   \t3.Game Master\n\n");
        if(option==4)
            printf("\t\t\t\t\t\t\t==>\t4.HELP\n\n");
        else
            printf("\t\t\t\t\t\t\t   \t4.Help\n\n");
        if(option==5)
            printf("\t\t\t\t\t\t\t==>\t5.EXIT\n\n");
        else
            printf("\t\t\t\t\t\t\t   \t5.Exit\n\n");
        fflush(stdin);
        ch=getch();
        if(ch==72)
            option--;
        if(ch==80)
            option++;

        if(option<1)
            option=MAX_OPTION1;
        if(option>5)
            option=1;

    }
    return option;
}


int main()
{
    system("cls");
    int i,choice,n=1,points=0;
    char ques[150]= {},add[3]= {},options[100]= {},ans,ch;
    system("color 5E");
    gotoxy(50,17);
        for( i=0; i<10; i++)
        {
            printf("*");
        }
        printf(" WELCOME TO KBC 2.0 ");
        for( i=0; i<10; i++)
        {
            printf("*");
        }
    printf("\n\n\n\t\t\t\t\t\t\t");
    printf("PRESS ANY KEY TO CONTINUE....");
    getch();
    while(1)
    {
        choice=menuhandler();
        if(choice==1)
        {
            startgame();
        }
        else if(choice==2)
        {
            system("cls");
            hscore();
        }
        else if(choice==3)
        {
            system("cls");
            login();
        }
        else if(choice==4)
        {
            //system("cls");
            help();
        }
        else
            exit(0);

    }
    getch();
    return 0;
}



