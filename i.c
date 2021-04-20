#include "PES1UG19CS336_H.h"

void shiftUp(Priq *priq, int i){
	Vertex temp = priq->vertex[i];
	int c = i;
	int p = (c-1)/2;
	
	while(c > 0 && priq->vertex[p].d > temp.d){
		priq->vertex[c] = priq->vertex[p];
		c = p;
		p = (c-1)/2;
	}
	priq->vertex[c] = temp;
}

void shiftDown(Priq *priq, int i){
	Vertex temp = priq->vertex[i];
	int p = i;
	int c = 2*p+1;
	
	if(c > priq->size){
		return;
	}
	
	if(c+1 <= priq->size && priq->vertex[c].d > priq->vertex[c+1].d){
		c = c+1;
	}
	
	while(c <= priq->size && temp.d > priq->vertex[c].d){
		priq->vertex[p] = priq->vertex[c];
		p = c;
		c = 2*p+1;
		if(c+1 <= priq->size && priq->vertex[c].d > priq->vertex[c+1].d){
			c = c+1;
		}
	}
	priq->vertex[p] = temp;
}

void insert(Priq *priq, int v_id, int d, int p){
	priq->size++;
	priq->vertex[priq->size].v_id = v_id;
	priq->vertex[priq->size].d = d;
	priq->vertex[priq->size].p = p;
	priq->vertex[priq->size].marked = 0;
	
	shiftUp(priq, priq->size);
}

Vertex delete(Priq *priq){
	if(priq->size < 0){
		Vertex temp;
		temp.v_id = -1;
		temp.d = -1;
		temp.p = -1;
		temp.marked = -1;
		return temp;
	}

	Vertex res;
	priq->vertex[0].marked = 1;
	res = priq->vertex[0];
	
	priq->vertex[0] = priq->vertex[priq->size];
	priq->size--;
	
	shiftDown(priq, 0);
	return res;
}

Vertex update(Priq *priq, int v_id, int d, int p){
	int pos;
	Vertex temp;
	
	for(int i=0; i <= priq->size; i++){
		if(priq->vertex[i].v_id == v_id){
			pos = i;
			break;
		}
	}
	
	priq->vertex[pos].p = p;
	if(d > priq->vertex[pos].d){
		priq->vertex[pos].d = d;
		temp = priq->vertex[pos];
		shiftDown(priq, pos);
	}
	else{
		priq->vertex[pos].d = d;
		temp = priq->vertex[pos];
		shiftUp(priq, pos);
	}
	return temp;
}

void display(Priq *priq){
	for(int i = 0; i <= priq->size; i++){
		printf("%d ", priq->vertex[i].v_id);
	}
	printf("\n");
	for(int i = 0; i <= priq->size; i++){
		printf("%d ", priq->vertex[i].d);
	}
	printf("\n");
	for(int i = 0; i <= priq->size; i++){
		printf("%d ", priq->vertex[i].p);
	}
	printf("\n\n");
}

Graph* createGraph(int vertices) {
	Graph* graph = malloc(sizeof(Graph));
	
	graph->numVertices = vertices;
	graph->adjLists = malloc(vertices * sizeof(Node*));

	for (int i = 0; i <= vertices; i++) {
		graph->adjLists[i] = NULL;
	}
  return graph;
}

Node* createNode(int vertex, int weight) {
	Node* newNode = malloc(sizeof(Node));
	newNode->vertex = vertex;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
	Node* newNode = createNode(dest, weight);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;
}

void printGraph(Graph* graph) {
	for (int v = 1; v <= graph->numVertices; v++) {
		Node* temp = graph->adjLists[v];
		printf("\n Adjacency list of vertex %d\n ", v);
		while (temp) {
			printf("%d[%d] -> ", temp->vertex, temp->weight);
			temp = temp->next;
		}
		printf("\n");
	}
}
