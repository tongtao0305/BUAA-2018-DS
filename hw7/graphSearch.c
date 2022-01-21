#include<stdio.h>
#include<stdlib.h>

int  Visited[200] = { 0 }; //??????????,N????

//???????????????
typedef struct edge {
	int adjvex;
	struct edge* next;
}ELink;
typedef struct ver {
	int vertex;
	ELink* link;
}VLink;
VLink G[100];

//?????
void insertnode(int i, int j) {
	ELink* p, * q, * r;
	p = (ELink*)malloc(sizeof(ELink));
	p->adjvex = j;
	p->next = NULL;
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
void ADJLIST(VLink G[], int n, int e) {
	int k, vi, vj;
	ELink* p1,*p2, * q;
	for (k = 0; k < n; k++) {
		G[k].vertex = k;
		G[k].link = NULL;
	}
	for (k = 0; k < e; k++) {
		scanf("%d %d", &vi, &vj);
		insertnode(vi, vj);
		insertnode(vj, vi);
	}
}

//?????????item???
void DELVER(VLink G[], int n, int item) {
	int i, k = -1;
	ELink* p, * q, * r;
	for (i = 0; i < n; i++) {
		if (G[i].vertex == item) {
			k = i;
			break;
		}
	}
	if (k != -1) {
		p = G[k].link;
		for (i = k + 1; i < n; i++) {
			G[i - 1].vertex = G[i].vertex;
			G[i - 1].link = G[i].link;
		}
		n--;
		while (p != NULL) {
			r = p;
			p = p->next;
			free(r);
		}
		for (i = 0; i < n; i++) {
			p = G[i].link;
			while (p != NULL)
				if (p->adjvex == k) {
					if (G[i].link == p)
						G[i].link = p->next;
					else
						q->next = p->next;
					r = p;
					p = p->next;
					free(r);
				}
				else {
					if (p->adjvex > k)
						p->adjvex--;
					q = p;
					p = p->next;
				}
		}
	}
}

void VISIT(VLink G[], int v) {
	printf("%d ", G[v].vertex);
}

//??????
void DFS(VLink G[], int v)
{
	ELink* p;
	Visited[v] = 1; //?????????
	VISIT(G, v); //?????
	for (p = G[v].link; p != NULL; p = p->next)
		if (!Visited[p->adjvex])
			DFS(G, p->adjvex);
}
void  travelDFS(VLink  G[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0;
	for (i = 0; i < n; i++)
		if (!Visited[i])
			DFS(G, i);
}


//??????
//???????????????????????? 
int Q[200];
int front = -1, rear = -1;
void BFS(VLink  G[], int v)
{
	ELink* p;
	VISIT(G, v); //??????
	Visited[v] = 1; //?????????
	Q[++rear] = v;//???? 
	while (!(front == rear)) {
		v = Q[++front];  //??????
		p = G[v].link;  //????????????
		for (; p != NULL; p = p->next) //?????????????
			if (!Visited[p->adjvex]) {
				VISIT(G, p->adjvex); //??????
				Visited[p->adjvex] = 1; //?????????
				Q[++rear] = p->adjvex;
			}
	}
}
void  travelBFS(VLink  G[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		Visited[i] = 0;
	for (i = 0; i < n; i++)
		if (!Visited[i])
			BFS(G, i);
}


int main(void) {

	int i, n, e, del;

	//????????????????? 
	scanf("%d %d", &n, &e);
	ADJLIST(G, n, e);

	/*
	for (i = 0; i < n; i++) {
		printf("%d ", G[i].vertex);
		ELink* temp = G[i].link;
		while(temp) {
			printf("%d ", temp->adjvex);
			temp = temp->next;
		}
		printf("\n");
	}
	*/

	travelDFS(G, n); printf("\n");
	travelBFS(G, n); printf("\n");

	scanf("%d", &del);
	DELVER(G, n, del);

	travelDFS(G, n-1); printf("\n");
	travelBFS(G, n-1); printf("\n");

	return 0;
}

/*
9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3
*/
