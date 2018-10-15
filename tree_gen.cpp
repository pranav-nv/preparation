#include <iostream>
#include <queue>          // std::queue
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "tree_defs.h"

Tree_t *
tree_insert_node_bst(Tree_t *node_in,int val)
{
	Tree_t *node = node_in;
	if (node == NULL) {
		Tree_t *new_node = (Tree_t *) calloc(sizeof(Tree_t),1);
		new_node->val = val;
		return new_node;
	} 
	if (node->val > val) {
		node->left = tree_insert_node_bst(node->left,val);
	} else if (node->val <= val){
		node->right = tree_insert_node_bst(node->right,val);
	}
	return node;
}

Tree_t *
tree_insert_node_random(Tree_t *node_in,int val)
{
	Tree_t *node = node_in;
	if (node == NULL) {
		Tree_t *new_node = (Tree_t *) calloc(sizeof(Tree_t),1);
		new_node->val = val;
		return new_node;
	} 
	if (rand() %2) {
		node->left = tree_insert_node_random(node->left,val);
	} else {
		node->right = tree_insert_node_random(node->right,val);
	}
	return node;
}

void 
tree_print(Tree_t *node)
{
	std::queue<Tree_t *> Q;
	Q.push(node);	
	Q.push(NULL);	
	while(!Q.empty()) {
		Tree_t *node;
		node = Q.front();
		Q.pop();
		if (!node) {
			printf("\n");	
			if (!Q.empty()) {
				Q.push(NULL);	
			}
			continue;
		}
		printf(" %d ",node->val);
		if (node->left) 
			Q.push(node->left);	
		if (node->right) 
			Q.push(node->right);	
	}
}

Tree_t *
tree_gen_random_bst(int node_count)
{
	Tree_t *root = NULL;	
	int i;	
	srand(time(NULL));

	for (i=0;i<node_count;i++) {
		int val=rand()%100;	
		root = tree_insert_node_bst(root,val);
	}
	return root;
}

Tree_t *
tree_gen_random(int node_count)
{
	Tree_t *root = NULL;	
	int i;	
	srand(time(NULL));

	for (i=0;i<node_count;i++) {
		int val=rand()%100;	
		root = tree_insert_node_random(root,val);
	}
	return root;
}

#if 0
int main()
{
	Tree_t *root = tree_gen_random_bst(16);
	tree_print(root);
}
#endif
