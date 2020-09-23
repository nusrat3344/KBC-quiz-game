#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

#define MAX_OPTION 3
#define MAX_OPTION1 5
char pass1[11]={"GAMEMASTER"};
char user[11]={"gamemaster"};
COORD c={0,0};
void gotoxy(int x, int y)
{
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void login()
{
    char username[50]={},password[25]={};
    char ch;
    int i=0,j;
    gotoxy(5,5);
    for(int i=0;i<10;i++)
    {
    printf("*");
    }
    printf("PASSWORD PROTECTED");
    for(int i=0;i<10;i++)
    {
    printf("*");
    }
    gotoxy(10,7);
    printf("Enter username:\t");
    scanf("%s",username);
    gotoxy(10,9);
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
        gotoxy(10,7);
        printf("WELCOME!");
        gotoxy(10,9);
        printf("PRESS ANY KEY TO CONTINUE....");
        getch();
        return;
    }
    else
    {
        gotoxy(10,11);
        printf("Warning!! Incorrect Password! Try again...");
        getch();
        system("cls");
        login();
    }
}

int menuhandler()
{
    int option=1;
    char ch='\0';
    while(ch!=13)
    {
        system("cls");
    gotoxy(2,2);
    for(int i=0;i<10;i++)
    {
    printf("*");
    }
    printf("WELCOME TO THE GAME!");
    for(int i=0;i<10;i++)
    {
    printf("*");
    }
    gotoxy(4,4);

        if(option==1)
            printf("\t==>\t1.START GAME\n");
        else
            printf("\t   \t1.Start game\n");
        if(option==2)
            printf("\t==>\t2.HIGHEST SCORES\n");
        else
            printf("\t   \t2.Highest Scores\n");
        if(option==3)
            printf("\t==>\t3.GAME MASTER\n");
        else
            printf("\t   \t3.Game Master\n");
        if(option==4)
            printf("\t==>\t4.HELP\n");
        else
            printf("\t   \t4.Help\n");
        if(option==5)
            printf("\t==>\t5.EXIT\n");
        else
            printf("\t   \t5.Exit\n");
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
    int i,choice;
    while(1)
    {
        choice=menuhandler();
        if(choice==1)
            {
                system("cls");
                //start=addcontacts(start);
            }
        else if(choice==2)
        {
          system("cls");
          //printallcontacts(start);
          //getch();
        }
        else if(choice==3)
        {
          system("cls");
          login();
        }
        else if(choice==4)
        {
          system("cls");
          //start=delete(start);
        }
        else
            exit(1);

    }
//printf("This is the changed cursor position.");
getch();
return 0;
}
