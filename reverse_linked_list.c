/*
 *
 *
 * Tags: Recursion, Linked List
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ Node_t;

struct Node_ {
    int a;
    Node_t *next;
};



void
reverseLL(Node_t **head,Node_t *prev, Node_t *cur)
{
    if (cur == NULL) {
        *head = prev;
        return;
    }

    reverseLL(head, cur, cur->next);
    cur->next = prev;
}


Node_t *
addNode(Node_t *cur, int new_node_val)
{
    Node_t *new_node = malloc(sizeof(Node_t));
    new_node->a = new_node_val;
    new_node->next = NULL;
    if (cur) {
        cur->next = new_node;
    }
    return new_node;
}

void
traverseNodes(Node_t *head)
{
    Node_t *cur = head;
    while (cur) {
        printf ("%d -> ",cur->a);
        cur = cur->next;
    }
    printf("NULL\n");
}

void
reverseLL_iterative(Node_t **head_in)
{
    Node_t *prev, *cur, *next;


    prev = NULL;
    cur = *head_in;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head_in = prev;
}

int
main()
{
    Node_t *head = addNode(NULL,1);
    addNode(addNode(addNode(addNode(addNode(addNode(head,2),3),4),5),6),7);
    traverseNodes(head);
    reverseLL(&head,NULL,head);
    traverseNodes(head);
    reverseLL_iterative(&head);
    traverseNodes(head);
}
