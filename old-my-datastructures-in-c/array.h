#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include "common.h"

// Dynamic integer array
typedef struct
{
    int *parr;
    int capacity;
    int size;
} dynamic_array_struct;

// create an array
int* get_fixed_array();
// create a dynamic array, growable array, resizeable array, dynamic table, mutable array, or array list
dynamic_array_struct* create_dynamic_array(dynamic_array_struct *pdynarr, int capacity);

/// wasted space
bool resize_dynamic_array_capacity(dynamic_array_struct *pdynarr, const int capacity_requested);
void free_dynamic_array(int** pparr);

const int initialize_array(int *pdynarr, const int size, int ele_val_seed);
int print_array(int *parr, int size);

/// indexing
int  array_get_element_at(const int *parr, const int size, const int index);
bool array_set_element_at(int *parr, const int size, const int index, const int ele);
int  array_get_index_of(int *parr, const int size, const int ele);

/// insert/delete at begin
int array_insert_at_begin(dynamic_array_struct *pdynarr, const int ele);
int array_delete_at_begin(dynamic_array_struct *pdynarr);

/// insert/delete at end
int array_insert_at_end(dynamic_array_struct *pdynarr, const int ele);
int array_delete_at_end(dynamic_array_struct *pdynarr);

/// insert/delete at middle
int array_insert_at_middle(dynamic_array_struct *pdynarr, const int ele);
int array_delete_at_middle(dynamic_array_struct *pdynarr);

#endif // ARRAY_H_INCLUDED
