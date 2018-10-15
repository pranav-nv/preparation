#include <iostream>
#include <queue>          // std::queue
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "tree_defs.h"

#define TRUE 	1
#define FALSE	0

bool
tree_is_bst(Tree_t *node,Tree_t *prev_node)
{
	bool ret;
	if (!node) {
		return TRUE;
	}	
	if (prev_node) {
		if (node->val < prev_node->val) {
			return FALSE;
		}
	}
	ret = tree_is_bst(node->left,prev_node);
	if (ret == FALSE) {
		return ret;
	}
	prev_node = node;
	return tree_is_bst(node->right,prev_node);
}

int
main()
{
	bool ret;	
	Tree_t *root = tree_gen_random_bst(16);
	tree_print(root);
	ret = tree_is_bst(root,NULL);
	printf("is_bst() = %d\n",ret);
	
	root= tree_gen_random(5);
	tree_print(root);
	ret = tree_is_bst(root,NULL);
	printf("is_bst() = %d\n",ret);
}
