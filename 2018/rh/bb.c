#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



long poww(long k) {
	if( k == 0) return 1;
	long p = 2;
	for (long i = 1; i < k; ++i)
	{
		p = 2 * p;
	}
	return p;
}

bool prefix(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}


long main() {
	long t;
	scanf(" %ld",&t);
	for (long i = 1; i < t+1; i++)
	{
		long n, p;
		scanf(" %ld %ld",&n,&p);
		long avai = poww(n);
		char * string = malloc(n * sizeof(char));
		char ** all = malloc(p * sizeof(string));

		for (long k = 0; k < p; k++)
		{
			char * string = malloc(n * sizeof(char));
			scanf(" %s", string);
			all[k] = string;
			
		}
		for (int i = 0; i < p; ++i)
		{
			for (int k = 0; k < p; k++) 
			{
				if(k==i) continue;
				else {
					if(prefix(all[k], all[i])) 
					{
						all[i] = "0";
					}
				}
			}
			
		}
		for (int ii = 0; ii < p; ii++)
		{
			if(!prefix("0", all[ii])) {
				avai -= poww(n-strlen(all[ii]));	
			}
			
		}
		printf("Case #%ld: %ld\n",i,avai);
	}
	return 0;
} 


	
