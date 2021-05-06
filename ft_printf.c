#include "ft_printf.h"

void	write_int(t_fmt *fmt, va_list *ap)
{
	int nb;

	nb = (int)va_arg(*ap, int);
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
	ft_putnbr_fd(nb, 1);//! 精度０の時０出力しない
	if (fmt->flag == '-')
		put_space(fmt);
}

int	write_arg(t_fmt *fmt, va_list *ap)
{
	if (fmt->type == 'd' || fmt->type == 'i' || fmt->type == 'u')
		write_int(fmt, ap);
	else if (fmt->type == 'c')
		write_char(fmt, ap);
	else if (fmt->type == 's')
		write_str(fmt, ap);
	return (fmt->put_len);
}


int	ft_input_fmt(const char *format, int *i, va_list *ap)
{
	t_fmt	fmt;

	(*i)++;
	init_fmt(&fmt);

	fmt.flag = flag_input(format, i);
	fmt.width = width_precision_input(format, i, ap);
	if (fmt.width < 0)
	{
		fmt.width *= -1;
		fmt.flag = '-';
	}
	if (format[*i] == '.')
	{
		(*i)++;
		fmt.precision = width_precision_input(format, i, ap);
	}
	fmt.type = ft_strchr_return("cspdiuxX%", format[*i]);
	return (write_arg(&fmt, ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		n;
	int		start;

	i = 0;
	start = 0;
	n = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			// printf("i: %d\n", i);
			// printf("format: %s\n", format);
			n += ft_input_fmt(format, &i, &ap);
		}
		else
		{
			n += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (n);
}
