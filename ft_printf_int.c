#include "ft_printf.h"

void	write_int(t_fmt *fmt, va_list *ap)
{
	long nb;

	nb = (long)va_arg(*ap, int);
	fmt->base = 10;
	culc_space_nb(fmt, &nb);
	culc_zero(fmt);
	if (fmt->minus_sign && fmt->cnt_space && fmt->cnt_zero)
		fmt->cnt_space--;
	fmt->put_len = fmt->cnt_space + fmt->cnt_zero + fmt->arg_len;
	if (fmt->flag != '-')
		put_space(fmt);
	if (fmt->minus_sign)
	{
		write(1, "-", 1);
		fmt->put_len++;
	}
	put_zero(fmt);
	if (!(fmt->precision == 0 && nb == 0))
		ft_putnbr_unsigned((unsigned long long)nb);//! 精度０の時０出力しない
	if (fmt->flag == '-')
		put_space(fmt);
}

void	write_unsigned(t_fmt *fmt, va_list *ap)
{
	unsigned long long	nb;

	nb = (unsigned long long)va_arg(*ap, unsigned int);
	fmt->base = 10;
	culc_space_unsigned(fmt, &nb);//unsigned intいけてる？
	culc_zero(fmt);
	fmt->put_len = fmt->cnt_space + fmt->cnt_zero + fmt->arg_len;
	if (fmt->flag != '-')
		put_space(fmt);
	put_zero(fmt);
	if (!(fmt->precision == 0 && nb == 0))
		ft_putnbr_unsigned(nb);
	if (fmt->flag == '-')
		put_space(fmt);
}

void	culc_space_unsigned(t_fmt *fmt, unsigned long long *nb)
{
	int	digit;
	unsigned long long	nb_cpy;

	digit = 0;
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

void	ft_putnbr_unsigned(unsigned long long nb)
{
	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar_fd(nb + '0', 1);
}

void	write_percent(t_fmt *fmt)
{
	if (fmt->width > 0)
		fmt->cnt_space = fmt->width - 1;
	fmt->put_len = fmt->cnt_space + 1;
	if (fmt->flag == '0')
	{
		fmt->cnt_zero = fmt->cnt_space;
		fmt->cnt_space = 0;
	}
	if (fmt->flag != '-')
		put_space(fmt);
	put_zero(fmt);
	write(1, "%", 1);
}