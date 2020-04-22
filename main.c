#include "splitArray.h"

int main(void)
{
  int numbers[] = {3,1 ,7, 4, 6 ,5 ,8 ,2};
  int range[] = {4,7};
  // printf("%d",LENGTH(numbers));
  Split_Array *final = get_split_array_by_range(numbers,range,LENGTH(numbers));
  return 0;
}