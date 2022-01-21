#include<stdio.h>
#include<stdlib.h>

int len = 0;//����ȫ�ֱ�����¼���ݸ��� 
typedef struct node {
	int data;
	struct node *link;
}STNode, *STLink;

STLink popstlink(STLink top, int num) {
	STLink p = NULL;
	if (!(p = (STLink)malloc(sizeof(STNode))))
		return top;	//�ռ䲻��,����ʧ��
	else {
		if (len == 100) {
			printf("error ");	//��ջ����������ʧ�� 
		}
		else {
			p->data = num;
			p->link = top;
			top = p; 
			len++;
		}
	}
	return top;
}

STLink pushstlink(STLink top) {
	STLink p = top;

	if (len == 0) {
		printf("error ");	//��ջΪ�գ�����ʧ�� 
	}
	else {
		printf("%d ", p->data);
		top = top->link;
		free(p);
		len--;
	}
	return top;
}

int main(void) {
	STLink top = NULL;
	int n, num;

	while (1) {
		scanf("%d", &n);
		switch (n) {
		case 1:
			scanf("%d", &num);
			top=popstlink(top, num);
			break;
		case 0:
			top=pushstlink(top);
			break;
		case -1:
			return 0;
		}
	}

	return 0;
}
