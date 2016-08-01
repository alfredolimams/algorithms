#include <stdio.h>

int main(int argc, char const *argv[])
{
	double num;
	while( scanf("%lf", &num) , num != -1.0 )
	{
		double sum = 0;
		int i;
		for ( i = 1; sum <= num ; ++i)
			sum += 1.0/i;
		printf("%d\n", i-1);
	}
	return 0;
}
