 #include "../include/ft_printf.h"

/**
 * @brief Outputs a character to standard output
 * 
 * @param c The character to output
 * @return The number of characters printed (always 1)
 */
int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * @brief Outputs a string to standard output
 * 
 * If the string is NULL, outputs "(null)".
 * 
 * @param s The string to output
 * @return The number of characters printed
 */
int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		count += ft_putchar(*s++);
	}
	return (count);
}

/**
 * @brief Outputs an integer to standard output
 * 
 * Handles negative numbers by outputting a minus sign and
 * converting to a positive number.
 * 
 * @param nb The integer to output
 * @return The number of characters printed
 */
int	ft_putnbr(int nb)
{
	char			digit;
	unsigned int	nbr;
	int				count;

	count = 0;
	if (nb < 0)
	{
		nbr = nb * -1;
		count += ft_putchar('-');
	}
	else
		nbr = nb;
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	digit = nbr % 10 + '0';
	count += ft_putchar(digit);
	return (count);
}

int	ft_putnbr_u(unsigned int nbr)
{
	char	digit;
	int		count;

	count = 0;
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	digit = nbr % 10 + '0';
	count += ft_putchar(digit);
	return (count);
}

int	format_selector(char const *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == '%')
		count += ft_putchar('%');
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putnbr_u(va_arg(args, int));
	else if (*format == 'x')
		count += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (*format == 'X')
		count += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (*format == 'p')
		count += ft_putptr(va_arg(args, unsigned long long), "0123456789abcdef",
				1);
	return (count);
}
