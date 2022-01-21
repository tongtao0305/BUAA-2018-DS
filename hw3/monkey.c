#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	int check;
	struct node *link;
};
typedef struct node Node;
typedef struct node* Nodeptr;

//����һ������n���ڵ��ѭ������ 
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

	//��������n������ѭ������ 
	list = createList(n);

	//Ѱ�ҵ�q����� 
	for (temp = list, q--; q > 0; q--)
		temp = temp->link;

	//��ʼn-1��ѭ�� 
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
