#include <stdio.h>

char	*ft_strcat(char	*dest, char	*src)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (dest[s] != '\0')
	{
		s++;
	}
	while (src[i] != '\0')
	{
		dest[s] = src[i];
		i++;
		s++;
	}
	dest[s] = '\0';
	return (dest);
}

int	main(void)
{
	char	a[10] = "54";
	char	b[] = "10122";

	printf("%s", ft_strcat(a, b));
	return (0);
}
