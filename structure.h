#ifndef structure
#define structure
#define BUCKET_MAX 2153
#include <stdbool.h>

struct node{
    int key;
    struct node *next;
};

struct list{
    struct node *head;
    struct node *rear;
};

struct Array{
    int *first;
    int rear;
};

struct BSTnode{
    int key;
    struct BSTnode *left, *right;
};



void Linked_list_insert(struct list *ll, int key);
bool Linked_list_search(struct list *ll, int key);

void Array_insert(struct Array *arr, int key);
bool Array_search(struct Array *arr, int key);
void swap(int* a, int* b);
int partition (int *arr, int low, int high);
void quickSort(int *arr, int low, int high);

struct BSTnode *BST_insert(struct BSTnode *root, int key);
bool BST_search(struct BSTnode *root, int key);

int hash_func(int number);
void hash_insert(struct list **bucket, int key);
bool hash_search(struct list **bucket, int key);


#endif