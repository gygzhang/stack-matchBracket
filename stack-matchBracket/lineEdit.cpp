#include"lineEdit.h"


char* line_edit(char* p) {
	SStack s;
	InitializeStack(&s);
	while (*p) {
		if (*p == '#'&&isEmpty(s)) {
			pop(&s);
		}
		if (*p != '#'&&*p != '@') {
			push(&s,*p);
		}
		if (*p == '@') {
			while (!isEmpty(s)) {
				pop(&s);
			}
		}
	}
	print_stack(s);
	return NULL;
}