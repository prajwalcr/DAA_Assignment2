#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct Vertex{
	int v_id;
	int d;
	int p;
	int marked;
} Vertex;

typedef struct Priq{
	Vertex vertex[1024];
	int size;
} Priq;

typedef struct Node
{
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node** adjLists;
} Graph;

typedef struct Dummy{
	int H[100];
	int size;
}Dummy;

void insert(Priq *, int, int, int);
void update(Priq *, int, int, int);
Vertex delete(Priq *);
void display(Priq *);

void shiftUp(Priq *, int);
void shiftDown(Priq *, int);

Graph *createGraph(int);
Node *createNode(int, int);
void addEdge(Graph *, int, int, int);
void printGraph(Graph *);
