#include <stdlib.h>

char	*ft_strdup(char	*src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i++])
		;
	str = (char *)malloc((i + 1) * (sizeof(char)));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (src[++i] != '\0')
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
