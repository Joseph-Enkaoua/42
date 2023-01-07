int	ft_iterative_power(int	nb, int	power)
{
	int	s;

	s = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		nb = nb * s;
		power--;
	}
	return (nb);
}
