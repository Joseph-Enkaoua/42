#include <stdio.h>

int	main()
{
	char	a[] = "hallo world";
	char	b[] = "whatsbu";
	ft_strncpy(a, b, 4);
	printf("%s", a);
}
