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

float S(float u, float t)
{
	float g = 9.8;
	return (u*t + 0.5*g*t*t);
}

int main ()
{
	float x = 20, y, t, v, sign = 1, fps = 120, dt = 0.01, h = 25, restituition = 0.8, g = 9.8;
	char ball = 'o';
	
	h = 30-h;
	system("cls");
	gotoxy(x, h);
	printf("'");
	putchar(ball);
	printf("' press any key to continue");
	set_cursor(0);
	getch();
	while(h>0)
	{
		t = 0;
		v = 0;
		y = h;
		while(y<30)
		{
			v += g*t;
			y += S(v, t);
			t += dt;
			system("cls");
			gotoxy(x, y);
			putchar(ball);
			set_cursor(0);
			Sleep(1000/fps);
		}
		t = 0;
		v *= restituition;
		while(v > 0)
		{
			v -= g*t;
			y -= S(v, t);
			t += dt;
			system("cls");
			gotoxy(x, y);
			putchar(ball);
			set_cursor(0);
			Sleep(1000/fps);
		}
		h = y;
	}
	return 0;
}
