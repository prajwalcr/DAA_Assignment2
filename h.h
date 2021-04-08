#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vertex{
	int v_id;
	int d;
	int p;
} Vertex;

typedef struct Priq{
	Vertex *vertex;
	int size;
} Priq;

typedef struct Dummy{
	int H[100];
	int size;
}Dummy;

void insert(Dummy *, int);
void update(Dummy *, int, int);
int delete(Dummy *);
void display(Dummy *);

void shiftUp(Dummy *, int);
void shiftDown(Dummy *, int);
