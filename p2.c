#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct tree_node{
	struct tree_node * left;
	struct tree_node * right;
	int data;
} Tree_node;


/* Adapted Vector type, with data being an array of node pointers */
typedef struct{
	Tree_node ** data; /* Pointer to data */
	int size;      /* Size of the array from the user's perspective */
	int capacity;  /* The actual size of allocation "data" pointer points to */
} Vector;

/* Insert your vector functions here and convert to Tree_node * data type */
/* Insert your vector functions here and convert to Tree_node * data type */
/* Insert your vector functions here and convert to Tree_node * data type */

/* Stack structure built on top of our Vector type */
typedef struct{
	Vector * v;
} Stack;

/* Initializes stack */
Stack * init_stack(void)
{
}

/* Pushes node pointer onto stack */
void push(Stack * stack, Tree_node * value )
{
}

/* Pops node pointer off of stack */
Tree_node * pop( Stack * stack )
{
}


/* Determines if the given tree is a valid BST or not */
int is_tree_iterative(Tree_node * tree)
{
}

Tree_node * build_good_tree(void)
{
	/* Allocate head */
	int n_nodes = 11;
	int i;
	Tree_node * nodes = (Tree_node *) malloc(n_nodes * sizeof(Tree_node));
	for( i = 0; i < n_nodes; i++ )
	{
		nodes[i].data  = i;
		nodes[i].left  = NULL;
		nodes[i].right = NULL;
	}

	/* Top Level */
	nodes[5].left =  &nodes[3];
	nodes[5].right = &nodes[7];
	/* Second Level */
	nodes[3].left =  &nodes[1];
	nodes[3].right = &nodes[4];
	nodes[7].left =  &nodes[6];
	nodes[7].right = &nodes[9];
	/* Third Level */
	nodes[1].left =  &nodes[0];
	nodes[1].right = &nodes[2];
	nodes[9].left =  &nodes[8];
	nodes[9].right = &nodes[10];
	/* Everything else is a leaf */

	return &nodes[5];
}

Tree_node * build_bad_tree(void)
{
	/* Allocate head */
	int n_nodes = 11;
	int i;
	Tree_node * nodes = (Tree_node *) malloc(n_nodes * sizeof(Tree_node));
	for( i = 0; i < n_nodes; i++ )
	{
		nodes[i].data  = i;
		nodes[i].left  = NULL;
		nodes[i].right = NULL;
	}

	/* Top Level */
	nodes[5].left =  &nodes[3];
	nodes[5].right = &nodes[7];
	/* Second Level */
	nodes[3].left =  &nodes[1];
	nodes[3].right = &nodes[6];
	nodes[7].left =  &nodes[6];
	nodes[7].right = &nodes[9];
	/* Third Level */
	nodes[1].left =  &nodes[0];
	nodes[1].right = &nodes[2];
	nodes[9].left =  &nodes[3];
	nodes[9].right = &nodes[10];

	return &nodes[5];
}

int main(void)
{
	Tree_node * good_test_tree = build_good_tree();
	Tree_node * bad_test_tree;

	int isBST = is_tree_iterative(good_test_tree);

	if( isBST )
		printf("Tree is valid!\n");
	else
		printf("Tree is invalid!\n");

	bad_test_tree = build_bad_tree();

	isBST = is_tree_iterative(bad_test_tree);

	if( isBST )
		printf("Tree is valid!\n");
	else
		printf("Tree is invalid!\n");


	return 0;
}
