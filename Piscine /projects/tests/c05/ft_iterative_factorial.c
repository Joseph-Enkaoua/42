#include <stdio.h>

int	ft_iterative_factorial(int	nb)
{
	int	i;

	i = nb - 1;
	if (nb < 0)
		return (0);
	while (i > 1)
		nb = nb * (i--);
	return (nb);
} 

int	main(void)
{
	int	num;

	num = -510;
	printf("%d", ft_iterative_factorial(num));
	return (0);
}
