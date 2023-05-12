#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int val;
    struct node *next;
} node;

node *create_node(void);
node *add_node(node *list, int val);
void display_list(node *list);
void free_list(node *list);
int delete(node **list, int val);
// node search(node *list);
// void insert(node *new_node);
// node *pop(node *list);

int main(void)
{
    node *list = create_node();
    for (int i = 1; i < 10; i++)
        add_node(list, i);
    

    display_list(list);
    printf("Deleted node value: %d\n", delete(&list, 0));
    display_list(list);

    free_list(list);
}

node *create_node(void)
{
    node *block = malloc(sizeof(node));
    if (block == NULL)
        return NULL;

    block->val = 0;
    block->next = NULL;
    return block;
}

node *add_node(node *list, int data)
{
    node *tmp = list;
    node *block = create_node();
    block->val = data;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = block;
    return list;
}

void display_list(node *list)
{
    if (list == NULL)
        return;

    int node_count = 1;

    while (list)
    {
        printf("Node %d: %d\n", node_count, list->val);
        list = list->next;
        node_count++;
    }
    
}

void free_list(node *list)
{
    if (list == NULL)
        return;
    
    free_list(list->next);
    free(list);
}

int delete(node **list, int val)
{   
    // tmp instead holds address of node->next instead of the literal node
    node **tmp = list;
    while ((*tmp)->val != val)
        tmp = &(*tmp)->next;
    
    node *del = *tmp;
    *tmp = (*tmp)->next;
    free(del);

    return (*tmp)->val;       
}