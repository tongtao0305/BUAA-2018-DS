#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	int check;
	struct node *link;
};
typedef struct node Node;
typedef struct node* Nodeptr;

//创建一个具有n个节点的循环链表 
Nodeptr createList(int n) {
	Nodeptr p, q, list = NULL;
	int i;
	for (i = 1; i <= n; i++) {
		q = (Nodeptr)malloc(sizeof(Node));
		q->data = i;
		q->check = 1;
		q->link = list;
		if (list == NULL)
			list = p = q;
		else
			p->link = q;
		p = q;
	}
	return list;
}

int main(void) {
	int n, m, q, i, j, k;
	Nodeptr list = NULL, temp = NULL;

	scanf("%d %d %d", &n, &m, &q);

	//创建含有n个结点的循环链表 
	list = createList(n);

	//寻找第q个结点 
	for (temp = list, q--; q > 0; q--)
		temp = temp->link;

	//开始n-1次循环 
	for (i = 1; i <= n - 1; i++) {
		j = m;
		while (j > 0) {
			if (temp->check == 1) {
				if (j == 1) {
					temp->check = 0;
				}
				j--;
			}
			temp = temp->link;
		}
	}

	for (temp = list;; temp = temp->link) {
		if (temp->check == 1) {
			printf("%d", temp->data);
			break;
		}
	}

	return 0;
}
