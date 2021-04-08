#include "h.h"

int main(){
	int numVertices;
	char buf[1024];
	char *line = buf;
	FILE *fp = fopen("adjacencylist.txt", "r");
	if(fp == NULL){
		printf("Error opening file\n");
		return 0;
	}
	
	fgets(buf, sizeof(buf), fp);
	sscanf(line, "%d", &numVertices);
	printf("%d\n", numVertices);

	while(fgets(buf, sizeof(buf), fp)){
		int src, n, dest, weight, count=0;
		//char data[] = "100 185 400 11 1000";
    		//line = data;
    		char *line = buf;
		sscanf(line, "%d%n", &src, &n);
		line += n;
		printf("%d ", src);

		while(sscanf(line, "%d%d%n", &dest, &weight, &n) == 2){
			line += n;
			printf("%d %d ", dest, weight);
		}
		printf("\n");
	}
	
}
