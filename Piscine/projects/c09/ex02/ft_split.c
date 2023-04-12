#include <stdlib.h>
#include <stdio.h>

char	*ft_checkstr(char	*original, int	i, int	*d)
{
	char	*arr;
	int		num;
	int		x;

	x = *d;
	num = i - x;
	arr = malloc(num + 1 * (sizeof(char)));
	while (i != x)
	{	
		arr = original[x];
		arr++;
		x++;
	}
	arr = '\0';
	*d = x + 1;
	return (arr);
}

char	*ft_last(char	*str, int	i)
{
	char	*arr;
	int		d;

	d = i;
	while (str[d++])
		;
	arr = (char *)malloc((d - i + 1) * (sizeof(char)));
	while (str[i++])
	{
		arr = str[i];
		arr++;
	}
	arr = 0;
	return (arr);
}

char	**ft_split(char	*str, char	*charset)
{
	int		i;
	int		x;
	int		d;
	int		s;
	char	**ret;

	i = 0;
	x = 0;
	d = 0;
	s = 0;
	ret = (char **)malloc((ret + 1) * (sizeof(char **)));
	while (str[i])
	{
		while (charset[x])
		{
			if (str[i] == charset[x])
			{
				if (i - d > 0)
				{
					(ret[s] = ft_checkstr(str, i, &d));
					s++;
				}
				else
					d++;
			}
			x++;
		}
		i++;
	}
	if (str[d])
	{
		ret[s] = ft_last(str, d);
		s++;
	}
	ret[s] = 0;
	return (ret);
}

int	main(void)
{
	char	**arr;
	int	i;
	int	x;

	i = 0;
	x = 0;
	arr = ft_split("hello world", "eo");
	while (arr[x][i] != '\0')
	{
		while(arr[x][i] != '\0')
		{
			printf("%s", arr[x][i]);
			i++;
		}
		x++;
	}
	return (0);
}
