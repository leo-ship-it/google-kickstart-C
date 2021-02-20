#include <stdio.h>
#include <stdlib.h>


typedef unsigned long long ull;


int main(int argc, char const *argv[])
{
	int t;
	scanf(" %d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n;
		ull b;
		ull ans;
		scanf(" %d %lld", &n, &b);
		ull * liste = calloc(1000, sizeof(ull));
		for (int j = 0; j < n; ++j)
		{
			ull toscan;
			scanf("%lld", &toscan);
			liste[toscan-1]++;
		}
		// int ii,j,c;
		// int N = n;
		// for(j=1;j<=N;j++) // pour faire l'operation N fois
		//     for(ii=0;ii<N-1;ii++)
		//         if ( liste[ii] > liste[ii+1] ) {
		//                 c = liste[ii];
		//                 liste[ii] = liste[ii+1];
		//                 liste[ii+1] = c;
		//         }
		int indice = 0;
		for (int c = 0; c < 1000; ++c)
		{
			for(int m = 0; m < liste[c]; m++) {
				if(b >= c+1) {
					b-= c+1;
					indice++;
				}
			} 

		}
		free(liste);
		printf("Case #%d: %d\n", i+1, indice);
	}
	return 0;
}