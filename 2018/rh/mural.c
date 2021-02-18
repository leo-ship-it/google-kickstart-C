#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int t;
	scanf(" %d", &t);
	for (int i = 1; i < t + 1; ++i)
	{
		int n;
		scanf(" %d", &n);
		int * walls = malloc( n * sizeof(int));
		int one;
    	for (int i = 0; i < n; ++i)
    	{
    		scanf(" %1d", &one);
        	walls[i] = one % 10;
    	}
		int max = 0;
		int try = 0;
		int size = n / 2 + 1;
		if(!(n % 2)) size = n / 2;
		for (int j = 0; j < size; ++j)
		{
			try += walls[j];
		}
		max = try;
		for (int k = 0; k < size; ++k)
		{
			try += walls[k + size] - walls[k];
			if(try > max) max = try;
		}
		printf("Case #%d: %d\n",i ,max);
	}
	return 0;
}
