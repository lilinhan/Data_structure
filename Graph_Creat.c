#include <stdio.h>
#include <stdlib.h>

#define DEBUG
#define MAXVEX 1000

typedef char Vertextype;
typedef int Edgetype;

typedef struct EdgeNode
{
	int adjvex;
	Edgetype weight;
	struct EdgeNode * next;
}EdgeNode;

typedef struct VexEdgHead
{
	Vertextype data;
	EdgeNode * firstedge;
}VexEdgH;

typedef struct 
{
	int numVertexes,numEdges;
	VexEdgH header[MAXVEX];
}GraphList;

int Locate(GraphList * g , char ch)
{
	int i;
	for( i = 1 ; i <= MAXVEX ; i++ )  {
		if( ch == g->header[i].data)  {
			break;
		}
	}	
	if( i > MAXVEX)  {
		printf("Sorry , There is no VEX\n");
		return -1;
	}
	return i;
}

int CreatGraph(GraphList * g)
{
	int i,m,n;
	char p,q;
	EdgeNode *e , *f;
	printf("please input The Vex and Edge's number!\n");
	scanf("%d %d",&g->numVertexes,&g->numEdges);
//	printf("%d   %d",g->numVertexes,g->numEdges);
	for( i = 1 ; i <= g->numVertexes ; i++ )  {
		printf("please input all VEX!\n");
		g->header[i].data = getchar();
		g->header[i].firstedge = NULL;
		while(g->header[i].data == '\n')
			g->header[i].data = getchar();
	}
	getchar();
	for( i = 1 ; i <= g->numEdges ; i++ )  {
		printf("please input The Vex of the Edge!(vi,vj)\n");
		scanf("%c%c",&p,&q);
		getchar();
		m = Locate(g,p);
		n = Locate(g,q);
		if( m == -1 || n == -1 )  {
			return -1;
		}
		
		printf("m = %d",m);
		printf("n = %d",n);
		printf("p = %c",p);
		printf("q = %c",q);
                printf("\n");
		
		e = (EdgeNode * )malloc(sizeof(EdgeNode));
		if( e == NULL )  {
			printf("malloc error!\n");
			return -1;
		}
		/*
		printf("please input the weight!\n");
		scanf("%d",&e->weight);
		*/
		e->adjvex = m;
		e->next = g->header[n].firstedge;
		g->header[n].firstedge = e;

		f = (EdgeNode *)malloc(sizeof(EdgeNode));
		if( f == NULL )  {
			printf("malloc error!\n");
			return -1;
		}
		/*
		printf("please input the weight!\n");
		scanf("%d",&f->weight);
		*/
		f->adjvex = n;
		f->next = g->header[m].firstedge;
		g->header[m].firstedge = f;
	}
	return 1;
}

void PrintGraph(GraphList * g)
{
	int i = 1 ;
	EdgeNode * e = NULL;
	printf("Print Start!\n\n");
	while( g->header[i].firstedge != NULL && i <= g->numVertexes )  {
		printf("VEX:%c",g->header[i].data);
		e = g->header[i].firstedge;
		while(e != NULL)  {
			printf("\t%d  ",e->adjvex);
			e = e->next;
		}
		i++;
		printf("\n");
	}
}

int main(int arrgc , char ** argv)
{
	GraphList g;
	CreatGraph(&g);
	PrintGraph(&g);
	return 0;
}
