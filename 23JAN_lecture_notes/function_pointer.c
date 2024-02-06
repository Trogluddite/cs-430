#include<math.h>
#include<stdio.h>

int main(){
	double (*gorilla)(double) = sin;
	printf("sin(10) = %lf\n", gorilla(10));

	double (*sheep[])(double) = {sin, cos, tan};
	for(int i = 0; i < 3; i++)
		printf("%lf\n", sheep[i](10));

	for(double (**cf)(double) = sheep; cf < sheep + 3; cf++)
		printf("%lf\n", (*cf)(8));

	double (*sheep_selector(int idx))(double){
		return sheep[idx];
	}
	printf("tan(5) = %lf\n",  sheep_selector(2)(5));

	double (*sheep_identifier(double (*f)(double)))(double){
		double res = f(1);
		for(int i = 0; i < 3; i++){
			if(res == sheep[i](1))
				return sheep[i];
		}
		return 0;
	}
	double (*sheep_id)(double) = sheep_identifier(cos);
	if(sheep_id){
		printf("cos is the sheep at address %p\n", sheep_id);
		printf("We'll test it:  cos(10) = %lf\n", sheep_id(10));
	}
	if(sheep_id = sheep_identifier(log))
		printf("log is in the list of sheep!\n");
	else
		printf("log is NOT in the list of sheep\n");

	void *moose = sheep;
//	moose[1](2);
	double (**goats)(double) = moose;
	goats[1](3);
	return 0;
}
