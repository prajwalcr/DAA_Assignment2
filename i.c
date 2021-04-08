#include "h.h"

void shiftUp(Dummy *dummy, int i){
	int temp = dummy->H[i];
	int c = i;
	int p = (c-1)/2;
	
	while(c > 0 && dummy->H[p] > temp){
		dummy->H[c] = dummy->H[p];
		c = p;
		p = (c-1)/2;
	}
	dummy->H[c] = temp;
}

void shiftDown(Dummy *dummy, int i){
	int temp = dummy->H[i];
	int p = i;
	int c = 2*p+1;
	
	if(c > dummy->size){
		return;
	}
	
	if(c+1 <= dummy->size && dummy->H[c] > dummy->H[c+1]){
		c = c+1;
	}
	
	while(c <= dummy->size && temp > dummy->H[c]){
		dummy->H[p] = dummy->H[c];
		p = c;
		c = 2*p+1;
		if(c+1 <= dummy->size && dummy->H[c] > dummy->H[c+1]){
			c = c+1;
		}
	}
	dummy->H[p] = temp;
}

void insert(Dummy *dummy, int n){
	dummy->size++;
	dummy->H[dummy->size] = n;
	
	int c = dummy->size;
	int p = (c-1)/2;
	
	while(c > 0 && dummy->H[p] > n){
		dummy->H[c] = dummy->H[p];
		c = p;
		p = (c-1)/2;
	}
	dummy->H[c] = n;
}

int delete(Dummy *dummy){
	if(dummy->size < 0) return -1;

	int result;
	result = dummy->H[0];
	
	dummy->H[0] = dummy->H[dummy->size];
	dummy->size--;
	
	int temp = dummy->H[0];
	int p = 0;
	int c = 2*p+1;
	
	if(c > dummy->size){
		return result;
	}
	
	if(c+1 <= dummy->size && dummy->H[c] > dummy->H[c+1]){
		c = c+1;
	}
	
	while(c <= dummy->size && temp > dummy->H[c]){
		dummy->H[p] = dummy->H[c];
		p = c;
		c = 2*p+1;
		if(c+1 <= dummy->size && dummy->H[c] > dummy->H[c+1]){
			c = c+1;
		}
	}
	dummy->H[p] = temp;
	return result;
}

void update(Dummy *dummy, int i, int n){
	if(i > dummy->size) return;
	if(n > dummy->H[i]){
		dummy->H[i] = n;
		
		int temp = dummy->H[i];
		int p = i;
		int c = 2*p+1;
		
		if(c > dummy->size){
			return;
		}
		
		if(c+1 <= dummy->size && dummy->H[c] > dummy->H[c+1]){
			c = c+1;
		}
		
		while(c <= dummy->size && temp > dummy->H[c]){
			dummy->H[p] = dummy->H[c];
			p = c;
			c = 2*p+1;
			if(c+1 <= dummy->size && dummy->H[c] > dummy->H[c+1]){
				c = c+1;
			}
		}
		dummy->H[p] = temp;
	}
	else{
		dummy->H[i] = n;
		
		int c = i;
		int p = (c-1)/2;
		
		while(c > 0 && dummy->H[p] > n){
			dummy->H[c] = dummy->H[p];
			c = p;
			p = (c-1)/2;
		}
		dummy->H[c] = n;
	}
}

void display(Dummy *dummy){
	for(int i = 0; i<=dummy->size; i++){
		printf("%d ", dummy->H[i]);
	}
	printf("\n");
}
