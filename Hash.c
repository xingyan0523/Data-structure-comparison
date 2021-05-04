#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structure.h"

#define BUCKET_MAX 2153

struct bucket;

int hash_func(int number){
    return number % BUCKET_MAX;
}

void hash_insert(struct bucket *bk1, int key){
    if(bk1->arr[hash_func(key)] != -1){
        struct node *new = malloc(sizeof(struct node));
        new->key = key;
        new->next = NULL;
        struct node *tmp = bk1->link[hash_func(key)];
        if(!tmp){
            bk1->link[hash_func(key)] = new;
        }
        else{
            while(tmp->next){
                tmp = tmp->next;
            }
            tmp->next = new;
        }
        
    }
    else{
        bk1->arr[hash_func(key)] = key;
    }
}

bool hash_search(struct bucket bk1, int key){
    if(bk1.arr[hash_func(key)] == key){
        return true;
    }
    struct node *tmp = bk1.link[hash_func(key)];
    while(tmp){
        if(tmp->key == key)
            return true;
        tmp = tmp->next;
    }
    return false;
}