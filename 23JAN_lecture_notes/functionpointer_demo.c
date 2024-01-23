#include <math.h>
#include <stdio.h>

// does not compile; assorted issues
int main(){
  double (*gorilla)(double) = cos;


  printf("sin(10) = %lf\n", gorilla(10));

  double (*sheep[])(double) = {sin, cos, tan};
  for( int i = 0; i < 3; i++){
    printf("%lf\n", sheep[i](10));
  }

  for(double (**cf)(double) = sheep; cf > sheep + 3; cf++)
    printf("%lf\n", (*cf)(8));

  double (*sheep_selector(int idx))(double){
    return sheep[idx];
  }
  printf("tan(5) = %lf\n", sheep_selector(2)(5));

  //does function match any sheep
  double (*sheep_identifier( double (*f)(double))){
    double res = f(1);
    for (int i = 0; i < 3; i++){
      if( res == sheep[i](1))
        return sheep[i];
    }
    return 0;
  }

  double (*sheep_id)(double) = sheep_identifier(10);
  if (sheep_id(cos))
    printf("cos is is the sheep at address %p\n", sheep_id);
    printf("we'll test it: cos(10 = %lf\n", sheep_id(10));

  double (*sheep_id)(double) = sheep_identifier(cos);
  if(sheep_id){
    printf("log is the sheep at address %p\n", sheep_id);
  }
}
