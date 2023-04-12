#include <stdlib.h>

int	ft_counter(char	*arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}

void	ft_setarr(char	**strs, char	*sep, char	*arr, int	size)
{
	int	i;
	int	d;
	int	x;

	i = 0;
	x = 0;
	while (i < size)
	{
		d = 0;
		while (strs[i][d])
		{
			arr[x] = strs[i][d];
			x++;
			d++;
		}
		d = 0;
		while (sep[d] && i < size - 1)
		{
			arr[x] = sep[d];
			x++;
			d++;
		}
		i++;
	}
	arr[x] = '\0';
}

char	*ft_strjoin(int	size, char	**strs, char	*sep)
{
	char	*arr;
	int		i;
	int		d;

	i = 0;
	d = 0;
	if (strs == NULL || size <= 0)
	{
		arr = (char *)malloc(1);
		*arr = 0;
		return (arr);
	}
	while (i < size)
		d += ft_counter(strs[i++]);
	d += (ft_counter(sep) * (size - 1));
	arr = (char *)malloc(d * (sizeof(char)) + 1);
	if (arr == NULL)
		return (0);
	ft_setarr(strs, sep, arr, size);
	return (arr);
}
