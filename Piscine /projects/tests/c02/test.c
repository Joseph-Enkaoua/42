#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "bye bye bye";
	char	dest[] = "hallo world";
	strncpy(dest, src, 15);
	printf("%s", dest);
	return (0);
}
