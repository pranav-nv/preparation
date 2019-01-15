#include "string.h"
#include "stdlib.h"
#include <iostream> 
#include <unordered_map> 
using namespace std; 

typedef struct trie_node_ trie_node_t;

struct trie_node_ {
    unordered_map<char,trie_node_t*> children;
    bool isword;
};


void 
trie_add(trie_node_t *root, char *str)
{
    trie_node_t *t_node = root;

    while (*str) {
        if (t_node->children.find(*str) == t_node->children.end()) {
            //key does not exist
            trie_node_t *new_t_node = new trie_node_t;
            t_node->children[*str] = new_t_node;
        }
        t_node = t_node->children[*str];
        if (*(str+1) == 0) {
            t_node->isword = 1;
        }
        str++;
    }
}

void
trie_print_subtree(trie_node_t *root, char *wordsofar,int len)
{
    if (root->children.size() == 0) {
        return;
    }

    for (auto key: root->children) {
        wordsofar[len] = key.first;
        if (key.second->isword) {
            printf("%s\n",wordsofar);
        }
        trie_print_subtree(key.second,wordsofar,len+1);
        wordsofar[len] = 0;
    }
}

void 
trie_print_all_substings_with_prefix(trie_node_t *root,char *prefix)
{
    trie_node_t *t_node = root;
    char *pr_ptr = prefix;
    if (!root) {
        return;
    }
    while(*pr_ptr) {
        if (t_node->children.find(*pr_ptr) == t_node->children.end()) {
            break;
        }
        t_node = t_node->children[*pr_ptr];
        pr_ptr++;
    }
    char str[32];
    strcpy(str,prefix);
    trie_print_subtree(t_node,str,strlen(str));
}

int main() 
{ 
    trie_node_t *root = new trie_node_t;
    
    trie_add(root,(char *)"AB"); 
    trie_add(root,(char *)"ABC"); 
    trie_add(root,(char *)"ABCD"); 
    trie_add(root,(char *)"ABCDE"); 
    trie_add(root,(char *)"ABD"); 
    trie_add(root,(char *)"ABK"); 
    trie_add(root,(char *)"DCE"); 
    trie_add(root,(char *)"DCX"); 
    //char wordsofar[32]={0};
    //trie_print_subtree(root,wordsofar,0);

    printf("\n\n\n");
    trie_print_all_substings_with_prefix(root,(char *)"AB");
    printf("\n\n\n");
    trie_print_all_substings_with_prefix(root,(char *)"DCE");
#if 0
    // Traversing an unordered map 
    for (auto x : umap) 
      cout << x.first << " " << x.second << endl; 
#endif

}
