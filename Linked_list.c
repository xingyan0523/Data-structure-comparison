#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structure.h"

struct node;
struct list;

void Linked_list_insert(struct list *ll, int key){

    struct node *tmp = ll->head;
    struct node *new = malloc(sizeof(struct node));
    new->key = key;
    new->next = NULL;
    if(!(ll->head)){
        ll->head = new;
        ll->rear = new;
    } 
    else{
        ll->rear->next = new;
        ll->rear = new;
    }
}

bool Linked_list_search(struct list *ll, int key){
    struct node *tmp = ll->head;
    for(; tmp; tmp = tmp->next){
        if(tmp->key == key){
            return true;
        }
    }
    return false;
}