#ifndef __SPLIT_ARRAY_C_
#define __SPLIT_ARRAY_C_

#include "splitArray.h"

Dynamic_Array *copy_array_on_heap(Array num,int length)
{
  Array list = malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++)
  {
    list[i] = num[i];
  }
  Dynamic_Array * final = malloc(sizeof(Dynamic_Array));
  final->length = length;
  final->list = list;
  return final;
}

Split_Array *create_split_array(Array *numbers, Array sizes, int length)
{
  Dynamic_Array ** list = malloc(sizeof(Dynamic_Array *) *length);
  for (int i = 0; i < length; i++)
  {
    list[i] = copy_array_on_heap(numbers[i],sizes[i]);
  }
  Split_Array * final = malloc(sizeof(Split_Array));
  final->list = list;
  final->length = length;
  return final;
}

Split_Array *get_split_array_by_range(Array num,Array range,int length)
{
  int first[length];
  int count_f = 0;
  int second[length];
  int count_s = 0;
  int third[length];
  int count_t = 0;
  for (int i = 0; i < length; i++)
  {
    if(num[i]<range[0]){
      first[count_f] = num[i];
      count_f++;
      continue;
    }
    if(num[i]>range[1]){
      third[count_t] = num[i];
      count_t++;
      continue;
    }
    second[count_s] = num[i];
    count_s++;
  }
  Array result[] = {first,second,third};
  int sizes[] =  {count_f,count_s,count_t};
  return create_split_array(result,sizes, 3);
}


#endif