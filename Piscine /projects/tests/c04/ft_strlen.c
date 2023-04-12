#include <stdio.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	main(void)
{
	char	a[] = "123456789012345";
	printf("%d", ft_strlen(a));
	return (0);
}
