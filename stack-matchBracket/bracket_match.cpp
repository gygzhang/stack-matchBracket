#include"bracket_match.h"
#include"stack.h"

bool bracket_match(const char* p) {
	SStack s;
	InitializeStack(&s);
	//����������ſ�ʼ���ж�Ϊ��ƥ��
	if (*p == ')' || *p == ']' || *p == '}') return false;
	//������������ַ������ж�Ϊ��ƥ��
	if (strlen(p) % 2 == 1) return false;
	//�ж��ַ�����β
	while (*p != '\0') {
		//���*p�������ţ��Һ�ջ��Ԫ�ز�ƥ�䣬��*p ��ջ
		//print_stack(s);

		if (*p == '(' || *p == '{' || *p == '[' && !is_match(*p, get_top(s)))  push(&s, *p);
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