int	ft_sqrt(int	nb)
{
	int	i;

	i = nb;
	if (nb > 500000)
		i = i / 200;
	if (nb == 1)
		return (1);
	if (nb <= 0)
		return (0);
	while (i > 0)
	{
		if (nb / i == i && nb % i == 0)
			return (i);
		i--;
	}
	return (0);
}
