#include<stdio.h>

//������¼�沨�����ʽ�İ����������ֺ�һ���ж����Ľṹ 
struct string_data {
	int type;	//0Ϊ����,1Ϊ����
	int num;
	char sign;
};

//���������ȡ�Ķ�ȡ�ķ����Լ����ȼ��Ķ�ջ�Ľṹ 
struct stack_data {
	int priority;
	char sign;
};


int main(void) {
	int i = 0, j, k, top = -1, count = -1,num[100];
	char string_in[1000];
	struct stack_data stack[1000];
	struct string_data temp, string_out[1000];

	temp.num = 0;

	fgets(string_in, BUFSIZ, stdin);	//��ȡ�������ʽ���ұ�����string_in�ַ������� 

	do {
		if (string_in[i] == ' ') {
			continue;	//��ȡ���ո������ 
		}
		else if ('0' <= string_in[i] && string_in[i] <= '9') {
			//��ȡ�����ַ�Ϊ���� 
			temp.type = 1;
			temp.num = temp.num * 10 + string_in[i] - '0';
		}
		else {
			//��ȡ�����ַ�Ϊ����
			if (temp.type == 1) {
				string_out[++count].num = temp.num;
				string_out[count].type = 1;
				temp.num = 0;
				temp.type = 0;
			}
			//�Զ�ջ�еķ������ȼ������ж�
			if (string_in[i] == '(') {
				stack[++top].priority = 0;
				stack[top].sign = string_in[i];
			}
			else if (string_in[i] == ')') {
				while (stack[top].sign != '(') {
					string_out[++count].type = 0;
					string_out[count].sign = stack[top--].sign;
				}
				top--;
			}
			else if (string_in[i] == '*' || string_in[i] == '/' || string_in[i] == '%') {
				//�˳�ȡ�� 
				while (stack[top].priority == 1 && top>=0 ) {
					//��������ֱ�����ȼ����͵ķ��� 
					string_out[++count].type = 0;
					string_out[count].sign = stack[top--].sign;
				}
				stack[++top].priority = 1;
				stack[top].sign = string_in[i];
			}
			else if (string_in[i] == '+' || string_in[i] == '-') {
				//�Ӽ� 
				while ((stack[top].priority == 1 || stack[top].priority == 2)&& top>=0 ) {
					//��������ֱ�����ȼ����͵ķ��� 
					string_out[++count].type = 0;
					string_out[count].sign = stack[top--].sign;
				}

				stack[++top].priority = 2;
				stack[top].sign = string_in[i];
			}
		}
	} while (string_in[i++] != '=');

	while (top >= 0) {
		string_out[++count].type = 0;
		string_out[count].sign = stack[top--].sign;
	}
	
	/*
	for (i = 0; i <= count; i++) {
		switch (string_out[i].type) {
		case 0:printf("%c ", string_out[i].sign); break;
		case 1:printf("%d ", string_out[i].num); break;
		}
	}
	printf("\n");
	*/

	top = -1;
	for (i = 0; i <= count; i++) {
		if (string_out[i].type == 1) {
			num[++top] = string_out[i].num;
		}
		else {
			switch (string_out[i].sign) {
			case '+':
				num[top - 1] = num[top - 1] + num[top];
				top--;
				break;
			case '-':
				num[top - 1] = num[top - 1] - num[top];
				top--;
				break;
			case '*':
				num[top - 1] = num[top - 1] * num[top];
				top--;
				break;
			case '/':
				num[top - 1] = num[top - 1] / num[top];
				top--;
				break;
			case '%':
				num[top - 1] = num[top - 1] % num[top];
				top--;
				break;
			}
		}
	}

	printf("%d", num[top]);

	return 0;
}
