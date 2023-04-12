void	ft_foreach(int	*tab, int	lenth, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < lenth)
	{
		f(tab[i]);
		i++;
	}
}
