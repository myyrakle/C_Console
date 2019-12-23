#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

//색
enum Color
{
	BLACK = 0,
	DARK_BLUE = 1,
	DARK_GREEN = 2,
	DARK_CYAN = 3,
	DARK_RED = 4,
	DARK_MAGENTA = 5,
	DARK_YELLOW = 6,
	GRAY = 7,
	DARK_GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	CYAN= 11,
	RED = 12,
	MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15,
	TextDefault = 7,
	BackgroundDefault = 0
};
typedef enum Color Color;

struct __Console
{
	int __color;
	
	void(*Write)(const char*);
	void(*WriteLine)(const char*);
	void(*WriteFormat)(const char*, ...);

	int(*Read)();
	void(*ReadLine)(char*, size_t);
	void(*ReadFormat)(const char*, ...);

	void(*SetTextColor)(Color);
	Color(*GetTextColor)();
	void(*SetBackgroundColor)(Color);
	Color(*GetBackgroundColor)();

	void(*Clear)();
	void(*Pause)();
	void(*Exit)();
};

extern struct __Console Console;
