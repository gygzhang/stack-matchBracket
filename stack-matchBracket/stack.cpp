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
		s->top = s->base + s->size;
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

//重载函数
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


//去掉fgets()中保留的回车
void newline_trim(char* p) {
	while (*p != '\n') p++;
	*p = '\0';
}