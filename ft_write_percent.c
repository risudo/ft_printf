#include "ft_printf.h"
# include <stdio.h>
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

void	write_hex(t_fmt *fmt, va_list *ap, int case_letter)
{
	long	nb;

	fmt->base = 16;
	nb = (long)va_arg(*ap, int);
	culc_space_nb(fmt, &nb);
	culc_zero(fmt);
	write_hex_ans(fmt, nb, case_letter);
}

void	get_base(int case_letter, t_fmt *fmt)
{
	int		i;
	char	c;

	i = -1;
	if (case_letter == 1)
		c = 'A';
	else
		c = 'a';
	while (++i <= 9)
	{
		fmt->base_string[i] = i + '0';
	}
	while (i <= 15)
	{
		fmt->base_string[i] = c++;
		i++;
	}
	fmt->base_string[i] = '\0';
}

void	write_hex_ans(t_fmt *fmt, int nb, int case_letter)//! :精度0のとき0出力しない
{
	get_base(case_letter, fmt);
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
	ft_put_nbr_hex(nb, fmt);
	if (fmt->flag == '-')
		put_space(fmt);
}

void	ft_put_nbr_hex(int nb, t_fmt *fmt)
{
	if (nb > 15)
	{
		ft_put_nbr_hex(nb / 16, fmt);
		ft_put_nbr_hex(nb % 16, fmt);
	}
	else
		ft_putchar_fd(fmt->base_string[nb % 16], 1);
}