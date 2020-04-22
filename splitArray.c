#ifndef __SPLIT_ARRAY_C_
#define __SPLIT_ARRAY_C_

#include "splitArray.h"

Split_Array *get_split_array_by_range(Array num,Array range,int length)
{
  Split_Array * final;
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
  printf("%d %d %d\n",first[0],first[1],first[2]);
  printf("%d %d %d %d\n",second[0],second[1],second[2],second[3]);
  printf("%d",third[0]);
  return final;
}


#endif