typedef struct vector{
	int* base;
	int size;
	int capacity;
}vector;

void push_back(vector* v, int val);
void pop_back(vector* v);
int front(vector* v);
int back(vector* v);
int size(vector* v);
int capacity(vector* v);
void erase(vector* v, int idx);
void insert(vector* v, int idx, int val);
void resize(vector* v);
int* end(vector* v);
int* begin(vector* v);
void clear(vector* v);
int empty(vector* v);
int* find(vector* v, int val);