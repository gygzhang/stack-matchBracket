#include"stack.h"
#include"lineEdit.h"
#include"bracket_match.h"
#include<Windows.h>

int main() {
	SStack s;
	InitializeStack(&s);
	char p[500];
	//puts(line_edit("asdasdh@123#qqqsss"));
	//���Բ����б༭
	printf("�б༭����\n");
	fgets(p, 2048, stdin);
	//ȥ��fgets()����Ļس�
	newline_trim(p);
	printf("�б༭���Ϊ��%s\n", line_edit(p));
	
	//���Բ�������ƥ��
	printf("\n\n����ƥ�����\n");
	fgets(p,2048,stdin);
	//ȥ��fgets()����Ļس�
	newline_trim(p);
	if (bracket_match(p)) {
		puts(" ջ�ѿ� ƥ��ɹ���\n");
	}
	else {
		puts("ջδ�� ƥ��ʧ�ܣ���\n");
	}
	system("pause");
}