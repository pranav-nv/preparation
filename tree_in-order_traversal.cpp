#include <iostream>
#include <queue>          // std::queue
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#include "tree_defs.h"

void
tree_in_order(Tree_t *node)
{
	if (!node) {
		return;		
	}	
	tree_in_order(node->left);
	printf(" %d ",node->val);	
	tree_in_order(node->right);
}

int
main()
{
	Tree_t *root = tree_gen_random_bst(16);
	tree_print(root);
	tree_in_order(root);
}
