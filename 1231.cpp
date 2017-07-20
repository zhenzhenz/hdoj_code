#include<stdio.h>
#include<string.h>

int arry[10005];

int main()
{
	int n;
	while (scanf("%d", &n) && n != 0)
	{
		memset(arry, 0, sizeof(arry));
		double max_sum = -0.1, max_here = 0;
		int beg, end,cbeg,cend;
		int tag = 1;

		for (int i = 0; i < n; ++i)
			scanf("%d", &arry[i]);
		beg = end = arry[0];
		cbeg = arry[0];

		for (int i = 0; i < n; ++i)
		{
			if (arry[i] >= 0)
				tag = 0;
			max_here += arry[i];
			if (max_here > max_sum)
			{
				beg = cbeg;
				end = arry[i];
				max_sum = max_here;
			}
			else if(max_here < 0)
			{
				cbeg = arry[i + 1];
				max_here = 0;
			}
		}

		if (tag)
			printf("0 %d %d\n", arry[0], arry[n - 1]);
		else
			printf("%.f %d %d\n", max_sum, beg, end);

	}
	

	return 0;
}