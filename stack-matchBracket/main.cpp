#include"stack.h"
#include"lineEdit.h"
#include<Windows.h>

int main() {
	SStack s;
	InitializeStack(&s);
	char p[500];
	//puts(line_edit("123#qqqsss"));
	//���Բ����б༭
	printf("%s\n", line_edit("##@123q@qqsssss111s#111##333"));
	
	//���Բ�������ƥ��
	/*fgets(p,2048,stdin);
	//ȥ��fgets()����Ļس�
	bracket_trim(p);
	if (bracket_match(p)) {
		puts("ƥ��ɹ��� ջ�ѿ�\n");
	}
	else {
		puts("ƥ��ʧ�ܣ�ջδ�գ�");
	}*/
	system("pause");
}