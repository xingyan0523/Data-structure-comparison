#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include "structure.h"

enum type{
    BST, BS, ARR, LL, HASH
};

/*
-d N (required) 插入的資料筆數，每筆資料是唯一的 (1e4, 1e5, 1e6)
-q M (required) 查詢資料筆數 (1e3, 1e4, 1e5)
-bst: 測量BST建立和查詢所需時間
-bs:  測量 Binary Search建立資料結構(含 sorting) 和查詢所需時間
-arr: 測量 array 建立資料結構和查詢(linear search)所需時間
-ll: 測量 linked list 建立資料結構和查詢所需時間
-hash 測量 hash 建立資料結構和查詢所需時間
*/


int main (int argc, char **argv){
    unsigned int testcase_ins, testcase_qry;
    bool bst, bs, arr, ll, hash;
    bst = bs = arr = ll = hash = false;
    struct timeval start, end;
    unsigned long diff;

    time_t **result = malloc(sizeof(time_t*) * 2);
    for(int i = 0; i < 2; i++){
        result[i] = malloc(sizeof(time_t) * 5);
    }

    for(int i = 1; i < argc; i++){
        if(!strcmp(argv[i], "-d")){
            i++;
            switch(argv[i][2]){
                case '4': testcase_ins = 10000; break;
                case '5': testcase_ins = 100000; break;
                case '6': testcase_ins = 1000000; break;
            }
        }
        else if(!strcmp(argv[i], "-q")){
            i++;
            switch(argv[i][2]){
                case '3': testcase_qry = 1000; break;
                case '4': testcase_qry = 10000; break;
                case '5': testcase_qry = 100000; break;
            }
        }
        else if(!strcmp(argv[i], "-bst"))
            bst = true;
        else if(!strcmp(argv[i], "-bs"))
            bs = true;
        else if(!strcmp(argv[i], "-arr"))
            arr = true;
        else if(!strcmp(argv[i], "-ll"))
            ll = true;
        else if(!strcmp(argv[i], "-hash"))
            hash = true;
    }

    start.tv_usec = end.tv_usec = 0;
    gettimeofday(&start, NULL);
    bool *unique = malloc(sizeof(bool) * RAND_MAX);
    int *insert = malloc(sizeof(int) * testcase_ins);
    int *query = malloc(sizeof(int) * testcase_qry);

    srand(0);

    for(int i = 0; i < testcase_ins; i++){
        int num = rand();
        if(unique[num])
            i--;
        else{
            insert[i] = num; 
            unique[num] = true;
        }
    }
    for(int i = 0; i < testcase_qry; i++){
        query[i] = rand(); 
    }
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("%lf\n", diff / 1000000.0);
    
    
    if(ll){
        start.tv_usec = end.tv_usec = 0;
        printf("ll:\n");
        gettimeofday(&start, NULL);
        struct list list1;
        list1.head = NULL;
        list1.rear = NULL;
        for(int i = 0; i < testcase_ins; i++){
            Linked_list_insert(&list1, insert[i]);
        }

        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %lf sec\n", diff / 1000000.0);
        

        gettimeofday(&start, NULL);
        for(int i = 0; i < testcase_qry; i++){
            if(Linked_list_search(&list1, query[i]))
                printf("%d ", query[i]);
            
        }
        printf("\n");
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %lf sec\n", diff / 1000000.0);
    }
    
    if(arr){
        start.tv_usec = end.tv_usec = 0;
        printf("arr:\n");
        gettimeofday(&start, NULL);
        struct Array array;
        array.first = malloc(sizeof(int) * testcase_ins);
        array.rear = 0;
        for(int i = 0; i < testcase_ins; i++){
            Array_insert(&array, insert[i]);
        }
        
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %lf sec\n", diff / 1000000.0);

        gettimeofday(&start, NULL);
        for(int i = 0; i < testcase_qry; i++){
            if(Array_search(&array, query[i]))
                printf("%d ", query[i]);
        }
        printf("\n");
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %lf sec\n", diff / 1000000.0);
        free(array.first);
    }

    if(bs){
        start.tv_usec = end.tv_usec = 0;
        printf("bs:\n");
        gettimeofday(&start, NULL);
        struct Array array;
        array.first = malloc(sizeof(int) * testcase_ins);
        array.rear = 0;
        for(int i = 0; i < testcase_ins; i++){
            Array_insert(&array, insert[i]);
        }
        quickSort(array.first, 0, testcase_ins - 1);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %lf sec\n", diff / 1000000.0);

        gettimeofday(&start, NULL);

        for(int i = 0; i < testcase_qry; i++){
            if(Array_search(&array, query[i]))
                printf("%d ", query[i]);
        }
        printf("\n");
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %lf sec\n", diff / 1000000.0);
        free(array.first);
    }

    if(bst){
        start.tv_usec = end.tv_usec = 0;
        printf("bst:\n");
        gettimeofday(&start, NULL);
        struct BSTnode *root = NULL;
        for(int i = 0; i < testcase_ins; i++){
            root = BST_insert(root, insert[i]);
        }
        
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %lf sec\n", diff / 1000000.0);

        gettimeofday(&start, NULL);
        for(int i = 0; i < testcase_qry; i++){
            if(BST_search(root, query[i]))
                printf("%d ", query[i]);
        }
        printf("\n");
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %lf sec\n", diff / 1000000.0);
    }

    if(hash){
        start.tv_usec = end.tv_usec = 0;
        printf("hash:\n");
        gettimeofday(&start, NULL);
        struct bucket bucket1;
        bucket1.arr = malloc(sizeof(int) * BUCKET_MAX);
        bucket1.link = malloc(sizeof(struct node*) * BUCKET_MAX);

        for(int i = 0; i < BUCKET_MAX; i++){
            bucket1.arr[i] = -1;
            bucket1.link[i] = NULL;
        }
        
        for(int i = 0; i < testcase_ins; i++){
            hash_insert(&bucket1, insert[i]);
        }

        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("building time: %lf sec\n", diff / 1000000.0);

        gettimeofday(&start, NULL);

        for(int i = 0; i < testcase_qry; i++){
            if(hash_search(bucket1, query[i]))
                printf("%d ", query[i]);
        }
        printf("\n");

        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("query time: %lf sec\n", diff / 1000000.0);
    }
    return 0;
}