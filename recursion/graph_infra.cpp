#include <iostream>
#include <map>

using namespace std;

typedef struct graph_node_ {
    list<graph_node_t> neighbors; 
    int label;
}graph_node_t'


graph_node_t
graph_node_create(int node_label)
{
    return (new graph_node_t);
}


#if 0
template <int>
void
graph_create(graph_node_t my_node,initializer_list<int> list_neighbor)
{
    
}
#endif


