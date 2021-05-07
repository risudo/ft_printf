#include "ft_printf.h"

void	write_unsigned(t_fmt *fmt, va_list *ap)
{
	unsigned int	nb;

	nb = (unsigned int)va_arg(*ap, int);
	fmt->base = 10;
	culc_space_unsigned(fmt, &nb);//unsigned intいけてる？
	culc_zero(fmt);
	fmt->put_len = fmt->cnt_space + fmt->cnt_zero + fmt->arg_len;
	if (fmt->flag != '-')
		put_space(fmt);
	put_zero(fmt);
	ft_putnbr_unsigned(nb);
	if (fmt->flag == '-')
		put_space(fmt);
}

void	culc_space_unsigned(t_fmt *fmt, unsigned int *nb)
{
	int	digit;
	unsigned int	nb_cpy;

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

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar_fd(nb + '0', 1);
}

//? unsigned char にキャスト？
void	write_char(t_fmt *fmt, va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (fmt->width > 1)
		fmt->cnt_space = fmt->width - 1;
	fmt->put_len = fmt->cnt_space + 1;
	if (fmt->flag == '0')
	{
		fmt->cnt_zero = fmt->cnt_space;
		fmt->cnt_space = 0;
		put_zero(fmt);
	}
	put_space(fmt);
	write(1, &c, 1);
}

void	make_null_str(char **str, char *null_str)
{
	null_str[0] = '(';
	null_str[1] = 'n';
	null_str[2] = 'u';
	null_str[3] = 'l';
	null_str[4] = 'l';
	null_str[5] = ')';
	null_str[6] = '\0';
	*str = null_str;

}

void	write_str(t_fmt *fmt, va_list *ap)
{
	char	*str;
	char	null_str[7];
	int		i;

	i = -1;
	str = (char *)va_arg(*ap, char *);
	if (!str)
		make_null_str(&str, null_str);
	culc_str(fmt, str);
	if (fmt->flag != '-')
		put_space(fmt);
	put_zero(fmt);
	while (fmt->arg_len)
	{
		write(1, &str[++i], 1);
		fmt->arg_len--;
	}
	if (fmt->flag == '-')
		put_space(fmt);
}

void	culc_str(t_fmt *fmt, char *str)
{
	//出力する文字列の長さ計算
	if (fmt->precision >= 0 && fmt->precision < (int)ft_strlen(str))
		fmt->arg_len = fmt->precision;
	else
		fmt->arg_len = ft_strlen(str);
	//出力するスペースの数計算
	if (fmt->width > fmt->arg_len)
		fmt->cnt_space = fmt->width - fmt->arg_len;
	fmt->put_len = fmt->arg_len + fmt->cnt_space;
	//フラグ0だったらスペースを0に変換
	if (fmt->flag == '0')
	{
		fmt->cnt_zero = fmt->cnt_space;
		fmt->cnt_space = 0;
	}
}