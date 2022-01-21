#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

//定义二叉树节点的结构 
typedef struct BTNODE {
	char c;
	int num, flag;
	struct BTNODE* lchild, * rchild;
}btnode, * btnodeptr;

//定义一个链表来建立huffman树
typedef struct NODE {
	btnodeptr treenode;
	struct NODE* link;
}node, * nodeptr;

nodeptr list = NULL;

nodeptr insertnode(int num, btnodeptr t) {
	//将新建的二叉树结点建立链表节点插入链表 
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
		l->link = new;
		new->link = r;
	}
	return list;
}



int main(void) {
	int i, j, k, n, c, count[150],count_total=-1,count_out,len,num_out;
	char temp, string[10000], word[150][100],total[1000],out[100];
	FILE* fpin, * fpout;

	//打开输入和输出文件 
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
			//建立新的二叉树结点 
			btnodeptr new_bt;
			new_bt = (btnodeptr)malloc(sizeof(btnode));
			new_bt->c = i;
			new_bt->lchild = NULL;
			new_bt->rchild = NULL;
			new_bt->num = count[i];
			new_bt->flag = -1;
			//将二叉树结点插入链表 
			list=insertnode(count[i], new_bt);
		}
	}

	while (list->link != NULL) {
		//将链表中最前面的两个二叉树结点作为左右子节点建立一个新的二叉树结点 
		btnodeptr new_bt;
		new_bt = (btnodeptr)malloc(sizeof(btnode));
		new_bt->c = -1;
		new_bt->flag = -1;
		new_bt->lchild = list->treenode; new_bt->lchild->flag = 0;
		new_bt->rchild = list->link->treenode; new_bt->rchild->flag = 1;
		new_bt->num = list->treenode->num + list->link->treenode->num;
		list = list->link->link;
		//将二叉树结点插入链表 
		list=insertnode(new_bt->num, new_bt);
	}

	btnodeptr stack1[1000];
	int stack2[1000],flag,top;

	for (i = 0; i < 150; i++) {
		//后序遍历找到对应的字符节点
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
			
			//从栈中找出对应的密码
			for (j = 1; j <= top ; j++) {
				//printf("%d", stack1[j]->flag);
				word[i][j - 1] = stack1[j]->flag + '0';
			}
			word[i][j-1] = '\0';
			//printf("\n");
			//printf("%d %s\n", i, word[i]);
		}
	}
	
	char code[100000],hmp[10];
	
	for (i=0;i<=count_total;i++){
		if (i==0)
			strcpy(code,word[total[i]]);
		else
			strcat(code,word[total[i]]);
	}
	strcat(code,word['\0']);
	
	n=j=strlen(code);
	j=8-j%8;
	if(j!=8) for(;j>0;j--) code[n++]='0';
	
	memset(hmp,0,sizeof(hmp));
	for(j=0;code[j];j){
		for(i=0;i<8;i++) hmp[i]=code[j++];
		c=0;
		for(i=0;i<8;i++) c=(c<<1)+hmp[i]-'0';
		printf("%x",c);
		putc(c,fpout);
	}

	return 0;
}
