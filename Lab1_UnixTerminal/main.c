// Add your program here! sorry new to C, wait for me some time, I am catching up...
#include <stdio.h>
int main(void)
{
	printf("Hello World\n");

	int a=5;
	int* pa=&a;

	printf("a address is %p\n", &a);
	printf("pa stores %p\n", pa);
	printf("pa points to the value %i\n", *pa);

	return 0;
}
