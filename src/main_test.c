#include <stdio.h>

void ft_swap(void *a, void *b);

int		main(void)
{
	int a;
	int b;

	a = 5;
	b = 10;
	printf("Before a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After a = %d, b = %d\n", a, b);
	return (0);
}
