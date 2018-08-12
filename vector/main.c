#include "vector.h"
#include <stdio.h>

int main(){

	vector arr = { NULL, };
	for (int i = 0; i < 10; i++){
		push_back(&arr, i);
	}
	pop_back(&arr);
	insert(&arr, find(&arr,4), 200);
	erase(&arr, find(&arr,3));
	//printf("%d", empty(&arr));
	//clear(&arr);
	/*printf("%d",empty(&arr));*/
//resize(&arr, 7, 100);
	for (int* it = begin(&arr); it != end(&arr); it++){ 
		printf("%d ", *it);
	}
}