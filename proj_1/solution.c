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
int find_best(void* fp_list, int f_param, size_t num_fps){
  int best_idx = 0;
  int best_res = 0;
  for(int i=0; i<num_fps; i++){
    printf("fp_list value at idx: %x", ((int*)fp_list)[i]);
  }

  return best_idx;
}

int main() {
  struct bundle_struct bunst;
  bunst.sorted_copy = sorted_copy;
  bunst.combine = combine;
  bunst.find_best = find_best;

  test(&bunst);
	
  return 0;
}