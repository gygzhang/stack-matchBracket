#include"stack.h"
#include"lineEdit.h"
#include"bracket_match.h"
#include<Windows.h>

int main() {
	SStack s;
	InitializeStack(&s);
	char p[500];
	//puts(line_edit("asdasdh@123#qqqsss"));
	//可以测试行编辑
	printf("行编辑测试\n");
	fgets(p, 2048, stdin);
	//去掉fgets()留存的回车
	newline_trim(p);
	printf("行编辑结果为：%s\n", line_edit(p));
	
	//可以测试括号匹配
	printf("\n\n括号匹配测试\n");
	fgets(p,2048,stdin);
	//去掉fgets()留存的回车
	newline_trim(p);
	if (bracket_match(p)) {
		puts(" 栈已空 匹配成功！\n");
	}
	else {
		puts("栈未空 匹配失败！：\n");
	}
	system("pause");
}