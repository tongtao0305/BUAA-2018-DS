#include<stdio.h>
#include<string.h>

//����ṹ���������
struct Node {
	int type;
	int pos;
	char str[500];
	int n;
};
struct Node operation[100];


int main(void) {
	int former_count;
	int n, a, b, c, i, j, k, top = 0, count, num, pos,top1,type;
	char str[500],string[550],temp_string[550];

	fgets(string, BUFSIZ, stdin);

	scanf("%d", &top1);
	//��¼֮ǰ�Ĳ��� 
	for (i = 0; i < top1; i++) {
		scanf("%d %d %s", &operation[i].type, &operation[i].pos, operation[i].str);
		operation[i].n = strlen(operation[i].str);	//��¼�������ַ����ĳ���
	}
	top1--;


	while (1) {
		scanf("%d", &type);

		switch (type) {
			case -1:
				printf("%s", string);
				return 0;	//�˳�����
			case 1:
				//��ȡ����λ���Լ�������ַ���
				scanf("%d %s", &pos, str);

				//��¼�ôβ���
				operation[++top1].type = 1;
				operation[top1].pos = pos;
				strcpy(operation[top1].str,str);
				operation[top1].n = strlen(str);
				
				//���в���
				for (i = 0; i < pos; i++)
					temp_string[i] = string[i];
				for (i = 0; i < strlen(str); i++)
					temp_string[i + pos] = str[i];
				for (i = pos; i < strlen(string); i++)
					temp_string[strlen(str) + i] = string[i];
				temp_string[strlen(string) + strlen(str)] = '\0';
				strcpy(string, temp_string);
				//printf("%s\n", string);

				break;
			case 2:
				//��ȡɾ��λ���Լ�ɾ���ĳ���
				scanf("%d %d", &pos, &n);

				//��¼�ôβ���
				operation[++top1].type = 2;
				operation[top1].pos = pos;
				operation[top1].n = n;
				for (j = 0; j < n; j++) {
					operation[top1].str[j] = string[j+pos];
				}
				operation[top1].str[n] = '\0';
				
				//���в���
				if (pos + n >= strlen(string)) {
					for (i = 0; i < pos; i++)
						temp_string[i] = string[i];
					temp_string[pos] = '\0';
				}
				else {
					for (i = 0; i < pos; i++)
						temp_string[i] = string[i];
					for (i = pos + n; i < strlen(string); i++)
						temp_string[i-n] = string[i];
					temp_string[strlen(string) - n] = '\0';
				}
				strcpy(string, temp_string);
				//printf("%s\n", string);
				break;
			case 3:
				//���û�пɳ����Ĳ������򲻲��� 
				if (top1<0)
					break;
				
				switch (operation[top1].type) {
				case 1:
					pos = operation[top1].pos;
					n = operation[top1].n;

					//����ɾ������
					if (pos + n >= strlen(string)) {
						for (i = 0; i < pos; i++)
							temp_string[i] = string[i];
						temp_string[pos] = '\0';
					}
					else {
						for (i = 0; i < pos; i++)
							temp_string[i] = string[i];
						for (i = pos + n; i < strlen(string); i++)
							temp_string[i - n] = string[i];
						temp_string[strlen(string) - n] = '\0';
					}
					strcpy(string, temp_string);
					//printf("%s\n", string);
					break;
				case 2:
					pos = operation[top1].pos;
					strcpy(str, operation[top1].str);

					//���в������
					for (i = 0; i < pos; i++)
						temp_string[i] = string[i];
					for (i = 0; i < strlen(str); i++)
						temp_string[i + pos] = str[i];
					for (i = pos; i < strlen(string); i++)
						temp_string[strlen(str) + i] = string[i];
					temp_string[strlen(string) + strlen(str)] = '\0';
					strcpy(string, temp_string);
					//printf("%s\n", string);
					break;
				}

				top1--;
				break;
	
			case 4:
				for (i=0;i<=top1;i++)
					printf("%d %d %s %d\n",operation[i].type,operation[i].pos,operation[i].str,operation[i].n);
			 	break;
		}
	}

	return 0;
}
