#include <stdio.h>

int	ft_strcmp(char	*s1, char	*s2)
{
	int	d;

	d = 0;
	while (*s1 == *s2)
	{
		if (*s1 == '\0' && *s2 == '\0')
		{
			return (d);
		}
		s1++;
		s2++;
	}
	d = *s1 - *s2;
	return (d);
}

int	main(void)
{
	char	*a = "16161";
	char	*b = "1616";

	printf("%d", ft_strcmp(a, b));
	return (0);
}
