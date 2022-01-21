#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	char name[100];
	struct node* lchild, * rchild;
}btnode, * btree;

btree stack[100];

void inorder(btree t) {
	if (t != NULL) {
		printf("%s\n", t->name);
		inorder(t->lchild);
		inorder(t->rchild);
	}
	return;
}

int main(void) {
	int n, i, j, k, rear = -1, front = -1;
	char name1[100], name2[100], name3[100];
	btree root = NULL;

	FILE* fpin;
	fpin = fopen("E:\\in.txt", "r");

	fscanf(fpin, "%d", &n);

	while (n--) {
		fscanf(fpin,"%s %s %s", name1, name2, name3);
		if (root == NULL) {
			btree n, l, r;
			l = (btree)malloc(sizeof(btnode)); strcpy(l->name, name2);
			r = (btree)malloc(sizeof(btnode)); strcpy(r->name, name3);
			n = (btree)malloc(sizeof(btnode)); strcpy(n->name, name1); n->lchild = l; n->rchild = r;
			root = n;
			stack[++rear] = root;
		}
		else {
			while (strcmp(stack[front + 1]->name, name1) != 0 && front != rear) {
				front++;
			}
			btree l, r;
			l = (btree)malloc(sizeof(btnode)); strcpy(l->name, name2);
			r = (btree)malloc(sizeof(btnode)); strcpy(r->name, name3);
			stack[front + 1]->lchild = l; stack[front + 1]->rchild = r;
			stack[++rear] = l; stack[++rear] = r;
			front++;
		}
	}

	inorder(root);

	return 0;
}

