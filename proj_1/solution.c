/* This one is for you to finish!  Have fun! */
#include "tester.h"
#include <stdio.h>
#include <stdlib.h>


int* sorted_copy(int* source_arr, size_t alen){
  //copy the source_arr
  int* sorted = malloc( sizeof(source_arr[0]) * alen);
  for(int i=0; i < alen; i++){
    sorted[i] = source_arr[i];
  }
  // I am advanced prograemar
  // I am bubble sort them baubles
  int sortlen = alen-1;
  while(sortlen > 0){
    int slice_idx = 0;
    while(slice_idx < sortlen){
      if(sorted[slice_idx] > sorted[slice_idx +1]){
        int t = sorted[slice_idx];
        sorted[slice_idx] = sorted[slice_idx + 1];
        sorted[slice_idx + 1] = t;
      }slice_idx++;
    }sortlen--;
  }
  return sorted;
}

int combine(int, int){
  return 0;
}
int find_best(void*, int, size_t){
  return 0;
}

int main() {
  struct bundle_struct bunst;
  bunst.sorted_copy = sorted_copy;
  bunst.combine = combine;
  bunst.find_best = find_best;

  int sortme[6] = {34,43,51,67,91,100};
  size_t arrlen = sizeof(sortme) / sizeof(sortme[0]);
  //int* sorted = bs.sorted_copy(sortme, arrlen);
  test(&bunst);
	
  return 0;
}
