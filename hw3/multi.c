#include <stdio.h>
#include<stdlib.h>

//定义链表 
struct node {
	int coefficient;
	int index;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;

//在链表中插入元素 
Nodeptr insertNode(Nodeptr list, int coefficient, int index) {
	Nodeptr p, q, r;
	p = (Nodeptr)malloc(sizeof(Node));
	p->coefficient = coefficient;
	p->index = index;
	if (list == NULL || index > list->index) {
		p->link = list;
		list = p;
	}
	else {
		q = list;
		while (q != NULL && index < q->index) {
			r = q;
			q = q->link;
		}
		p->link = q;
		r->link = p;
	}
	return list;
}

Nodeptr clearlist(Nodeptr list) {
	Nodeptr temp = NULL;
	for (temp = list; temp->link != NULL;) {
		if (temp->index == temp->link->index) {
			temp->coefficient += temp->link->coefficient;
			temp->link = temp->link->link;
		}
		else {
			temp = temp->link;
		}
	}
	return list;
}

int main(void) {
	Nodeptr list1 = NULL, list2 = NULL, list = NULL, temp = NULL, l = NULL, r = NULL;
	int coefficient, index;
	char c;

	do {
		scanf("%d %d", &coefficient, &index);
		list1 = insertNode(list1, coefficient, index);
		c = getchar();
	} while (c != '\n');

	do {
		scanf("%d %d", &coefficient, &index);
		list2 = insertNode(list2, coefficient, index);
		c = getchar();
	} while (c != '\n');

	for (l = list1; l != NULL; l = l->link) {
		for (r = list2; r != NULL; r = r->link) {
			list = insertNode(list, l->coefficient*r->coefficient, l->index + r->index);
		}
	}
	list = clearlist(list);
	for (temp = list; temp != NULL; temp = temp->link) {
		printf("%d %d ", temp->coefficient, temp->index);
	}

	return 0;
}
