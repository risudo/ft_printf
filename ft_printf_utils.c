#include "ft_printf.h"
//TODO: baseを求めて10進数でも16進数でも同じ関数を使う
void	culc_space_nb(t_fmt *fmt, long *nb)
{
	int		digit;
	long	nb_cpy;

	digit = 0;
	if (*nb < 0)
	{
		fmt->minus_sign = 1;
		*nb *= -1;
	}
	nb_cpy = *nb;
	while (nb_cpy)
	{
		nb_cpy /= fmt->base;
		digit++;
	}
	fmt->arg_len = digit;
	if (fmt->precision > digit)
		digit = fmt->precision;
	if (fmt->width > digit)
		fmt->cnt_space = fmt->width - digit;
}

void	culc_zero(t_fmt *fmt)
{
	if (fmt->precision == -1 && fmt->flag == '0')
	{
		fmt->cnt_zero = fmt->cnt_space;
		fmt->cnt_space = 0;
	}
	if (fmt->precision > fmt->arg_len)
		fmt->cnt_zero = fmt->precision - fmt->arg_len;
}

void	put_space(t_fmt *fmt)
{
	int	i;

	i = 0;
	while (i < fmt->cnt_space)
	{
		write(1, " ", 1);
		i++;
	}
}

void	put_zero(t_fmt *fmt)
{
	int	i;

	i = 0;
	while (i < fmt->cnt_zero)
	{
		write(1, "0", 1);
		i++;
	}
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
