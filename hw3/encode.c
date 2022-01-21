#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	char ch;
	struct node* link;
};
typedef struct node Node;
typedef struct node *Nodeptr;

//在链表中插入节点 
Nodeptr insertNode(Nodeptr list, char c) {
	Nodeptr p, q, r;
	p = (Nodeptr)malloc(sizeof(Node));
	p->ch = c;
	if (list == NULL) {
		list = p;
		list->link = list;
	}
	else {
		for (q = list; q->link != list; q = q->link)
			;
		q->link = p;
		p->link = list;
	}
	return list;
}

int main(void) {
	int i, j, k, len;
	int string_out[150], string_count[150], string_temp[150];
	char string_in[50], ch, first,wait;
	FILE *fin, *fout;
	Nodeptr list = NULL, temp = NULL, l = NULL, r = NULL;

	//ASCII编码为32到126的可见字符，初始化判断数组 
	for (i = 32; i <= 126; i++)
		string_count[i] = 1;

	if ((fin = fopen("in.txt", "r")) == NULL) {
		printf("Cannot open the file!\n");	//无法打开输入文件 
		return 1;
	}

	if ((fout = fopen("in_crpyt.txt", "w")) == NULL) {
		printf("Cannot open the file!\n");	//无法打开输出文件 
		return 1;
	}

	//从标准输入中读取密钥 
	fgets(string_in, 32, stdin);

	//生成密钥环 
	for (i = 0; i < strlen(string_in); i++) {
		if (string_count[string_in[i]] == 1) {
			list = insertNode(list, string_in[i]);
			string_count[string_in[i]] = 0;
		}
	}
	
	for (i = 32; i <= 126; i++) {
		if (string_count[i] == 1) {
			list = insertNode(list, i);
			string_count[i] = 0;
		}
	}

	//独立记录第一个字符
	first = list->ch;
	wait = list->ch;
	len = list->ch;
	for (r = list->link ; r != list; l = r, r = r->link)
		;
	l->link = r->link;
	free(r);
	list = l->link;
	r = list;
	for (i = 32; i <= 126; i++) {
		//最后一个 
		if (i == 126 || r->link == r) {
			string_out[r->ch] = first;
			break;
		}
		//寻找ASCII码对应的需要删除的节点
		while (len > 1) {		
			l = r;
			r = r->link;
			len--;
		}

		string_out[wait] = r->ch;
		wait = r->ch;
		len = (r -> ch);
		l->link = r->link;
		free(r);
		r = l->link;
	}

	
	//在文件中输出加密文件 
	while ((ch = fgetc(fin)) != EOF) {
		if (32<=ch&&ch<=126)
			fputc(string_out[ch], fout);
		else
			fputc(ch, fout);
	}
	

	return 0;
}
