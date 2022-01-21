#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int count_words = -1, count = 0;
char words[3500][100], temp[100];

//???? 
int ordersearch() {
	int i;
	for (i = 0; i <= count_words; i++) {
		count++;
		if (strcmp(temp, words[i]) == 0)
			return 1;
		else if (strcmp(temp, words[i]) < 0)
			return 0;
	}
	return 0;
}

//???? 
int halfsearch() {
	int i = 0, j = count_words, mid;
	while (i < j) {
		count++;
		mid = (i + j) / 2;
		if (strcmp(temp, words[mid]) == 0)
			return 1;
		else if (strcmp(temp, words[mid]) > 0)
			i = mid + 1;
		else if (strcmp(temp, words[mid]) < 0)
			j = mid - 1;
	}
	return 0;
}

//???? 
int indexsearch() {
	int i = 0, j = count_words, mid;

	while (words[i][0] != temp[0])
		i++;
	while (words[j][0] != temp[0])
		j--;

	printf("FROM %d TO %d\n", i, j);

	while (i < j) {
		count++;
		mid = (i + j) / 2;
		if (strcmp(temp, words[mid]) == 0)
			return 1;
		else if (strcmp(temp, words[mid]) > 0)
			i = mid + 1;
		else if (strcmp(temp, words[mid]) < 0)
			j = mid - 1;
	}
	return 0;
}

//??hash???? 
typedef struct hashnode {
	char string[100];
	struct hashnode* link;
}node, * nodeptr;
nodeptr symtub[3005];

/* compute hash value for string */
#define NHASH  3001
#define MULT  37
unsigned int hash(char* str) {
	unsigned int h = 0;
	char* p;
	for (p = str; *p != '\0'; p++)
		h = MULT * h + *p;
	return h % NHASH;
}

void insertnode(char string[]) {
	nodeptr n, r = symtub[hash(string)];
	n = (nodeptr)malloc(sizeof(node));
	strcpy(n->string, string);
	n->link = NULL;

	if (r == NULL)
		symtub[hash(string)] = n;
	else {
		while (r->link != NULL)
			r = r->link;
		r->link = n;
	}
	return;
}

int searchnode() {
	nodeptr r = symtub[hash(temp)];
	if (r == NULL)
		return 0;
	else {
		while (r != NULL) {
			count++;
			if (strcmp(temp, r->string) == 0)
				return 1;
			else if (strcmp(temp, r->string) > 0)
				r = r->link;
			else if (strcmp(temp, r->string) < 0)
				break;
		}
	}
	return 0;
}

//hash?? 
int hashsearch() {
	int i;
	for (i = 0; i < 3005; i++)
		symtub[i] = NULL;
	for (i = 0; i <= count_words; i++) {
		insertnode(words[i]);
	}
		

	return searchnode();
}

int main(void) {
	FILE* fpin;
	int i, j, k, type = 0, result;

	if ((fpin = fopen("Edictionary3000.txt", "r")) == NULL) {
		printf("Cannot open the file!\n");
		return 1;
	}

	//?????
	while ((fscanf(fpin, "%s", temp)) != EOF) {
		strcpy(words[++count_words], temp);
	}

	scanf("%s %d", temp, &type);

	switch (type) {
	case 1:result = ordersearch(); break;
	case 2:result = halfsearch(); break;
	case 3:result = indexsearch(); break;
	case 4:result = hashsearch(); break;
	}

	printf("%d %d", result, count);

	return 0;
}
