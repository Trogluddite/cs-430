#include<stdio.h>
#include<pthread.h>

unsigned int fib(int x){
  if (x < 2) {
      return 1;
  }
  else
    return fib(x-1) + fib(x-2);
}

void *thread_function(void* parameter){
  fib(*(int*)parameter);
}

int main() {
  pthread_t t;
  int thread_param = 45;
  pthread_create(&t, 0, thread_function, &thread_param);
  prinitf("%d\n", fib(45));
  pthread_join(t, 0);
  prinitf("The thread calculated %d\n", thread_param);
  return 0;
}

