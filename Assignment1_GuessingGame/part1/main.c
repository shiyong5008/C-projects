// Add your program here! sorry I am new to C, I need some time to transfer python to C, wait me for some time :)

// updated: tracking the guess time and print out total times used, thanks Xinchao for the input!

#include<stdio.h>
int main()
{
	int k=0;
	int m[10];

	for (;k < 5;)
	{
		int a;
		int total;
		int num = 1 + rand() % 10;
		// printf("%d\n", num);
		int x = 0;
		while (x < 10)
		{
			printf("this is game %d, %d guess, input 1-10:\n", k, x + 1);
			scanf("%d", &a);
			x++;
			if (a > num)
			{
				printf("too large, guess lower\n");
			}
			else if (a < num)
			{
				printf("too small, guess higher\n");
			}
			else
			{
				printf("correct, you got it, you use %d times\n", x + 1);
				total = x + 1;
				break;
			}
		}
		m[k] = total;
		k++;
	}
	int n = 0;
	int time;
	for (; n < 5;)
	{
		time = m[n];
		printf("game %d use %d times\n", n, time);
		n++;
	}
	return 0;
}
