#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vertex{
	int v_id;
	int d;
	int p;
} Vertex;

typedef struct Priq{
	Vertex vertex[1000];
	int size;
} Priq;

typedef struct Node
{
    int vertex;
    int weight;
    struct node* next;
} Node;

typedef struct Graph
{
    int numVertices;
    struct node** adjLists;
} Graph;

typedef struct Dummy{
	int H[100];
	int size;
}Dummy;

void insert(Priq *, int);
void update(Priq *, int, int);
Vertex delete(Priq *);
void display(Priq *);

void shiftUp(Priq *, int);
void shiftDown(Priq *, int);

Graph *createGraph(int);
