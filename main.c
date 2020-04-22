#include "splitArray.h"

int main(void)
{
  int numbers[] = {3,1 ,7, 4, 6 ,5 ,2};
  int range[] = {4,7};
  Split_Array *final = get_split_array_by_range(numbers,range,LENGTH(numbers));
  printf("%d",final->list[2]->list[0]);
  return 0;
}