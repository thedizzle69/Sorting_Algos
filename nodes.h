#ifndef Nodes
#define Nodes

struct list {
	int data;
	struct list* next;
};

typedef struct list* node;

//prototypes
node init_list();
void free_list(node);
int copy_array_to_list(node, int*, int);
void print_list(node);
node insertion_sort_list(node);

#endif // !Nodes
