#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_fmt
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		arg_len;
	int		cnt_space;
	int		cnt_zero;
	int		put_len;
	int		minus_sign;
	int		base;
	char	base_string[17];
	int		case_letter;
	int		pointer_sign;
}			t_fmt;

int		ft_printf(const char *format, ...);
void	write_unsigned(t_fmt *fmt, va_list *ap);
void	ft_put_nbr_hex(unsigned long long nb, t_fmt *fmt);
void	write_pointer(t_fmt *fmt, va_list *ap);
void	ft_putnbr_unsigned(unsigned long long nb);
void	culc_space_unsigned(t_fmt *fmt, unsigned long long *nb);
void	write_percent(t_fmt *fmt);
void	write_hex(t_fmt *fmt, va_list *ap);
void	write_hex_ans(t_fmt *fmt, unsigned long long nb);
int		ft_input_fmt(const char *format, int *i, va_list *ap);
int		write_arg(t_fmt *fmt, va_list *ap);
void	write_int(t_fmt *fmt, va_list *ap);
char	ft_strchr_return(char *set, char c);
int		width_precision_input(const char *format, int *i, va_list *ap);
char	*ft_strchr(const char *s, int c);
char	flag_input(const char *format, int *i);
int		write_arg(t_fmt *fmt, va_list *ap);
void	culc_space_nb(t_fmt *fmt, long *nb);
void	culc_zero(t_fmt *fmt);
void	init_fmt(t_fmt *fmt);
void	put_zero(t_fmt *fmt);
void	put_space(t_fmt *fmt);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
void	write_char(t_fmt *fmt, va_list *ap);
void	write_str(t_fmt *fmt, va_list *ap);
void	culc_str(t_fmt *fmt, char *str);
void	make_null_str(char **str, char *null_str);
#endif
