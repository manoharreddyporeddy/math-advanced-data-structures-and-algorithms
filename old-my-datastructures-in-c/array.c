#include "array.h"
/**
array
number of elements in specified order
They are accessed using an integer to specify which element required
(although the elements may be of almost any type).
Typical implementations allocate contiguous memory words for the elements of arrays
(but this is not always a necessity).
Arrays may be fixed-length or expandable.
*/

int print_array(int *parr, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", parr[i]);
    }

    printf("\n");
    return 1;
}

// static allocates memory & also initializes an array
int* get_fixed_array()
{
    //        int arr[pdynarr->size];            // expected constant expression
    // static int arr[pdynarr->size];            // error: storage pdynarr->size of 'arr' isn't constant|
    // static int arr[pdynarr->size] = {0};    // error: variable-sized object may not be initialized|
    // static int arr[pdynarr->size] = {0};   // error C2057: expected constant expression
    // static int arr[5] = { 0 };            // OK
    //      preallocated space in the data section of the program
    static int arr[5];

    return arr;
}

/// Dynamic Allocates memory & also initializes an array
dynamic_array_struct* create_dynamic_array(dynamic_array_struct *pdynarr, int capacity)
{
    assert(capacity > 0);
    void* _parr=malloc(sizeof(int)*capacity);
    if (_parr)
    {
        pdynarr->parr=_parr;
        pdynarr->capacity=pdynarr->size=capacity;
    }

    return pdynarr;
}

/// initializes integer array with 'init_value_from' till 'init_value_from' + size, for size elements
const int initialize_array(int *parr, const int size, int init_value_from)
{
    int i;
    for (i=0; i<size; i++)
    {
        parr[i] = init_value_from + i;
    }

    return i;
}

/// wasted space
/// O(n)
bool resize_dynamic_array_capacity(dynamic_array_struct *pdynarr, const int capacity_requested)
{
    int capacity_projected_required = 2 * pdynarr->capacity; // lets double memory each time, hope new requested cap is less than this

    if (capacity_requested > capacity_projected_required)            // higher than existing
    {
        capacity_projected_required = capacity_requested;
    }
    else if (capacity_requested < (2/3)*pdynarr->capacity)    // lot lesser than existing, lets reduce memory
    {
        capacity_projected_required = (2/3)*pdynarr->capacity;
    }
    else if (pdynarr->capacity > capacity_requested)            // higher than existing
    {
        return true;    // nothing to do
    }

    int* parr_temp = realloc(pdynarr->parr, sizeof(int)*capacity_projected_required);  // pdynarr->parr will have garbage for the new elements at the end
    if (parr_temp)
    {
        pdynarr->capacity = capacity_projected_required;
        // print_array(parr_temp, pdynarr->size);
        return true;
    }

    return false;
}

/// Free memory of a pointer and also sets to NULL
void free_dynamic_array(int **pparr)
{
    if (*pparr)
    {
        free (*pparr);
        *pparr = NULL;
    }
}

/// array_get_element_at
/// O(1)
int array_get_element_at(const int *parr, const int size, const int index)
{
    if ( (index>=0) && (index<size) )
    {
        return parr[index];                // works
        // return index[pdynarr->parr];    // works too-    ->  a+b = b+a // commutative
    }
    else
    {
        printf("array_get_element_at: invalid index\n");
        return -1;
    }
}

/// array_set_element_at
/// O(1)
bool array_set_element_at(int *parr, const int size, const int index, const int ele)
{
    if ((index>=0) && (index<size))
    {
        parr[index] = ele;
        return true;
    }
    else
    {
        printf("array_set_element_at: invalid index\n");
        return false;
    }
}

/// array_get_index_of
/// O(n)
int array_get_index_of(int *parr, const int size, const int ele)
{
    int i;
    for (i=0; i<size; i++)
    {
        if (parr[i] == ele)
            break;
    }

    if (i == size)
    {
        printf("array_get_index_of: element not found\n");
        return -1;
    }

    return i;
}
// ---------------

int* right_shift_dynamic_array(dynamic_array_struct *pdynarr, int begin_index, int end_index)
{
    if (!end_index)
        end_index = pdynarr->size-1;

    // move elements to right by 1, from begin_index to end_index of array
    for (int i=end_index; i>=begin_index; i--)
    {
        pdynarr->parr[i+1] = pdynarr->parr[i];
    }
    pdynarr->size++;

    pdynarr->parr[begin_index] = 0;
    return pdynarr->parr;
}

int* left_shift_dynamic_array(dynamic_array_struct *pdynarr, int begin_index, int end_index)
{
    if (!end_index)
        end_index = pdynarr->size-1;

    // move elements to left by 1, from begin_index to end_index of array
    for (int i=begin_index; i<=end_index; i++)
    {
        pdynarr->parr[i] = pdynarr->parr[i+1];
    }
    pdynarr->size--;

    pdynarr->parr[end_index] = 0;
    return pdynarr->parr;
}

/// array_insert_at_begin
/// O(n)
int array_insert_at_begin(dynamic_array_struct *pdynarr, const int ele)
{
    myprintf20("array_insert_at_begin: ");
    // print_array(pdynarr->parr, pdynarr->size);

    if (resize_dynamic_array_capacity(pdynarr, pdynarr->size+1))
    {
        right_shift_dynamic_array(pdynarr,0,0);

        pdynarr->parr[0] = ele;
        print_array(pdynarr->parr, pdynarr->size);
    }
    return pdynarr->size;
}

/// array_insert_at_end
/// O(1)
int array_insert_at_end(dynamic_array_struct *pdynarr, const int ele)
{
    myprintf20("array_insert_at_end: ");
    // print_array(pdynarr->parr, pdynarr->size);

    if (resize_dynamic_array_capacity(pdynarr, pdynarr->size+1))
    {
        pdynarr->parr[pdynarr->size] = ele;
        pdynarr->size++;
        print_array(pdynarr->parr, pdynarr->size);
    }

    return pdynarr->size;
}

/// array_insert_at_middle
/// O(n)
int array_insert_at_middle(dynamic_array_struct *pdynarr, const int ele)
{
    myprintf20("array_insert_at_middle: ");
    // print_array(pdynarr->parr, pdynarr->size);

    if (resize_dynamic_array_capacity(pdynarr, pdynarr->size+1))
    {
        int middle_index = pdynarr->size / 2;
        right_shift_dynamic_array(pdynarr, middle_index, 0);

        pdynarr->parr[middle_index] = ele;
        print_array(pdynarr->parr, pdynarr->size);
    }
    
    return pdynarr->size;
}


/// array_delete_at_begin
/// O(n)
int array_delete_at_begin(dynamic_array_struct *pdynarr)
{
    myprintf20("array_delete_at_begin: ");
    // print_array(pdynarr->parr, pdynarr->size);

    left_shift_dynamic_array(pdynarr,0,0);
    resize_dynamic_array_capacity(pdynarr, pdynarr->size-1);  // TODO: is resize needed? yes, if deleted many times then significant mem is wasted

    print_array(pdynarr->parr, pdynarr->size);
    return pdynarr->size;
}

/// array_delete_at_end
/// O(1)
int array_delete_at_end(dynamic_array_struct *pdynarr)
{
    myprintf20("array_delete_at_end: ");
    // print_array(pdynarr->parr, pdynarr->size);
    
    pdynarr->size--;
    resize_dynamic_array_capacity(pdynarr, pdynarr->size-1);
    
    print_array(pdynarr->parr, pdynarr->size);
    return pdynarr->size;
}

/// array_delete_at_middle
/// O(n)
int array_delete_at_middle(dynamic_array_struct *pdynarr)
{
    myprintf20("array_delete_at_middle: ");

    int middle_index = pdynarr->size / 2;
    left_shift_dynamic_array(pdynarr, middle_index, 0);

    resize_dynamic_array_capacity(pdynarr, pdynarr->size-1);    // ??
    
    print_array(pdynarr->parr, pdynarr->size);
    return pdynarr->size;
}
