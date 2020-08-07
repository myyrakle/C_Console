#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

struct __Console;
extern struct __Console Console;

enum Color;
typedef enum Color Color;


//색
enum Color
{
	BLACK = 0, //검은색
	DARK_BLUE = 1, //어두운 파란색 
	DARK_GREEN = 2, //어두운 초록색
	DARK_CYAN = 3, //어두운 청록색
	DARK_RED = 4, //어두운 빨강
	DARK_MAGENTA = 5, //어두운 자홍색
	DARK_YELLOW = 6, //어두운 노란색
	GRAY = 7, //회색
	DARK_GRAY = 8, //어두운 회색
	BLUE = 9, //파란색
	GREEN = 10, //초록색
	CYAN = 11, //청록색
	RED = 12, //빨간색
	MAGENTA = 13, //자홍색
	YELLOW = 14, //노란색
	WHITE = 15, //하얀색
	TextDefault = 7, //텍스트 색 디폴트
	BackgroundDefault = 0 //백그라운드 색 디폴트
};


struct __Console
{
	void(*Write)(const char*); //그냥 씀	
	void(*WriteLine)(const char*); //쓰고 개행
	void(*WriteFormat)(const char*, ...); //printf임

	void(*FlushOut)(); //출력버퍼 비움

	int(*Read)(); //한 글자 읽어옴
	void(*ReadLine)(char*, size_t); //한줄 읽어옴
	void(*ReadFormat)(const char*, ...); //scanf임

	void(*FlushIn)(); //입력버퍼 비움

	const int __color; //멤버변수니까 건들지 마시오
	void(*SetTextColor)(Color); //텍스트 색상 설정
	Color(*GetTextColor)(); //텍스트 색상 획득
	void(*SetBackgroundColor)(Color); //백그라운드 색상 설정
	Color(*GetBackgroundColor)(); //백그라운드 색상 획득
	void(*ResetColor)();

	void(*Clear)(); //콘솔 청소
	void(*Pause)(); //콘솔 대기
	void(*Exit)(); //콘솔 종료
};

