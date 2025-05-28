 #include "../include/ft_printf.h"

/**
 * @brief Custom printf implementation
 * 
 * Processes a format string and outputs the formatted text to standard output.
 * Supports various format specifiers like %c, %s, %d, etc.
 *
 * @param format The format string containing the text to be written
 * @param ... Additional arguments depending on format specifiers
 * @return The number of characters printed
 */
int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += format_selector(format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * @brief Outputs an unsigned integer in a specific base
 * 
 * Converts an unsigned integer to a string representation using the specified base
 * and outputs it to standard output.
 *
 * @param nbr The unsigned integer to output
 * @param base The base to use (hexadecimal, etc.)
 * @return The number of characters printed
 */
int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				count;

	base_len = 16;
	count = 0;
	if (nbr >= base_len)
	{
		count += ft_putnbr_base(nbr / base_len, base);
		count += ft_putnbr_base(nbr % base_len, base);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}

int	ft_putptr(unsigned long long nbr, char *base, int first)
{
	unsigned long long	base_len;
	int					count;

	base_len = 16;
	count = 0;
	if (!nbr && first)
		return (count = ft_putstr("(nil)"));
	if (first)
		count += ft_putstr("0x");
	if (nbr >= base_len)
	{
		count += ft_putptr(nbr / base_len, base, 0);
		count += ft_putptr(nbr % base_len, base, 0);
	}
	else
		count += ft_putchar(base[nbr]);
	return (count);
}
