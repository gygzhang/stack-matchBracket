#include"bracket_match.h"
#include"stack.h"

bool bracket_match(const char* p) {
	SStack s;
	InitializeStack(&s);
	//如果以右括号开始，判定为不匹配
	if (*p == ')' || *p == ']' || *p == '}') return false;
	//如果是奇数个字符串，判定为不匹配
	if (strlen(p) % 2 == 1) return false;
	//判断字符串结尾
	while (*p != '\0') {
		//如果*p是右括号，且和栈顶元素不匹配，则将*p 入栈
		//print_stack(s);

		if (*p == '(' || *p == '{' || *p == '[' && !is_match(*p, get_top(s)))  push(&s, *p);
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