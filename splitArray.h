#ifndef __SPLIT_ARRAY_H_
#define __SPLIT_ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) (int)sizeof(a)/(int)sizeof(a[0])
#define O_BRACKET printf("[")
#define C_BRACKET printf("]")
#define COMA printf(",")
#define EMPTY_LINE printf("\n")

typedef int * Array;
typedef int ** Arrays;


typedef struct {
  Array list;
  int length;
} Dynamic_Array;

typedef struct
{
  Dynamic_Array ** list;
  int length;
}Split_Array;

Split_Array *get_split_array_by_range(Array,Array,int);
Split_Array *create_split_array(Array *, Array, int);
Dynamic_Array *copy_array_on_heap(Array,int);
void print_split_array(Split_Array);

#endif