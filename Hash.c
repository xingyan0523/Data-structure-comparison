#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structure.h"

#define BUCKET_MAX 2153



int hash_func(int number){
    return number % BUCKET_MAX;
}

void hash_insert(struct list **bucket, int key){
    Linked_list_insert(bucket[hash_func(key)], key);
}

bool hash_search(struct list **bucket, int key){
    if(Linked_list_search(bucket[hash_func(key)], key))
        return true;    
    return false;
}