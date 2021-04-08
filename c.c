#include "h.h"

int main(){
	Priq dummy;
	dummy.size = -1;
	display(&dummy);
	insert(&dummy, 10);
	display(&dummy);
	insert(&dummy, 23);
	display(&dummy);
	insert(&dummy, 3);
	display(&dummy);
	insert(&dummy, 324);
	display(&dummy);
	insert(&dummy, 521);
	display(&dummy);
	insert(&dummy, 1);
	display(&dummy);
	insert(&dummy, 33);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
	update(&dummy, 3, 5);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
	printf("%d\n", delete(&dummy).v_id);
	display(&dummy);
}
