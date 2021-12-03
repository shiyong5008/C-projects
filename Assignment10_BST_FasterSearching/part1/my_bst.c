// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Modify the body of this function as needed.
    bst_t* myBST= NULL; 

    myBST = (bst_t*)malloc(sizeof(bst_t));
    
    if (myBST != NULL)
    {
        myBST->size = 0;
        myBST->root = NULL;
    }

    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    if (t->size == 0) {
        return 1;
    }

    return 0;
}

// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item) {
    if (t->root == NULL)                        
    {
        
        t->root = (bstnode_t*)malloc(sizeof(bstnode_t));
        
        if (t->root != NULL)
        {
            t->root->data = item;
            t->root->leftChild = t->root->rightChild = NULL;
            return 1;
        }
    }
    else if (t->root->data == item) {
        return 1;
    }
    else if (t->root->data > item) {
        bstnode_t* r;

        r = t->root->leftChild;
        if (r == NULL) {
            r = (bstnode_t*)malloc(sizeof(bstnode_t));
        }
        if (r != NULL)
        {
            r->data = item;
            r->leftChild = t->root->rightChild = NULL;

            return 1;
        }
    }
    else if (t->root->data < item) {
        bstnode_t* r;

        r = t->root->rightChild;
        if (r == NULL) {
            r = (bstnode_t*)malloc(sizeof(bstnode_t));
        }
        if (r != NULL)
        {
            r->data = item;
            r->leftChild = t->root->rightChild = NULL;

            return 1;
        }
    }
        return -1;
    
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    }else{

    }
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
    bstnode_t* s = t->root;

    if (s != NULL) {
        return s->data;
    }
  return 0;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
    bstnode_t* s = t->root;

    while (s != NULL) {
        if (value == s->data) {
            return 1;
        }
        else if (value < s->data)
            s = s->leftChild;
        else
            s = s->rightChild;
    }

  return 0;
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){

    if (NULL == t) {
        return 0;
    }
    
    return t->size;
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
    if (t != NULL) {
        free(t);
    }
}
