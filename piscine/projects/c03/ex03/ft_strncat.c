char	*ft_strncat(char	*dest, char	*src, unsigned int	nb)
{
	unsigned int	i;
	unsigned int	s;

	i = 0;
	s = 0;
	while (dest[s] != '\0')
	{
		s++;
	}
	while (src[i] != '\0' && i < nb)
	{
		dest[s] = src[i];
		i++;
		s++;
	}
	dest[s] = '\0';
	return (dest);
}
