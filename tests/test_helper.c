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
	t_stack	*stack;
	char	*arr1;

	arr1 = ft_strdup("23 45 6 7 11 9 1");
	ft_parse_pushswap(ft_count_words(arr1), arr1);
	stack = ft_parse_stack(ft_count_words(arr1), arr1);
	ft_printstack(stack);
	return (0);
}
