#include "vector.h"
#include<assert.h>
#include<string.h>
#include<malloc.h>

void push_back(vector* v, int val){
	if (v->capacity == v->size){
		v->capacity = v->capacity ? v->capacity * 2 : 1;
		v->base = realloc(v->base, sizeof(int)*v->capacity);
	}
	v->base[v->size] = val;
	v->size++;
}
void pop_back(vector* v){
	assert(v->size >= 0);	//방어적코딩
	v->size--;

}
int front(vector* v){
	return v->base[0];
}
int back(vector* v){
	return v->base[v->size - 1];
}
int size(vector* v){
	return v->size;
}
int capacity(vector* v){
	return v->capacity;
}
void erase(vector* v, int* it){
	int pos = (it - v->base);
	assert(pos >= 0 && pos < v->size);
	memmove(v->base + pos, v->base + pos + 1, sizeof(int)*(v->size - (pos + 1)));
	v->size--;
}
void insert(vector* v, int* it, int val){
	int pos = (it - v->base);
	assert(pos >= 0 && pos < v->size);
	if (v->size == v->capacity){
		v->capacity = v->capacity ? v->capacity * 2 : 1;
		v->base = realloc(v->base, sizeof(int)*v->capacity);
	}
	memmove(v->base + pos + 1, v->base + pos, sizeof(int)*(v->size - (pos)));
	v->base[pos] = val;
	v->size++;
}
void resize(vector* v, int N, int val){
	if (N > v->capacity){
		v->capacity = N;
		v->base = realloc(v->base, sizeof(int)*v->capacity);
	}
	for (int i = v->size; i < N; i++){
		v->base[i] = val;
	}
	v->size = N;
}
int* end(vector* v){
	return v->base + v->size;
}
int* begin(vector* v){
	return v->base;
}
void clear(vector* v){
	v->size = 0;
}
int empty(vector* v){
	return v->size ? 0 : 1;
}
int* find(vector* v, int val){
	for (int i = 0; i < v->size; i++){
		if (v->base[i] == val){
			return v->base + i;
		}
	}
	return NULL;
}

