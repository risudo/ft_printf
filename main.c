#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#ifdef FT_PRINTF
#define F(...) \
	ft_printf(__VA_ARGS__);
#else
#define F(...) \
	printf(__VA_ARGS__);
#endif

void	d_test(void)
{

	F("1: %*.*d\n", 5, -3, 42);
	F("2: %*.*d\n", -5, -3, 42);
	F("3: %05d\n", 42);
	F("4: %05.d\n", 42);
	F("5: %5.10d\n", 42);
	F("6: %-5d\n", 42);
	F("7: %7d\n", -14);
	F("8: %.d\n", 0);
	F("9: %10.d\n", 0);
	F("10: %-3d\n", 0);
	F("11: %3d\n", 0);
	F("12: %010.d\n", 0);
}

void	u_test()
{
	F("2: %u\n", 4294967295);
	F("9: %10u\n", 4294967293);
	F("10: %0.5u\n", 4294967293);

}

void	s_test()
{
	char *s = NULL;
	F("3: %s\n", "abc");
	F("9: %10s\n", "abc");
	F("10: %.s\n", "abc");
	F("11: %.1s\n", "abc");
	F("12: %010s\n", "abc");
	F("13: %s\n", s);
	F("14: %10s\n", s);
	F("15: %-10s\n", s);
	F("16: %.1s\n", s);
	F("17: %010s\n", s);

}

void	c_test()
{
	F("4: %c\n", 0);
	F("19: %10c\n", 'a');
	F("20: %010c\n", 'a');

}

void	per_test()
{
	F("21: %%\n");
	F("5: [%-10%]\n");
	F("21: %10.5%\n");
	F("21: %010.5%\n");
	F("21: %02.5%\n");
	F("21: %0.5%\n");

}

void	x_test()
{
	F("6: %x\n", -1045);
	F("%10x\n", INT_MIN);
	F("%10.5x\n", 42);
	F("x: %.x\n", 0);
}

void	X_test()
{
	F("7: %X", -10982734);
	F("%.X", 10982734);
	F("%-10X", 10982734);
	F("%010X", 10982734);
}

void	p_test()
{
	int	*p;
	int d = 100;
	p = &d;
	// F("%p\n", p);
	// F("%30p\n", p);
	// F("%030p\n", p);
	// F("%-30p\n", p);
	// F("%30.40p\n", p);
	// ft_printf("%10.20p\n", p);
	// printf("%10.20p\n", p);

}

int	main()
{

	// d_test();
	// u_test();
	// s_test();
	// c_test();
	// per_test();
	x_test();
	// X_test();
	// p_test();
	return (0);
}