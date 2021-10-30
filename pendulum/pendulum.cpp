#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<windows.h>

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void set_cursor(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

float f(float t)
{
	float g = 9.8, l = 15, c = -1.24;
	return (c*(sin(sqrt(g/l)*t)));
}

int main ()
{
	float x, y, t = 0, sign = 1, fps = 60, l = 15;
	char bob = 'o';
	while(!kbhit())
	{
		Sleep(1000/fps);
		system("cls");
		x = 60 + (l*(sin(f(t))));
		y = 5 + (l*(cos(f(t))));
		gotoxy(x,y);
		putchar(bob);
		set_cursor(0);
	    t = t + 0.5;
	}
	return 0;
}
