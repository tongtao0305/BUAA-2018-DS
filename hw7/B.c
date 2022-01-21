#include<stdio.h>
#include<stdlib.h>

int n,e,flag=0,count=0,path[1000],Visited[1000];

typedef struct edge {
	int adjvex;
	int weight;	//此处的weight指的是边的编号 
	struct edge* next;
}ELink;
typedef struct ver {
	int vertex;
	ELink* link;
}VLink;
VLink G[1000];

void insertnode(int weight,int i, int j) {
	ELink* p, * q, * r;
	p = (ELink*)malloc(sizeof(ELink));
	p->adjvex = j;
	p->weight=weight;
	p->next = NULL;
	if (G[i].link == NULL)
		G[i].link = p;
	else {
		q = G[i].link;
		if (weight < q->weight) {
			G[i].link = p;
			p->next = q;
		}
		else {
			while (q != NULL && weight > q->weight) {
				r = q;
				q = q->next;
			}
			p->next = q;
			r->next = p;
		}
	}
}
//建立邻接链表 
void ADJLIST() {
	int k, i, j,weight;
	ELink* p1,*p2, * q;
	for (k = 0; k < n; k++) {
		G[k].vertex = k;
		G[k].link = NULL;
	}
	for (k = 0; k < e; k++) {
		scanf("%d %d %d",&weight, &i, &j);
		insertnode(weight,i, j);
		insertnode(weight,j, i);
	}
}

//深度搜索 
void DFS(int v)
{
	int i;
	ELink* p;
	//如果到达了终点 
	if (v==n-1){
		for (i=0;i<=count;i++)
			printf("%d ",path[i]);
		printf("\n");
		return;
	}
	else{
		for (p = G[v].link; p != NULL; p = p->next)
			if (!Visited[p->adjvex]){
				Visited[p->adjvex] = 1; 
				path[++count]=p->weight;
				DFS(p->adjvex);
				Visited[p->adjvex] = 0; 
				count--;
			}		
	}
}
void  travelDFS()
{
	int i;
	ELink *p=G[0].link;
	while(p!=NULL){
		flag=0;
		for (i = 0; i < n; i++)
			Visited[i] = 0;
		Visited[0]=1;
		Visited[p->adjvex]=1;
		path[count]=p->weight;
		DFS(p->adjvex);
		Visited[p->adjvex]=0;
		p=p->next;
	}
}

int main(void){
	scanf("%d %d",&n,&e);
	ADJLIST();
	travelDFS();
	return 0;
} 
/*
6 8
1 0 1
2 1 2
3 2 3
4 2 4
5 3 5
6 4 5
7 0 5
8 0 1
*/
