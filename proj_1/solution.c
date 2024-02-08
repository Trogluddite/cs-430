/* This one is for you to finish!  Have fun! */
#include "tester.h"
#include <stdlib.h>

int find_best(void* fp_list, int f_param, size_t num_fps){
  int best_idx = 0;
  int best_res = 0;
  int curr_idx = 0;
  // de-referencing & casting fp_list -- (**cfunc) is a pointer-to-pointer; returns int; takes int param
  // iteration comparison: cfunc's address is < (fp_list's address + number of iteratiions * size of first value in cfunc
  // cfunc++ increases address value by word-size? sizeof(*cfunc), I think?
  for (int (**cfunc)(int) = fp_list; cfunc < fp_list + (num_fps * sizeof(*cfunc)); cfunc++){
    int tf_res = (*cfunc)(f_param);
    if(tf_res > best_res){
      best_res = tf_res;
      best_idx = curr_idx;
    }
    curr_idx++;
  }
  return best_idx;
}

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

// or both ints
// shift three places right
// change last byte to all zeros
int combine(int a, int b){
  int or_res = a | b;
  int shift_res = (or_res >> 3);
  int end_byte_zeros_mask = (~0) << 8;
  return shift_res & end_byte_zeros_mask;
}

int main() {
  struct bundle_struct bunst;
  bunst.sorted_copy = sorted_copy;
  bunst.combine = combine;
  bunst.find_best = find_best;

  test(&bunst);
	
  return 0;
}
