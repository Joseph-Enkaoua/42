int	ft_strlen(char	*str)
{
	int	sum;

	sum = 0;
	while (*str != '\0')
	{
		str++;
		sum++;
	}
	return (sum);
}
