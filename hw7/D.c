#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

typedef struct edge {
	int id;
	int adjvex;
	struct edge* next;
}ELink;
typedef struct ver {
	int vertex;
	ELink* link;
}VLink;
VLink G[500];

char string[500][20];	//记录站名和对应的编号，从0开始记录
int count_name = -1;


//建立邻接链表 
void insertnode(int id,int i, int j) {
	ELink* p, * q, * r;
	p = (ELink*)malloc(sizeof(ELink)); p->adjvex = j; p->id=id; p->next = NULL;

	if (G[i].link == NULL)
		G[i].link = p;
	else {
		q = G[i].link;
		if (j < q->adjvex) {
			G[i].link = p;
			p->next = q;
		}
		else {
			while (q != NULL && j > q->adjvex) {
				r = q;
				q = q->next;
			}
			p->next = q;
			r->next = p;
		}
	}
	return;
}


int main(void) {
	int i, j, k, l, r, line_sum, line, line_num, state, temp, p, min_adjvex, min_distance;
	int selected[500],mindist[500],parent[500],number[500],exchange[500];
	char name[50],start[50],end[50];
	FILE* fpin;
	ELink* edge;
	int a, b;

	if ((fpin = fopen("bgstations.txt", "r")) == NULL) {
		printf("Cannot open the file!\n");
		return 1;
	}

	for (i = 0; i < 500; i++) {
		selected[i] = 0;mindist[i] = INT_MAX;parent[i] = -1;number[i] = -1;exchange[i] = 0;
		G[i].vertex = i;G[i].link = NULL;
	}

	fscanf(fpin, "%d", &line_sum);	//读取总路线条数
	for (i = 1; i <= line_sum; i++) {
		l = -1;
		fscanf(fpin, "%d %d", &line, &line_num);
		for (j = 1; j <= line_num; j++) {
			fscanf(fpin, "%s %d", name, &state);
			for (k = 0; k <= count_name; k++) {
				if (strcmp(name, string[k]) == 0)
					break;
			}
			if (k == count_name + 1) {
				strcpy(string[++count_name], name);
				if (state == 1)
					exchange[count_name] = 1;
			}
			if (j==1) {
				r = k;continue;
			}
			else {
				l = r;r = k;
			}
			insertnode(line, l, r);
			insertnode(line, r, l);
		}
	}

	/*
	//输出地铁站编号及其名称
	for (i = 0; i <= count_name; i++) {
		printf("%d %s\n",i, string[i]);
	}
	//输出每个站点相邻的站点编号
	ELink *t;
	for (i = 0; i <= count_name; i++) {
		printf("***%d ", i);
		for (t = G[i].link; t != NULL; t = t->next)
			printf("%d ", t->adjvex);
		printf("\n");
	}
	*/
	
	scanf("%s", end);
	scanf("%s", start);
	for (l = 0; l <= count_name; l++) {
		if (strcmp(start, string[l]) == 0)
			break;
	}
	for (r = 0; r <= count_name; r++) {
		if (strcmp(end, string[r]) == 0)
			break;
	}

	selected[l] = 1;
	mindist[l]=0; 
	edge = G[l].link;
	p = l; 
	for (j = 1; j <= count_name; j++) {
		while (edge != NULL) {
			if (selected[edge->adjvex] == 0 && (mindist[p]+min_distance) < mindist[edge->adjvex]) {
				mindist[edge->adjvex] = mindist[p]+1;
				parent[edge->adjvex] = p;
				number[edge->adjvex] = edge->id;
			}
			edge = edge->next;
		}
		
		//寻找距离最近的下一个节点
		min_distance = INT_MAX;
		for (i = 0; i < count_name; i++) {
			if (selected[i] == 0 && mindist[i] < min_distance) {
				min_adjvex = i;
				min_distance = mindist[i];
			}
		}
		selected[min_adjvex] = 1;
		p = min_adjvex;
		edge = G[p].link;
	}



	int line1, line2,count=0;
	printf("%s", string[r]);
	line2 = number[r];
	for (; r != l;r=parent[r]) {
		count=count+mindist[r]-mindist[parent[r]];
		line1 = number[parent[r]];
		line2 = number[r];
		if (line1 != line2) {
			printf("-%d(%d)-", line2, count);
			printf("%s", string[parent[r]]);
			count = 0;
		}
	}
	if (count!=0) {
		printf("-%d(%d)-",number[r] , count);
		printf("%s\n", string[r]);
	}
		
	
	fclose(fpin);
	return 0;
}
