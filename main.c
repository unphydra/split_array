#include "split_array.h"

int main(void)
{
  int numbers[] = {3,1,7,4,6,5,8,2};
  int range[] = {4,7};
  Split_Array *final = get_split_array_by_range(numbers,range,LENGTH(numbers));
  print_split_array(*final);
  return 0;
}