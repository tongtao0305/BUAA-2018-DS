#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MIN(a,b) (a<b)?a:b

struct node {
	char word[100];
	int count;
	struct node *link;
};
typedef struct node Node;
typedef struct node * Nodeptr;

//在链表中插入元素 
Nodeptr insertNode(Nodeptr list, char word[100]) {
	Nodeptr p, q, r, n;

	//已有重复的单词 
	for (n = list; n != NULL; n = n->link) {
		if (strcmp(n->word, word) == 0) {
			n->count++;
			return list;
		}
	}

	//没有重复的单词，需要创建新的节点 
	p = (Nodeptr)malloc(sizeof(Node));
	strcpy(p->word, word);
	p->count = 1;
	if (list == NULL || strcmp(word, list->word) < 0) {
		p->link = list;
		list = p;
	}
	else {
		q = list;
		while (q != NULL && strcmp(word, q->word) > 0) {
			r = q;
			q = q->link;
		}
		p->link = q;
		r->link = p;
	}
	return list;
}

void lower(char word[100]) {
	int i;
	char temp[100];
	strcpy(temp, word);
	for (i = 0; i < strlen(temp); i++) {
		if (65 <= temp[i] && temp[i] <= 90)
			temp[i] += 32;
	}

	if (!isalpha(word[strlen(word) - 1])) {
		strncpy(word, temp, strlen(word) - 1);
		word[strlen(word) - 1] = '\0';
	}
	else {
		strncpy(word, temp, strlen(word));
		word[strlen(word)] = '\0';
	}
}

int main(void) {
	char word[100], c;
	int count = 0;
	Nodeptr list = NULL, temp = NULL;
	FILE *fin, *fout;

	//打开输入文件 
	if ((fin = fopen("article.txt", "r")) == NULL) {
		printf("Cannot open the file!\n");
		return 1;
	}

	//读取单词并插入链表
	while ((c = fgetc(fin)) != EOF){
		if (isalpha(c)) {
			word[count] = c;
			count++;
			continue;
		}
		else if (count!=0){
			word[count] = '\0';
			count = 0;
			lower(word);
			//printf("%s\n",word);
			list = insertNode(list, word);
		}
	}

	for (temp = list; temp != NULL; temp = temp->link) {
		printf("%s %d\n", temp->word, temp->count);
	}

	return 0;
}
