// Example created by Mike during Office hours
//
#include <stdlib.h>

typedef struct DataStructure{
    int* dataHeldInStructure; // This is an array that holds the data
                              // in the data structure.
    int size;                 // This is how many items are in the 
                              // 'dataHeldInStructure' array.
    int capacity;             // This is how much memory, we've allocated
                              // for the 'dataHeldInStructure' array.
}DataStructure_t;


// So let's create a function to initialize this data structure
DataStructure_t* Create_DataStructure(unsigned int _capacity){
// In this code, initialize all the fields in the structs.
    DataStructure_t* newDS = (DataStructure_t*)malloc(sizeof(DataStructure_t)*1);
    newDS->size=0;
    newDS->capacity = _capacity;

    newDS->dataHeldInStructure = (int*)malloc(sizeof(int)*_capacity);

    return newDS;
}

// 1 if the Data Structure is empty
// 0 if it is not
int DataStructure_IsEmpty(DataStructure_t* ds){
    if(ds->size==0){
        return 1;
    }else{
        return 0;
    }
}

int main(){

    DataStructure_t* temp = Create_DataStructure(5);
    DataStructure_IsEmpty(temp);

    return 0;
}
