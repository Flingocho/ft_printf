#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putformat(char *s);
int	ft_putstr(char *s);
int	ft_printf(char const *format, ...);
int	format_selector(char const *format, va_list arg);
int	ft_putnbr_u(unsigned int nbr);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putptr(unsigned long long nbr, char *base, int first);

#endif