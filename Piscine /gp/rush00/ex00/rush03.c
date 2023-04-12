void	ft_putchar(char	c);

void	out_line(int	t)
{
	ft_putchar('A');
	if (t >= 2)
	{
		while (t > 2)
		{
			ft_putchar('B');
			t--;
		}
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	in_line(int	t)
{
	ft_putchar('B');
	if (t >= 2)
	{
		while (t > 2)
		{
			ft_putchar(' ');
			t--;
		}
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	rush(int	x, int	y)
{
	if (x > 0 && y > 0)
	{
		out_line(x);
		if (y >= 2)
		{
			while (y > 2)
			{
				in_line(x);
				y--;
			}
			out_line(x);
		}
	}
}
