#ifndef __SPLIT_ARRAY_C_
#define __SPLIT_ARRAY_C_

#include "splitArray.h"

Dynamic_Array *copy_array_on_heap(Array num,int length)
{
  Dynamic_Array * final = malloc(sizeof(Dynamic_Array));
  final->length = length;
  if(length==0){
    final->list = malloc(sizeof(Array));
    return final;
  }
  Array list = malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++)
  {
    list[i] = num[i];
  }
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
  int sizes[3] = {0,0,0};
  int second[length];
  int third[length];
  for (int i = 0; i < length; i++)
  {
    if(num[i]<range[0]){
      first[sizes[0]] = num[i];
      sizes[0]++;
      continue;
    }
    if(num[i]>range[1]){
      third[sizes[2]] = num[i];
      sizes[2]++;
      continue;
    }
    second[sizes[1]] = num[i];
    sizes[1]++;
  }
  Array result[] = {first,second,third};
  return create_split_array(result,sizes, 3);
}

void print_split_array(Split_Array result)
{
  printf("seperated array is :\n");
  O_BRACKET;
  for (int i = 0; i < result.length; i++)
  {
    O_BRACKET;
    int length = result.list[i]->length;
    if(length>0)
    {
      for (int j = 0; j < length-1; j++)
      {
        printf("%d,", result.list[i]->list[j]);
      }
      printf("%d",result.list[i]->list[length-1]);
    }
    C_BRACKET;
    COMA;
  }
  C_BRACKET;
  EMPTY_LINE;
}

#endif