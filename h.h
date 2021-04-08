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
