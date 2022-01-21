#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//定义二叉树结构 
typedef struct tnode {
    char word[100];
    int count;
    struct tnode *lchild,*rchild;
}BTNode, *BTREE; 

BTREE insertNode(BTREE t,char s[100]) {
	BTREE p, q;
	p = (BTREE)malloc(sizeof(BTNode));
	strcpy(p->word,s);
	p->count=1;
	p->lchild = NULL;
	p->rchild = NULL;
	if (t == NULL)
		t = p;
	else {
		q = t;
		while (1) {
			if (strcmp(s,q->word)==0){
				q->count++;
				free(p);
				break;
			}
			else if (strcmp(s,q->word)<0) {
				if (q->lchild != NULL)
					q = q->lchild;
				else {
					q->lchild = p;
					break;
				}
			}
			else {
				if (q->rchild != NULL)
					q = q->rchild;
				else {
					q->rchild = p;
					break;
				}
			}
		}
	}
	return t;
}

//以递归方式中序遍历二叉树 
void INORDER(BTREE t){
	if (t!=NULL){
		INORDER(t->lchild);	
		printf("%s %d\n",t->word,t->count);
		INORDER(t->rchild);
	}
}

int main(void){
	int count=0;
	char c,temp[100]; 
	FILE *fin;
	BTREE root=NULL;
	
	//打开输入文件 
	if ((fin = fopen("article.txt", "r")) == NULL) {
		printf("Cannot open the file!\n");
		return 1;
	}
	
	//读取单词并插入树 
	while ((c = fgetc(fin)) != EOF){
		if (isalpha(c)) {
			if ('A'<=c&&c<='Z')
				temp[count++]=c-('A'-'a');
			else
				temp[count++] = c;
		}
		else if (count!=0){
			temp[count] = '\0';
			count = 0;
			root = insertNode(root, temp);
		}
	}	
	
	if (root!=NULL&&root->rchild==NULL)
		printf("%s\n",root->word);
	if (root!=NULL&&root->rchild!=NULL&&root->rchild->rchild==NULL)
		printf("%s %s\n",root->word,root->rchild->word);	
	if (root!=NULL&&root->rchild!=NULL&&root->rchild->rchild!=NULL)
		printf("%s %s %s\n",root->word,root->rchild->word,root->rchild->rchild->word);

	INORDER(root);
	
	return 0;
}
