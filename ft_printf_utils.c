#include "ft_printf.h"

void	culc_space_nb(t_fmt *fmt, long *nb)
{
	int					digit;
	unsigned long long	nb_cpy;

	digit = 0;
	if (*nb == 0)
		digit = 1;
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
	if (fmt->precision < 0 && fmt->flag == '0')
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
