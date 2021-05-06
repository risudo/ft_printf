#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

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
}			t_fmt;

int	ft_printf(const char *format, ...);
int	ft_input_fmt(const char *format, int *i, va_list *ap);
int	write_arg(t_fmt *fmt, va_list *ap);
void	write_int(t_fmt *fmt, va_list *ap);
char	ft_strchr_return(char *set, char c);
int		width_precision_input(const char *format, int *i, va_list *ap);
char	*ft_strchr(const char *s, int c);
char	*change_asterisk(const char *format, int *i, va_list *ap, t_fmt *cvt_fmt);
char	flag_input(const char *format, int *i);
int		write_arg(t_fmt *fmt, va_list *ap);
void	culc_space_nb(t_fmt *fmt, int *nb);
void	culc_zero(t_fmt *fmt);
void	init_fmt(t_fmt *fmt);
void	put_zero(t_fmt *fmt);
void	put_space(t_fmt *fmt);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
void	write_char(t_fmt *fmt, va_list *ap);
void	write_str(t_fmt *fmt, va_list *ap);
void	culc_str(t_fmt *fmt, char *str);
#endif
