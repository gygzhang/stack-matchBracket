#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define S_size 200
#define S_incr 50
#define ERROR 0
#define OVERFLOW 1
#define OK 2

typedef char ch;
typedef int status;
typedef char elem;

typedef struct {
	elem* base;
	elem* top;
	int size;
	int length;
}SStack;

status InitializeStack(SStack* s);

status push(SStack* s, elem e);

status pop(SStack* s, elem* e);

elem pop(SStack* s);

status get_top(SStack s, elem* e);

elem get_top(SStack s);

bool isEmpty(SStack s);

status destroy_stack(SStack s);

int stack_length(SStack s);

status print_stack(SStack s);
//输入的括号字符串是否匹配
bool bracket_match(const char* p);
//判断a,b是否为一对括号
bool is_match(char, char);

void bracket_trim(char* p);