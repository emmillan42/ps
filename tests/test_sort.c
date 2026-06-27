/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "push_swap.h"

int	main(void)
{
	char	*str;
	char	*se1;
	char	*se2;
	char	*se3;
	char	*se4;
	int		arr[] = {3, 2, 1, 5, 97, 43, 6, 7, 42, 8};

	se1 = ft_strdup("--simple");
	se2 = ft_strdup("--medium");
	se3 = ft_strdup("--complex");
	se4 = ft_strdup("--adaptive");

	printf("Hello World %.2f\n",
		ft_compute_disorder(arr, (sizeof(arr) / sizeof(int))));
	printf("Hello World %d\n", strcmp(str, se1));
	return (0);
}
