#include"stack.h"

status InitializeStack(SStack* s){
	s->base = (elem*)malloc(S_size * sizeof elem);
	//mallocʧ�ܷ���null
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
	//����������ſ�ʼ���ж�Ϊ��ƥ��
	if (*p == ')' || *p == ']' || *p == '}') return false;
	//������������ַ������ж�Ϊ��ƥ��
	if (strlen(p) % 2 == 1) return false;
	//�ж��ַ�����β
	while (*p!= '\0') {
		//���*p�������ţ��Һ�ջ��Ԫ�ز�ƥ�䣬��*p ��ջ
		//print_stack(s);
		
		if (*p == '(' || *p == '{' || *p == '['&&!is_match(*p,get_top(s)))  push(&s, *p);
		//���*p��s��ջ��Ԫ��ƥ�䣬��s��ջ��Ԫ�ص���
		if (is_match(*p, get_top(s)))  pop(&s);	
		p++;
	}
	//����ջ�Ƿ�Ϊ�գ����Ϊ�գ���ƥ��ɹ�������ʧ��
	return isEmpty(s);
}

bool is_match(char a, char b) {
	return (
		   (a == '('&&b == ')' || a == ')'&&b == '(')
		|| (a == '['&&b == ']' || a == ']'&&b == '[')
		|| (a == '{'&&b == '}' || a == '}'&&b == '{')
		);	
}
//ȥ��fgets()�б����Ļس�
void bracket_trim(char* p) {
	while (*p != '\n') p++;
	*p = '\0';
}