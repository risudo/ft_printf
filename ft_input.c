#include "ft_printf.h"

char	ft_strchr_return(char *set, char c)
{
	while (*set)
	{
		if (*set == c)
		{
			return (c);
		}
		set++;
	}
	return (0);
}

int	width_precision_input(const char *format, int *i, va_list *ap)
{
	int	nb;
	int	minus;

	nb = 0;
	minus = 1;
	if (format[*i] == '*')
	{
		(*i)++;
		nb = (int)va_arg(*ap, int);
		return (nb);
	}
	else if (format[(*i) - 1] == '.' && ft_strchr_return("cspdiuxX%", format[*i]))
	{
		return (0);
	}
	if (format[*i] == '-')
		minus = -1;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		nb *= 10;
		nb += (format)[*i] - '0';
		(*i)++;
	}
	return (nb * minus);
}

char	flag_input(const char *format, int *i)
{
	char	ret;

	ret = 'a';
	if (format[*i] == '0')
	{
		while (format[*i] == '0')
			(*i)++;
		return ('0');
	}
	if (format[*i] == '-')
	{
		while (format[*i] == '-')
			(*i)++;
		return ('-');
	}
	return ('a');
}

void	init_fmt(t_fmt *fmt)
{
	fmt->flag = 'a';
	fmt->width = -1;
	fmt->precision = -1;
	fmt->type = 0;
	fmt->arg_len = 0;
	fmt->cnt_space = 0;
	fmt->cnt_zero = 0;
	fmt->put_len = 0;
	fmt->minus_sign = 0;
	fmt->base = 0;
	fmt->pointer_sign = 0;
}
