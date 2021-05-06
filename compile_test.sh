gcc -Wall -Wextra -Werror -D FT_PRINTF main.c ft_printf.c ft_printf_utils.c ft_printf_write.c input.c
./a.out > result_ft_printf.txt
gcc main.c
./a.out > result_printf.txt
diff -s result_ft_printf.txt result_printf.txt \
 | sed "s/Files result_ft_printf.txt and result_printf.txt are identical/<TEST OK>/g" \
 | GREP_COLOR='01;32' grep -E --color "$|<TEST OK>"