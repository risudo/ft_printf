# gcc -Wall -Wextra -Werror -D FT_PRINTF main.c ft_printf.c ft_printf_utils.c ft_printf_hex.c ft_input.c ft_printf_int.c ft_printf_str.c
gcc -D FT_PRINTF main.c ft_printf.c ft_printf_utils.c ft_printf_hex.c ft_input.c ft_printf_int.c ft_printf_str.c
./a.out > result_ft_printf.txt
gcc -w main.c
./a.out > result_printf.txt
diff -s result_ft_printf.txt result_printf.txt  | cat -e \
 | sed "s/Files result_ft_printf.txt and result_printf.txt are identical/<TEST OK>/g" \
 | GREP_COLOR='01;32' grep -E --color "$|<TEST OK>"
#rm result_printf.txt result_ft_printf.txt a.out