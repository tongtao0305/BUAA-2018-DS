#include<stdio.h>
#include<string.h>

//定义结构来保存操作
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
	//记录之前的操作 
	for (i = 0; i < top1; i++) {
		scanf("%d %d %s", &operation[i].type, &operation[i].pos, operation[i].str);
		operation[i].n = strlen(operation[i].str);	//记录操作的字符串的长度
	}
	top1--;


	while (1) {
		scanf("%d", &type);

		switch (type) {
			case -1:
				printf("%s", string);
				return 0;	//退出程序
			case 1:
				//读取插入位置以及插入的字符串
				scanf("%d %s", &pos, str);

				//记录该次操作
				operation[++top1].type = 1;
				operation[top1].pos = pos;
				strcpy(operation[top1].str,str);
				operation[top1].n = strlen(str);
				
				//进行操作
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
				//读取删除位置以及删除的长度
				scanf("%d %d", &pos, &n);

				//记录该次操作
				operation[++top1].type = 2;
				operation[top1].pos = pos;
				operation[top1].n = n;
				for (j = 0; j < n; j++) {
					operation[top1].str[j] = string[j+pos];
				}
				operation[top1].str[n] = '\0';
				
				//进行操作
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
				//如果没有可撤销的操作，则不操作 
				if (top1<0)
					break;
				
				switch (operation[top1].type) {
				case 1:
					pos = operation[top1].pos;
					n = operation[top1].n;

					//进行删除操作
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

					//进行插入操作
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
