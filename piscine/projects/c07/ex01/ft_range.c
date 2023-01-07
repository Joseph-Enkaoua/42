#include <stdlib.h>

int	*ft_range(int	min, int	max)
{
	int	*p;
	int	i;

	i = 0;
	if (min >= max)
	{
		p = NULL;
		return (p);
	}
	p = (int *)malloc(sizeof(int) * (max - min));
	if (p == NULL)
		return (NULL);
	while (min < max)
	{
		p[i] = min;
		min++;
		i++;
	}
	return (p);
}
