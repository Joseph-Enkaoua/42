#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "yir";
	char	s2[] = "twf";
	printf("%d", strncmp(s1, s2, 0));
	return (0);
}
