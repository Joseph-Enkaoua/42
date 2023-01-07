void	ft_putchar(char	c);

void	first_line(int	t)
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

void	middle_line(int	t)
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

void	last_line(int	t)
{
	ft_putchar('C');
	if (t >= 2)
	{
		while (t > 2)
		{
			ft_putchar('B');
			t--;
		}
		ft_putchar('A');
	}
}

void	rush(int	x, int	y)
{
	if (x > 0 && y > 0)
	{
		first_line(x);
		if (y >= 2)
		{
			while (y > 2)
			{
				middle_line(x);
				y--;
			}
			last_line(x);
		}
	}
}
