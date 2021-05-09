#include "ft_printf.h"



int	write_arg(t_fmt *fmt, va_list *ap)
{
	if (fmt->type == 'd' || fmt->type == 'i')
		write_int(fmt, ap);
	else if (fmt->type == 'u')
		write_unsigned(fmt, ap);
	else if (fmt->type == 'c')
		write_char(fmt, ap);
	else if (fmt->type == 's')
		write_str(fmt, ap);
	else if (fmt->type == '%')
		write_percent(fmt);
	else if (fmt->type == 'x')
		write_hex(fmt, ap);
	else if (fmt->type == 'X')
		write_hex(fmt, ap);
	else if (fmt->type == 'p')
		write_pointer(fmt, ap);
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
