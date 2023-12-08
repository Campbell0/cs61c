/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "ex6_vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Create a new vector with a size (length) of 1 and set its single component to zero... the
   right way */
/* TODO: uncomment the code that is preceded by // */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *v = (vector_t*)malloc(sizeof(vector_t));

    /* First, we need to allocate memory on the heap for the struct */

    /* Check our return value to make sure we got memory */
    if (v == NULL) {
        allocation_failed();
    }

    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
    v->size = 1;
    v->data = (int*)malloc(sizeof(int));

    /* Check the data attribute of our vector to make sure we got memory */
    if (v->data == NULL) {
        free(v);				//Why is this line necessary?
        allocation_failed();
    }

    /* Complete the initialization by setting the single component to zero */
    v->data[0] = 0;

    /* and return... */
    return v; /* UPDATE RETURN VALUE */ //
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if(v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    size_t len = v->size;
    if(len > loc + 1) {
        return v->data[loc];
    }
    return 0;
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    /* 以下是vector_delete函数的注释:
       该函数用于删除一个vector_t结构体指针所指向的向量。
       函数首先释放向量中的数据，然后释放向量结构体本身。
    */
    /* YOUR CODE HERE */
    // 首先释放向量中的数据
    free(v->data);

    // 然后释放向量结构体本身
    free(v);
}

/* Set a value in the vector, allocating additional memory if necessary. 
   If the extra memory allocation fails, call allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */

    /* YOUR CODE HERE */
    size_t len = v->size;
    if(len <= loc) {
        size_t new_size = loc + 1;
        int *new_data = (int*)realloc(v->data,new_size * sizeof(int));
        if(new_data == NULL) {
            allocation_failed();
        }

        for(int i = len; i < new_size; ++i) {
            new_data[i] = 0;
        }
        new_data[loc] = value;
        v->size = new_size;
        v->data = new_data;
    }
    v->data[loc] = value;
}
