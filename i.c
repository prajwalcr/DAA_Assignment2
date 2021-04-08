#include "h.h"

void shiftUp(Priq *priq, int i){
	int temp = priq->vertex[i].v_id;
	int c = i;
	int p = (c-1)/2;
	
	while(c > 0 && priq->vertex[p].v_id > temp){
		priq->vertex[c].v_id = priq->vertex[p].v_id;
		c = p;
		p = (c-1)/2;
	}
	priq->vertex[c].v_id = temp;
}

void shiftDown(Priq *priq, int i){
	int temp = priq->vertex[i].v_id;
	int p = i;
	int c = 2*p+1;
	
	if(c > priq->size){
		return;
	}
	
	if(c+1 <= priq->size && priq->vertex[c].v_id > priq->vertex[c+1].v_id){
		c = c+1;
	}
	
	while(c <= priq->size && temp > priq->vertex[c].v_id){
		priq->vertex[p].v_id = priq->vertex[c].v_id;
		p = c;
		c = 2*p+1;
		if(c+1 <= priq->size && priq->vertex[c].v_id > priq->vertex[c+1].v_id){
			c = c+1;
		}
	}
	priq->vertex[p].v_id = temp;
}

void insert(Priq *priq, int n){
	priq->size++;
	priq->vertex[priq->size].v_id = n;
	
	shiftUp(priq, priq->size);
}

Vertex delete(Priq *priq){
	if(priq->size < 0){
		Vertex temp;
		temp.v_id = -1;
		temp.d = -1;
		temp.p = -1;
		return temp;
	}

	Vertex res;
	res = priq->vertex[0];
	
	priq->vertex[0].v_id = priq->vertex[priq->size].v_id;
	priq->size--;
	
	shiftDown(priq, 0);
	return res;
}

void update(Priq *priq, int i, int n){
	if(i > priq->size) return;
	if(n > priq->vertex[i].v_id){
		priq->vertex[i].v_id = n;
		
		shiftDown(priq, i);
	}
	else{
		priq->vertex[i].v_id = n;
		
		shiftUp(priq, i);
	}
}

void display(Priq *priq){
	for(int i = 0; i <= priq->size; i++){
		printf("%d ", priq->vertex[i].v_id);
	}
	printf("\n");
}
