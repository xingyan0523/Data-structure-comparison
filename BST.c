#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structure.h"

struct BSTnode;

struct BSTnode *BST_insert(struct BSTnode *root, int key){
    struct BSTnode *new = malloc(sizeof(struct BSTnode));
    new->key = key;
    new->left = NULL;
    new->right = NULL;

    if(!root){
        return new;
    }
    struct BSTnode *tmp = root;

    while(tmp){
        if(key > tmp->key){
            if(tmp->right)
                tmp = tmp->right;
            else{
                tmp->right = new;
                break;
            }
        }
        else{
            if(tmp->left)
                tmp = tmp->left;
            else{
                tmp->left = new;
                break;
            }
        }
    }
    return root;
}

bool BST_search(struct BSTnode *root, int key){
    if(!root){
        return false;
    }
    struct BSTnode *tmp = root;

    while(tmp){
        if(key > tmp->key){
            if(tmp->right)
                tmp = tmp->right;
            else
                break;
        }
        else if(key < tmp->key){
            if(tmp->left)
                tmp = tmp->left;
            else
                break;
        }
        else{
            return true;
        }
    }
    return false;
}
