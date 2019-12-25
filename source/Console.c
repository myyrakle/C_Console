#include "Console.h"

void __Console_Write(const char*);
void __Console_WriteLine(const char*);
//void __Console_WriteFormat(const char*, ...);

void __Console_FlushOut();

//int __Console_Read(const char*);
void __Console_ReadLine(char*, size_t);
//void(*ReadFormat)(const char*, ...);

void __Console_FlushIn();

void __Console_SetTextColor(Color);
Color __Console_GetTextColor();
void __Console_SetBackgroundColor(Color);
Color __Console_GetBackgroundColor();
void __Console_ResetColor();

void __Console_Clear();
void __Console_Pause();
void __Console_Exit();

struct __Console Console = {
   .__color = BLACK,

   .Write = __Console_Write,
   .WriteLine = __Console_WriteLine,
   .WriteFormat = printf,

   .FlushOut = __Console_FlushOut,

   .Read = getchar,
   .ReadLine = __Console_ReadLine,
   .ReadFormat = scanf,

   .FlushIn = __Console_FlushIn,

   .SetTextColor = __Console_SetTextColor,
   .GetTextColor = __Console_GetTextColor,
   .SetBackgroundColor = __Console_SetBackgroundColor,
   .GetBackgroundColor = __Console_SetBackgroundColor,
   .ResetColor = __Console_ResetColor,

   .Clear = __Console_Clear,
   .Pause = __Console_Pause,
   .Exit = __Console_Exit
};

void __Console_Write(const char* text)
{
	printf(text);
}

void __Console_WriteLine(const char* text)
{
	__Console_Write(text);
	putchar('\n');
}

void __Console_FlushOut()
{
	fflush(stdout);
}

void __Console_ReadLine(char* buffer, size_t max)
{
	fgets(buffer, max, stdin);
}

void __Console_FlushIn()
{
	int c;
	while( 
		(c = getchar()) != '\n' 
		&& 
		c != EOF 
	);
}

void __Console_SetTextColor(Color color)
{
	*(Color*)&Console.__color |= color & 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Console.__color);
}

Color __Console_GetTextColor()
{
	return Console.__color & 0xf;
}

void __Console_SetBackgroundColor(Color color)
{
	*(Color*)& Console.__color |= (color & 0xf) << 4;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Console.__color);
}

Color __Console_GetBackgroundColor()
{
	return (Console.__color & 0xff) >> 4;
}

void __Console_ResetColor()
{
	*(Color*)& Console.__color = TextDefault | (BackgroundDefault << 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Console.__color);
}

void __Console_Clear()
{
	system("cls");
}

void __Console_Pause()
{
	system("pause");
}

void __Console_Exit()
{
	system("exit");
}