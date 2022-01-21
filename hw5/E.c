#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����������ڵ�Ľṹ 
typedef struct BTNODE {
	char c;
	int num, flag;
	struct BTNODE* lchild, * rchild;
}btnode, * btnodeptr;

//����һ������������huffman��
typedef struct NODE {
	btnodeptr treenode;
	struct NODE* link;
}node, * nodeptr;

nodeptr list = NULL;

nodeptr insertnode(int num, btnodeptr t) {
	//���½��Ķ�������㽨�������ڵ�������� 
	nodeptr new;
	new = (nodeptr)malloc(sizeof(node));
	new->treenode = t;
	new->link = NULL;
	if (list == NULL || t->num < list->treenode->num) {
		new->link = list;
		list = new;
	}
	else {
		nodeptr l = NULL, r = list;
		while (r != NULL && t->num >= r->treenode->num) {
			l = r;
			r = r->link;
		}
		/*
		for (r = list; t->num >= r->treenode->num && r != NULL; l = r, r = r->link)
			;
		*/

		l->link = new;
		new->link = r;
	}
	return list;
}



int main(void) {
	int i, j, k, count[150],count_total=-1,count_out,len,num_out;
	char temp, string[10000], word[150][100],total[1000],out[100];
	FILE* fpin, * fpout;

	//�����������ļ� 
	if ((fpin = fopen("input.txt", "rb")) == NULL) {
		printf("Can not open the input file."); return 1;
	}
	if ((fpout = fopen("output.txt", "wb")) == NULL) {
		printf("Can not open the output file."); return 1;
	}

	for (i = 0; i < 150; i++)
		count[i] = 0;
	count[0] = 1;

	
	while ((temp = fgetc(fpin)) != EOF) {
		if (temp == '\n')
			continue;
		else if (temp == '\0') {
			total[++count_total] = temp;
			break;
		}
		else {
			total[++count_total] = temp;
			count[temp]++;
		}
	}
	

	for (i = 0; i < 150; i++) {
		if (count[i] != 0) {
			//�����µĶ�������� 
			btnodeptr new_bt;
			new_bt = (btnodeptr)malloc(sizeof(btnode));
			new_bt->c = i;
			new_bt->lchild = NULL;
			new_bt->rchild = NULL;
			new_bt->num = count[i];
			new_bt->flag = -1;
			//������������������ 
			list=insertnode(count[i], new_bt);
		}
	}

	while (list->link != NULL) {
		//����������ǰ������������������Ϊ�����ӽڵ㽨��һ���µĶ�������� 
		btnodeptr new_bt;
		new_bt = (btnodeptr)malloc(sizeof(btnode));
		new_bt->c = -1;
		new_bt->flag = -1;
		new_bt->lchild = list->treenode; new_bt->lchild->flag = 0;
		new_bt->rchild = list->link->treenode; new_bt->rchild->flag = 1;
		new_bt->num = list->treenode->num + list->link->treenode->num;
		list = list->link->link;
		//������������������ 
		list=insertnode(new_bt->num, new_bt);
	}

	btnodeptr stack1[1000];
	int stack2[1000],flag,top;

	for (i = 0; i < 150; i++) {
		//��������ҵ���Ӧ���ַ��ڵ�
		if (count[i] != 0) {
			top = -1;
			btnodeptr temp = list->treenode;
			do {
				while (temp != NULL) {
					stack1[++top] = temp;
					stack2[top] = 0;
					temp = temp->lchild;
				}
				temp = stack1[top];
				flag = stack2[top--];
				if (flag == 0) {
					stack1[++top] = temp;
					stack2[top] = 1;
					temp = temp->rchild;
				}
				else {
					if (temp->c == i) {
						stack1[++top] = temp;
						break;
					}
					temp = NULL;
				}
			} while (!(temp == NULL && top == -1));
			
			//��ջ���ҳ���Ӧ������
			for (j = 1; j <= top ; j++) {
				//printf("%d", stack1[j]->flag);
				word[i][j - 1] = stack1[j]->flag + '0';
			}
			word[i][j-1] = '\0';
			//printf("\n");
		
			//printf("%d %s\n", i, word[i]);
		}
	}

		printf("%s\n",word['\0']);

	//������
	count_out = -1;
	for (i = 0; i <= count_total; i++) {
		len = strlen(word[total[i]]);
		for (j = 0; j < len; j++) {
			out[++count_out] = word[total[i]][j];
		}
		//����λ���
		while (count_out >= 7) {
			num_out = 0;
			for (j = 0; j <= 3; j++) {
				num_out = num_out * 2 + out[j] - '0';
				//fputc(out[j], fpout);
				fprintf(fpout,"%d",out[j]-'0');
			}
			printf("%x", num_out);
			num_out = 0;
			for (j = 4; j <= 7; j++) {
				num_out = num_out * 2 + out[j] - '0';
				//fputc(out[j], fpout);
				fprintf(fpout,"%d",out[j]-'0');
			}
			printf("%x", num_out);
			for (j = 8; j <= count_out; j++)
				out[j - 8] = out[j];
			count_out -= 8;
		}
	}

	len = strlen(word['\0']);
	for (j = 0; j < len; j++) {
		out[++count_out] = word['\0'][j];
	}
	

	while(count_out !=-1) {
		//����8λ��0����
		if (count_out < 7) {
			for (i = count_out + 1; i <= 7; i++)
				out[i] = '0';
			count_out = 7;
		}
			
		num_out = 0;
		for (j = 0; j <= 3; j++) {
			num_out = num_out * 2 + out[j] - '0';
			//fputc(out[j], fpout);
			fprintf(fpout,"%d",out[j]-'0');
		}
		printf("%x", num_out);
		num_out = 0;
		for (j = 4; j <= 7; j++) {
			num_out = num_out * 2 + out[j] - '0';
			//fputc(out[j], fpout);
			fprintf(fpout,"%d",out[j]-'0');
		}
		printf("%x", num_out);
		for (j = 8; j <= count_out; j++)
			out[j - 8] = out[j];
		count_out -= 8;
	}
		
	return 0;
}
