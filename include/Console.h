#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

struct __Console;
extern struct __Console Console;

enum Color;
typedef enum Color Color;


//��
enum Color
{
	BLACK = 0, //������
	DARK_BLUE = 1, //��ο� �Ķ��� 
	DARK_GREEN = 2, //��ο� �ʷϻ�
	DARK_CYAN = 3, //��ο� û�ϻ�
	DARK_RED = 4, //��ο� ����
	DARK_MAGENTA = 5, //��ο� ��ȫ��
	DARK_YELLOW = 6, //��ο� �����
	GRAY = 7, //ȸ��
	DARK_GRAY = 8, //��ο� ȸ��
	BLUE = 9, //�Ķ���
	GREEN = 10, //�ʷϻ�
	CYAN = 11, //û�ϻ�
	RED = 12, //������
	MAGENTA = 13, //��ȫ��
	YELLOW = 14, //�����
	WHITE = 15, //�Ͼ��
	TextDefault = 7, //�ؽ�Ʈ �� ����Ʈ
	BackgroundDefault = 0 //��׶��� �� ����Ʈ
};


struct __Console
{
	void(*Write)(const char*); //�׳� ��	
	void(*WriteLine)(const char*); //���� ����
	void(*WriteFormat)(const char*, ...); //printf��

	void(*FlushOut)(); //��¹��� ���

	int(*Read)(); //�� ���� �о��
	void(*ReadLine)(char*, size_t); //���� �о��
	void(*ReadFormat)(const char*, ...); //scanf��

	void(*FlushIn)(); //�Է¹��� ���

	const int __color; //��������ϱ� �ǵ��� ���ÿ�
	void(*SetTextColor)(Color); //�ؽ�Ʈ ���� ����
	Color(*GetTextColor)(); //�ؽ�Ʈ ���� ȹ��
	void(*SetBackgroundColor)(Color); //��׶��� ���� ����
	Color(*GetBackgroundColor)(); //��׶��� ���� ȹ��
	void(*ResetColor)();

	void(*Clear)(); //�ܼ� û��
	void(*Pause)(); //�ܼ� �밡
	void(*Exit)(); //�ܼ� ����
};

