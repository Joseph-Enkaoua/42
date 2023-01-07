int	ft_is_sort(int	*tab, int	lenth, int	(*f)(int, int))
{
	int	i;
	int	s;

	i = 1;
	while (i < lenth)
	{
		s = f(tab[i - 1], tab[i]);
		if (s > 0)
			return (0);
		i++;
	}
	return (1);
}
