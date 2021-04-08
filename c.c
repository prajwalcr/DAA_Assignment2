#include "h.h"

int main(){
	int numVertices;
	char buf[1024];
	char *line = buf;
	Graph *graph;
	FILE *fp = fopen("adjacencylist.txt", "r");
	if(fp == NULL){
		printf("Error opening file\n");
		return 0;
	}
	
	fgets(buf, sizeof(buf), fp);
	sscanf(line, "%d", &numVertices);
	
	graph = createGraph(numVertices);

	while(fgets(buf, sizeof(buf), fp)){
		int src, n, dest, weight, count=0;
    		char *line = buf;
    		
		sscanf(line, "%d%n", &src, &n);
		line += n;

		while(sscanf(line, "%d%d%n", &dest, &weight, &n) == 2){
			line += n;
			addEdge(graph, src, dest, weight);
		}
	}
	printGraph(graph);
	
	Vertex result[numVertices+1], temp;
	Priq priq;
	priq.size = -1;
	
	for(int i=1; i < numVertices; i++){
		insert(&priq, i, INT_MAX, -1);
		temp.v_id = i;
		temp.d = INT_MAX;
		temp.p = -1;
		temp.marked = 0;
		result[i] = temp;
	}
	insert(&priq, numVertices, 0, -1);
	temp.v_id = numVertices;
	temp.d = 0;
	temp.p = -1;
	temp.marked = 0;
	result[numVertices] = temp;
	
	Vertex u_star, u;
	Node *tempNode;
	for(int i=0; i < numVertices; i++){
		u_star = delete(&priq);
		result[u_star.v_id] = u_star;
		for(int j=1; j<=numVertices; j++){
			u = result[j];
			if(u.marked == 0){
				tempNode = graph->adjLists[u.v_id];
				while(tempNode){
					if(tempNode->vertex == u_star.v_id){
						if(u_star.d + tempNode->weight < u.d){
							update(&priq, u.v_id, u_star.d + tempNode->weight, u_star.v_id);
						}
					}
				}
			}
		}
	}
	
	display(&priq);	
	
	fclose(fp);
	
}
