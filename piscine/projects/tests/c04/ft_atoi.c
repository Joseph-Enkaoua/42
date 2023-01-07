#include <stdio.h>

int	ft_atoi(char	*str)
{
	int	i;
	int	g;
	int	num;

	i = 0;
	g = 1;
	num = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			g = -g;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	num = num * g;
	return (num);
}

int	main(void)
{
	char	a[] = "        ---+---+-+--++---+fose3645";
	printf("%d", ft_atoi(a));
	return (0);
}
