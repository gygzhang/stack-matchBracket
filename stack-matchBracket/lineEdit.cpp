#include"lineEdit.h"


char* line_edit(const char* p) {
	SStack s;
	InitializeStack(&s);
	char* r = (char*)malloc(600);
	memset(r, 0, 600);
	while (*p) {
		//���*p����#����@����ô�����ݷ���ջ��
		if (*p != '#'&&*p != '@') {
			push(&s, *p);
		}
		//���*p��#����ջ��Ϊ�գ��ʹ�ջ��ɾ��ǰһ���ַ�
		if (*p == '#'&&!isEmpty(s)) {
			pop(&s);
		}
		//�������@,�ͽ�ջ���
		if (*p == '@') {
			while (!isEmpty(s)) {
				pop(&s);
			}
		}
		p++;
	}
	//��ջ�����ݴ����ַ�������
	for (int i = 0; i < s.length; i++)  r[i] = s.base[i];
	r[s.length] = '\0';
	return r;
}