#include <stdlib.h>

int	ft_ultimate_range(int	**range, int	min, int	max)
{
	int	i;
	int	*arr;

	if (min >= max)
	{
		arr = NULL;
		return (0);
	}
	i = max - min;
	arr = (int *)malloc(i * (sizeof(int)));
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (i);
}
