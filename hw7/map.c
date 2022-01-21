#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXNUM 512
#define MAXLEN 16
#define INFINITY 32767

typedef struct Station{
    char StopName[MAXLEN];
    int ischange;
}Station;
typedef struct Weight{
    int wei;
    int LineNo;
}Weight;

Station BGvertex[MAXNUM];
Weight BGweights[MAXNUM][MAXNUM];
int Vnum=0;

void initMap(void);
int addVertex(Station st);
void Dijkstra(int v0,int v1,int spath[]);
void printPath(int v0,int v1,int spath[]);

int main(void)
{
    FILE *fpin;
	//fpin=fopen("in.txt","r"); 
	int v1,v2,spath[1000];
    int i,j;
    char start[MAXLEN],end[MAXLEN];

    for(i=0;i<MAXNUM;i++)
        for(j=0;j<MAXNUM;j++)
        {
            BGweights[i][j].wei=INFINITY;
            BGweights[i][j].LineNo=0;
        }

    initMap();
    
    /*
    while((fscanf(fpin,"%s%s",start,end))!=EOF){
    	    v1=v2=-1;
    for(i=0;i<Vnum;i++)
        if(!strcmp(BGvertex[i].StopName,start))
        {
            v1=i;
            break;
        }
    for(i=0;i<Vnum;i++)
        if(!strcmp(BGvertex[i].StopName,end))
        {
            v2=i;
            break;
        }

    Dijkstra(v1,v2,spath);
    printPath(v1,v2,spath);
	}
	*/ 
    
	scanf("%s%s",start,end);

    v1=v2=-1;
    for(i=0;i<Vnum;i++)
        if(!strcmp(BGvertex[i].StopName,start))
        {
            v1=i;
            break;
        }
    for(i=0;i<Vnum;i++)
        if(!strcmp(BGvertex[i].StopName,end))
        {
            v2=i;
            break;
        }

    Dijkstra(v1,v2,spath);
    printPath(v1,v2,spath);

    return 0;
}
void initMap(void)
{
    FILE *fp;
    int i,j,snum,lno,lnum,v1,v2;
    Station st;

    if((fp=fopen("bgstations.txt","r"))==NULL)
        exit(-1);

    fscanf(fp,"%d",&snum);
    for(i=0;i<snum;i++)
    {
        fscanf(fp,"%d %d",&lno,&lnum);
        v1=v2=-1;
        for(j=0;j<lnum;j++)
        {
            fscanf(fp,"%s %d",st.StopName,&st.ischange);
            v2=addVertex(st);
            if(v1!=-1)
            {
                BGweights[v1][v2].wei=BGweights[v2][v1].wei=1;
                BGweights[v1][v2].LineNo=BGweights[v2][v1].LineNo=lno;
            }
            v1=v2;
        }
    }
    fclose(fp);
    return;
}
int addVertex(Station st)
{
    int i;

    for(i=0;i<Vnum;i++)
        if(!strcmp(BGvertex[i].StopName,st.StopName))
            return i;

    BGvertex[i]=st;
    return Vnum++;
}
void Dijkstra(int v0,int v1,int spath[])
{
    int i,j,v,minweight;
    int wfound[MAXNUM]={0};
    int sweight[MAXNUM]={0};
    for(i=0;i<Vnum;i++)
    {
        sweight[i]=BGweights[v0][i].wei;
        spath[i]=v0;
    }
    sweight[v0]=0;
    wfound[v0]=1;

    v=-1;
    for(i=0,j=0;i<Vnum-1;i++)
    {
        minweight=INFINITY;
        for(j=0;j<Vnum;j++)
            if(!wfound[j] && sweight[j]<minweight)
            {
                v=j;
                minweight=sweight[v];
            }
        wfound[v]=1;
        if(v==v1)
            return;
        for(j=0;j<Vnum;j++)
            if(!wfound[j] && BGweights[v][j].LineNo>0 && minweight+BGweights[v][j].wei<sweight[j])
            {
                sweight[j]=minweight+BGweights[v][j].wei;
                spath[j]=v;
            }
    }
    for(i=0;i<j;i++)
        printf("%d ",spath[i]);
    return;
}
void printPath(int v0,int v1,int spath[])
{
    char path[80]={0},buf[80];
    int board[80],bcount=0,line=-1,sc=0;
    int i;
    do
    {
        board[bcount++]=v1;
    }while((v1=spath[v1])!=v0);
    board[bcount++]=v0;

    line=BGweights[board[bcount-1]][board[bcount-2]].LineNo;
    sprintf(buf,"%s-%d(",BGvertex[board[bcount-1]].StopName,line);
    strcpy(path,buf);
    sc=1;
    for(i=bcount-2;i>0;i--,sc++)
        if(BGweights[board[i]][board[i-1]].LineNo!=line)
        {
            line=BGweights[board[i]][board[i-1]].LineNo;
            sprintf(buf,"%d)-%s-%d(",sc,BGvertex[board[i]].StopName,line);
            strcat(path,buf);
            sc=0;
        }
    sprintf(buf,"%d)-%s\n",sc,BGvertex[board[i]].StopName);
    strcat(path,buf);
    puts(path);

    return;
}
