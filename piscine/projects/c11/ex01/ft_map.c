int	*ft_map(int	*tab, int	lenth, 	int(*f)(int))
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(lenth * sizeof(int));
	while (i < lenth)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}
