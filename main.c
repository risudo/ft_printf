#include "ft_printf.h"
#include <stdio.h>

#ifdef FT_PRINTF
#define F(...) \
	ft_printf(__VA_ARGS__);
#else
#define F(...) \
	printf(__VA_ARGS__);
#endif


int	main()
{
	// ft_printf("[%010s]\n", "abc");
	//* :%d
	F("1: %*.*u\n", 5, 3, 42);
	F("2: %*.*u\n", -5, 3, 42);
	F("3: %05u\n", 42);
	F("4: %05.u\n", 42);
	F("5: %5.10u\n", 42);
	F("6: %-5u\n", 42);
	F("7: %.5u\n", 42);

	//* :%s
	char *s = NULL;
	F("8: %s\n", "abc");
	F("9: %10s\n", "abc");
	F("10: %-10s\n", "abc");
	F("11: %.1s\n", "abc");
	F("12: %010s\n", "abc");
	F("8: %s\n", s);
	F("9: %10s\n", s);
	F("10: %-10s\n", s);
	F("11: %.1s\n", s);
	F("12: %010s\n", s);

	// //* : %c
	F("13: %c\n", 'a');
	F("14: %10c\n", 'a');
	F("15: %010c\n", 'a');
	return (0);
}