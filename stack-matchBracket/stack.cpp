#include"stack.h"

status InitializeStack(SStack* s){
	s->base = (elem*)malloc(S_size * sizeof elem);
	//malloc失败返回null
	if (!s->base) exit(OVERFLOW);

	s->top = s->base;
	s->size = S_size;
	s->length = 0;
	return	OK;
}

status push(SStack* s, elem e) {
	if (s->top - s->base >= s->size) {
		s->base = (elem*)realloc(s,s->size + S_incr);
		if (!s->base) exit(OVERFLOW);
		//s->top = s->base + s->size;
		s->size += S_incr;
	}
	*s->top++ = e;
	s->length++;
	return OK;
}

status pop(SStack* s, elem* e) {
	*e = *--s->top;
	s->length--;
	return OK;
}

elem pop(SStack* s) {
	s->length--;
	return *--s->top;
}

status get_top(SStack s, elem* e) {
	*e = *(s.top-1);
	return OK;
}

elem get_top(SStack s) {
	if (isEmpty(s)) return 0;
	return *(s.top-1);
}

bool isEmpty(SStack s) {
	return s.length == 0 ? true : false;
}

status destroy_stack(SStack s) {
	free(s.base);
	return OK;
}

int stack_length(SStack s) {
	return s.length;
}

status print_stack(SStack s) {
	for (int i = 0; i < s.length; i++) {
		printf("%c ", s.base[i]);
	}
	return OK;
}

bool bracket_match(const char* p) {
	SStack s;
	InitializeStack(&s);
	//如果以右括号开始，判定为不匹配
	if (*p == ')' || *p == ']' || *p == '}') return false;
	//如果是奇数个字符串，判定为不匹配
	if (strlen(p) % 2 == 1) return false;
	//判断字符串结尾
	while (*p!= '\0') {
		//如果*p是右括号，且和栈顶元素不匹配，则将*p 入栈
		//print_stack(s);
		
		if (*p == '(' || *p == '{' || *p == '['&&!is_match(*p,get_top(s)))  push(&s, *p);
		//如果*p和s的栈顶元素匹配，则将s的栈顶元素弹出
		if (is_match(*p, get_top(s)))  pop(&s);	
		p++;
	}
	//返回栈是否为空，如果为空，则匹配成功，否则失败
	return isEmpty(s);
}

bool is_match(char a, char b) {
	return (
		   (a == '('&&b == ')' || a == ')'&&b == '(')
		|| (a == '['&&b == ']' || a == ']'&&b == '[')
		|| (a == '{'&&b == '}' || a == '}'&&b == '{')
		);	
}
//去掉fgets()中保留的回车
void bracket_trim(char* p) {
	while (*p != '\n') p++;
	*p = '\0';
}