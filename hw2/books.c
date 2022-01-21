#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//定义包含书的各项信息的结构 
struct book {
	char name[100];
	char author[100];
	char press[100];
	int year;
};
//定义节点 
struct node {
	struct book Book;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;

//更新书籍信息到文件ordered.txt中 
void renewlist(Nodeptr list) {
	Nodeptr temp;
	FILE *fpout;
	fpout = fopen("ordered.txt", "w");
	for (temp = list; temp != NULL; temp = temp->link)
		fprintf(fpout, "%-50s%-20s%-30s%-10d\n", temp->Book.name, temp->Book.author, temp->Book.press, temp->Book.year);
	fclose(fpout);
}

int main(void) {
	int i, j, k, n, year;
	char name[50], author[20], press[30], search[10];
	FILE *fpin, *fpout;
	Nodeptr list = NULL;

	if ((fpin = fopen("books.txt", "r")) == NULL){
		printf("Cannot open the file!\n");	//无法打开文件 
		return 1;
	}	

	while (fscanf(fpin, "%s %s %s %d", name, author, press, &year) != EOF) {
		Nodeptr n, l, r;
		n = (Nodeptr)malloc(sizeof(Node));
		strcpy(n->Book.name, name);
		strcpy(n->Book.author, author);
		strcpy(n->Book.press, press);
		n->Book.year = year;
		n->link = NULL;
		if (list == NULL) {
			list = n;
		}
		else {
			for (r = list; strcmp(name, r->Book.name) > 0 && r != NULL; l = r, r = r->link);//寻找插入位置 
			if (r == list) {
				n->link = r;
				list = n;
			}
			else {
				l->link = n;
				n->link = r;
			}
		}
	}
	renewlist(list);


	do {
		scanf("%d", &n);

		if (n == 1) {
			scanf("%s %s %s %d", name, author, press, &year);
			Nodeptr n=NULL, l, r;
			n = (Nodeptr)malloc(sizeof(Node));
			strcpy(n->Book.name, name);
			strcpy(n->Book.author, author);
			strcpy(n->Book.press, press);
			n->Book.year = year;
			n->link = NULL;
			if (list == NULL) {
				list = n;
			}
			else {
				for (r = list; strcmp(name, r->Book.name) > 0 && r != NULL; l = r, r = r->link);//寻找插入位置 
				if (r == list) {
					n->link = r;
					list = n;
				}
				else {
					l->link = n;
					n->link = r;
				}
			}
			renewlist(list);
		}
		else if (n == 2) {
			scanf("%s", search);
			Nodeptr q = list;
			while (q != NULL) {
				if (strstr(q->Book.name, search) != NULL) {
					printf("%-50s%-20s%-30s%-10d\n", q->Book.name, q->Book.author, q->Book.press, q->Book.year);
				}
				q = q->link;
			}
			renewlist(list);
		}
		else if (n == 3) {
			scanf("%s", search);
			Nodeptr l=list, r = list;			
			while (r != NULL) {
				if (strstr(r->Book.name, search) != NULL) {
					if (r == list) {
						list = r->link;
					}
					else {
						l->link = r->link;
					}
					if (r != NULL) {
						r = l;
					}
				}
				l = r;
				r = l->link;	
			}
			renewlist(list);
		}	
		else {
			renewlist(list);
		}
	} while (n != 0);

	return 0;
}


