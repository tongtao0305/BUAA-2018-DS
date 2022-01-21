#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n, e, sum = 0;
int selected[100];
int mindist[100];
int parent[100];
int number[100];
int chosen[100];

typedef struct edge {
	int adjvex, id, weight;
	struct edge* next;
}ELink;
typedef struct ver {
	int vertex;
	ELink* link;
}VLink;
VLink G[1000];

//建立邻接链表 
void insertnode(int weight, int id, int i, int j) {
	ELink* p, * q, * r;
	p = (ELink*)malloc(sizeof(ELink)); p->adjvex = j; p->id = id; p->weight = weight; p->next = NULL;
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
}
void ADJLIST() {
	int k, i, j, weight, id;
	ELink* p1, * p2, * q;
	for (k = 0; k < n; k++) {
		G[k].vertex = k;
		G[k].link = NULL;
	}
	for (k = 0; k < e; k++) {
		scanf("%d %d %d %d", &id, &i, &j, &weight);
		insertnode(weight, id, i, j);
		insertnode(weight, id, j, i);
	}
}

void MINSPANT_PRIM() {
	int i, j, k, temp, p, min_adjvex,min_distance;
	ELink* edge;

	//对三个序列进行初始化 
	for (i = 0; i < n; i++) {
		selected[i] = 0;
		mindist[i] = INT_MAX;
		parent[i] = -1;
		number[i] = -1;
	}
	for (i = 0; i < e; i++)
		chosen[i] = 0;
	//从第一个节点开始筛选 
	selected[0] = 1;
	mindist[0] = -1;
	p = 0;
	edge = G[0].link;
	//再进行n-1次操作 
	for (j = 1; j < n; j++) {
		/*
		printf("********************1\n");
		for (i = 0; i < n; i++)
			printf("%10d ", selected[i]);
		printf("\n");
		for (i = 0; i < n; i++)
			printf("%10d ", mindist[i]);
		printf("\n");
		for (i = 0; i < n; i++)
			printf("%10d ", parent[i]);
		printf("\n");
		for (i = 0; i < e; i++)
			printf("%8d %d  ", i, chosen[i]);
		printf("\n");
		printf("********************\n");
		*/
		//更新mindist序列 
		while (edge != NULL) {
			if (selected[edge->adjvex] == 0 && edge->weight < mindist[edge->adjvex]) {
				mindist[edge->adjvex] = edge->weight;
				parent[edge->adjvex] = p;
				number[edge->adjvex] = edge->id;
			}
			edge = edge->next;
		}
		/*
		printf("********************2\n");
		for (i = 0; i < n; i++)
			printf("%10d ", selected[i]);
		printf("\n");
		for (i = 0; i < n; i++)
			printf("%10d ", mindist[i]);
		printf("\n");
		for (i = 0; i < n; i++)
			printf("%10d ", parent[i]);
		printf("\n");
		for (i = 0; i < e; i++)
			printf("%8d %d  ", i, chosen[i]);
		printf("\n");
		printf("********************\n");
		*/
		//寻找距离最近的下一个节点
		min_distance = INT_MAX;
		for (i = 0; i < n; i++) {
			if (selected[i] == 0 && mindist[i] < min_distance) {
				min_adjvex = i;
				min_distance = mindist[i];
			}
		}
		selected[min_adjvex] = 1;
		chosen[number[min_adjvex]] = 1;
		p = min_adjvex;
		sum = sum + mindist[min_adjvex];
		edge = G[p].link;
	}
}


int main(void) {
	int i;
	ELink* t;
	scanf("%d %d", &n, &e);
	ADJLIST();

	/*
	for (i = 0; i < n; i++) {
		t = G[i].link;
		printf("***%d", i);
		for (t = G[i].link; t != NULL; t = t->next)
			printf("( %d , %d , %d )", t->adjvex, t->id, t->weight);
		printf("\n");
	}
	*/

	MINSPANT_PRIM();
	printf("%d\n", sum);
	for (i = 1; i <= e; i++)
		if (chosen[i] == 1)
			printf("%d ", i);
	return 0;
}
/*
6 10
1 0 1 600
2 0 2 100
3 0 3 500
4 1 2 500
5 2 3 500
6 1 4 300
7 2 4 600
8 2 5 400
9 3 5 200
10 4 5 600


5 8
1 0 1 600
2 0 2 100
3 0 3 500
4 1 2 500
5 2 3 500
6 1 4 300
7 2 4 600
8 3 4 400
*/
