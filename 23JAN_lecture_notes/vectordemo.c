#include <stdio.h>
#include <stdlib.h>

struct int_vector{
  int *contents;
  size_t allocated_space;
  size_t current_size;
};

void init_vector(struct int_vector *v, size_t initial_capacity){
  v->contents = malloc(initial_capacity * sizeof(int));
  v->allocated_space = initial_capacity;
  v->current_size = 0;
}

//realloc allows us to expand when the malloc may require a new space
void push_back(struct int_vector *v, int new_number){
  if (v->allocated_space <= v-> current_size) {
    v->allocated_space *= 2;
    v->contents = realloc(v->contents, v->allocated_space * sizeof(int));
  }
  v->contents[v->current_size++] = new_number;
}

int popback(struct int_vector *v){
  //what if the vector's empty?
if(!v->current_size)
    return 0;       // transparent zero *shrug*
  return v->contents[--v->current_size];
}

void deallocate_vector(struct int_vector *v){
  free(v->contents);
}

int main(){
  struct int_vector iv;
  init_vector(&iv, 3);
  push_back(&iv, 5);
  push_back(&iv, 12);
  push_back(&iv, 3);
  push_back(&iv, 8);
  push_back(&iv, 17);
  push_back(&iv, 23);

  for (int i = 0; i < iv.current_size; i++){
    printf("%d", iv.contents[i]);
  }

  
  int i = 48;
top:
  push_back(&iv, i);
  i += 3;
  if(i < 70)
    goto top;
second_top:
    printf("%d, ", iv.contents[i]);
  i++;
  if(i < iv.current_size)
    goto second_top;
  printf("]\n");

  return 0;
}

/* test w/ valgrind */
