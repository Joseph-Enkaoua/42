#include <stdlib.h>
#include <stdio.h>

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
		while (strs[i][d] != '\0')
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
	while (i < size)
		d += ft_counter(strs[i++]);
	d += (ft_counter(sep) * (size - 1));
	arr = (char *)malloc(d * (sizeof(char)) + 1);
	ft_setarr(strs, sep, arr, size);
	return (arr);
}

int	main(void)
{
	char	*input[5];
	char	sep[] = " ";
	char	*output;

	input[0] = "hello";
	input[1] = "how";
	input[2] = "are";
	input[3] = "you";
	input[4] = "today";

	output = ft_strjoin(5, input, sep);

	printf("output=%s...", output);

	return (0);
}
