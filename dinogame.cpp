#include <stdio.h>
#include<string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void gotoxy(int a, int b)
{
 COORD coordinate;
 coordinate.X = a;
 coordinate.Y = b;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
} 
void delay(int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void getup()
{
    printf("\n\nPress E to Exit, Press Space to Jump");
    gotoxy(51,2);
    printf("           SCORE : ");
    gotoxy(1,62);
}
 
int t,speed=50;
void jp(int jump=0)
{
    static int a=1;
 
    if(jump==0)
        t=0;
    else if(jump==2)
        t--;
    else t++;
    gotoxy(1,15-t);
    printf("                 ");
    gotoxy(1,16-t);
    printf("         @@@@@@@@");
    gotoxy(1,17-t);
    printf("         @@@@@@@@");
    gotoxy(1,18-t);
    printf("         @@@@@@");
    gotoxy(1,19-t);
    printf(" @      @@@@@@@@ ");
    gotoxy(1,20-t);
    printf(" @@@  @@@@@@@@@@ ");
    gotoxy(1,21-t);
    printf(" @@@@@@@@@@@@   ");
    gotoxy(1,22-t);
    printf("   @@@@@@@@@     ");
    gotoxy(1,23-t);
    if(jump==1 || jump==2){
    printf("    @@@ @@       ");
    gotoxy(1,24-t);
    printf("    @@   @@      ");
    }else if(a==1)
    {
    printf("    @@@@  @@@    ");
    gotoxy(1,24-t);
    printf("      @@         ");
    a=2;
    }
    else if(a==2)
    {
    printf("     @@@ @@      ");
    gotoxy(1,24-t);
    printf("          @@     ");
    a=1;
    }
    gotoxy(1,25-t);
    if(jump!=0){
        printf("                ");
    }
    else;
    {
         
    }
    delay(speed);
}
void object()
{
    static int x=0,scr=0;
    if(x==56 && t<4)
    {
    scr=0;
    speed=40;
    gotoxy(36,8);
    printf("GAMEOVER");
    getch();
    gotoxy(36,8);
    printf("        ");
    }
    gotoxy(74-x,20);
    printf("^^ ");
    gotoxy(74-x,21);
    printf("|| ");
    gotoxy(74-x,22);
    printf("** ");
    gotoxy(74-x,23);
    printf("|| ");
    gotoxy(74-x,24);
    printf("-- " );
    x++;
    if(x==73)
    {
    x=0;
    scr++;
    gotoxy(70,2);
    printf("     ");
    gotoxy(70,2);
    printf("%d",scr);
    if(speed>20)
        speed--;
    }
}
int main()
{
    system("mode con: lines=29 cols=82");
    char ch;
    int i,enter=0,count=0;
	char space,x; char name[20];
	printf("\n\n\n\n\n\n\t\t\t\t\t==========================================\n\t\t\t\t");
	printf("\n\t\t\t\t\t\tWELCOME TO THE T-REX GAME\n\n\t\t\t\t\t    Presented By Group of Aftab,Arif,jaideep \n\t\t\t\n");
	printf("\n\t\t\t\t\t==========================================\n\t\t\t\t");
	printf("\n\t\t\t\t\t\tTo Continue Press Any Key:\n\n\n");
	getch();
	system("CLS");
	printf("\nContinue By Entering Your Name:");
	gets(name);
	printf("Hello %s! Hope You Would Be Doing Well.\nYou Are Warmly Welcomed Here Lets Play The Game\n",name);
	printf("Press Enter Button When You Are Ready");
	scanf("%c",&space);
    system("CLS");
	getup();
    while(1)
    {	
		hidecursor();
        while(!kbhit())
        {
            jp();
            object();
        }
        ch=getch();
        if(ch==' ')
        {
            for(i=0;i<10;i++)
            {
            jp(1);
            object();
            }
            for(i=0;i<10;i++)
            {
            jp(2);
            object();
            }
        }
        else if (ch=='e')
            exit(1);
    } 
}

