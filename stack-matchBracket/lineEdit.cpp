#include"lineEdit.h"


char* line_edit(const char* p) {
	SStack s;
	InitializeStack(&s);
	char* r = (char*)malloc(600);
	memset(r, 0, 600);
	while (*p) {
		//如果*p不是#或者@，那么将内容放入栈中
		if (*p != '#'&&*p != '@') {
			push(&s, *p);
		}
		//如果*p是#号且栈不为空，就从栈中删除前一个字符
		if (*p == '#'&&!isEmpty(s)) {
			pop(&s);
		}
		//如果出现@,就将栈清空
		if (*p == '@') {
			while (!isEmpty(s)) {
				pop(&s);
			}
		}
		p++;
	}
	//将栈中内容存入字符数组中
	for (int i = 0; i < s.length; i++)  r[i] = s.base[i];
	r[s.length] = '\0';
	return r;
}