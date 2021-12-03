// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
int factorial(int n){
  int i;
  long f=1;
  for(i=1;i<=n;i++)
  {
	f=f*i;
  }  

  return f;
}

// TODO: Implement recursive solution here
int factorial_rec(int n){
  long f=1;
  if(n==0){return 1;}
  else{return n*factorial_rec(n-1);}
}

int main(){

  // Both of these should print the same result!
  printf("factorial(10) = %d\n",factorial(10));
  printf("factorial_rec(10) = %d\n",factorial_rec(10));


  return 0;
}
