#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *lchild, *rchild;
}BTNode, *BTREE;

BTREE INSERTBST(BTREE T, int item) {
	BTREE p, q;
	p = (BTREE)malloc(sizeof(BTNode));
	p->data = item;
	p->lchild = NULL;
	p->rchild = NULL;
	if (T == NULL)
		T = p;
	else {
		q = T;
		while (1) {
			if (item < q->data) {
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
	return T;
}

//求叶节点所在的层次
void LEAVEBT(BTREE T) {
	BTREE STACK1[100], p = T;
	int STACK2[100], flag, top = -1;
	if (T != NULL) {
		do {
			while (p != NULL) {
				STACK1[++top] = p;
				STACK2[top] = 0;
				p = p->lchild;
			}
			p = STACK1[top];
			flag = STACK2[top--];
			if (flag == 0) {
				STACK1[++top] = p;
				STACK2[top] = 1;
				p = p->rchild;
			}
			else {
				if (p->lchild == NULL && p->rchild == NULL)
					printf("%d %d\n", p->data, top + 2);
				p = NULL;
			}
		} while (!(p == NULL && top == -1));
	}
}

int main(void) {
	BTREE tree=NULL;
	int n, temp;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &temp);
		tree=INSERTBST(tree, temp);
	}
	LEAVEBT(tree);	//输出所有叶节点 
	return 0;
}
