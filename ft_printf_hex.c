#include "ft_printf.h"

void	write_pointer(t_fmt *fmt, va_list *ap)
{
	unsigned long long	p;

	p = (unsigned long long)va_arg(*ap, long);
	fmt->base = 16;
	fmt->pointer_sign = 1;
	fmt->case_letter = 0;
	culc_space_unsigned(fmt, &p);
	fmt->cnt_space -= 2;
	culc_zero(fmt);
	write_hex_ans(fmt, p);
}

void	write_hex(t_fmt *fmt, va_list *ap, int case_letter)
{
	long	nb;

	fmt->base = 16;
	nb = (long)va_arg(*ap, int);
	if (case_letter)
		fmt->case_letter = 1;
	else
		fmt->case_letter = 0;
	culc_space_nb(fmt, &nb);
	culc_zero(fmt);
	write_hex_ans(fmt, (unsigned long long)nb);
}

void	get_base(t_fmt *fmt)
{
	int		i;
	char	c;

	i = -1;
	if (fmt->case_letter == 1)
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

void	write_hex_ans(t_fmt *fmt, unsigned long long nb)
{
	get_base(fmt);
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
	if (fmt->pointer_sign)
		write(1, "0x", 2);
	put_zero(fmt);
	if (!(fmt->precision == 0 && nb == 0))
		ft_put_nbr_hex(nb, fmt);
	if (fmt->flag == '-')
		put_space(fmt);
}

void	ft_put_nbr_hex(unsigned long long nb, t_fmt *fmt)
{
	if (nb > 15)
	{
		ft_put_nbr_hex(nb / 16, fmt);
		ft_put_nbr_hex(nb % 16, fmt);
	}
	else
		ft_putchar_fd(fmt->base_string[nb % 16], 1);
}