int	ft_count_if(char	**tab, int	lenth, int(*f)(char*))
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (i < lenth)
	{
		if (f(tab[i]) != 0)
			num++;
		i++;
	}
	return (num);
}
