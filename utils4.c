/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:27:04 by nayache           #+#    #+#             */
/*   Updated: 2019/11/26 18:33:59 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_digit(t_element *stock, va_list ap, int *result)
{
	long	d;
	int		size;

	d = stock->type == 'u' ? (long)va_arg(ap, unsigned) : (long)va_arg(ap, int);
	if (d == 0 && stock->p_on && stock->precision == 0)
		return (print_width(stock, result));
	size = size_digit(d);
	stock->width -= d < 0 ? 1 : 0;
	if (!((stock->precision < 0 && stock->zero == '0') && digit_t(stock->type)))
		if (stock->p_on == 1 && !(stock->type == 's' || stock->type == 'c'))
			stock->zero = ' ';
	stock->width -= stock->precision < size ? size : stock->precision;
	if (d < 0 && stock->zero == '0')
		*result += ft_putchar('-');
	if (stock->reverse == 0)
		print_width(stock, result);
	if (d < 0 && stock->zero == ' ')
		*result += ft_putchar('-');
	stock->precision = stock->precision < size ? size : stock->precision;
	while (--stock->precision >= size)
		*result += ft_putchar('0');
	ft_putnbr(d);
	*result += size;
	print_width(stock, result);
}

void	print_hexa(t_element *stock, va_list ap, int *result)
{
	unsigned	x;
	int			size;

	x = va_arg(ap, unsigned);
	if (x == 0 && stock->p_on == 1 && stock->precision == 0)
		return (print_width(stock, result));
	size = size_hexa(x);
	if (!((stock->precision < 0 && stock->zero == '0') && digit_t(stock->type)))
		if (stock->p_on == 1 && !(stock->type == 's' || stock->type == 'c'))
			stock->zero = ' ';
	stock->width -= stock->precision < size ? size : stock->precision;
	if (stock->reverse == 0)
		print_width(stock, result);
	stock->precision = stock->precision < size ? size : stock->precision;
	while (--stock->precision >= size)
		*result += ft_putchar('0');
	put_hexa(x, stock->type);
	*result += size;
	print_width(stock, result);
}

void	print_char(t_element *stock, va_list ap, int *result)
{
	unsigned char c;

	c = stock->type == 'c' ? va_arg(ap, int) : '%';
	stock->width--;
	if (stock->reverse == 0)
		print_width(stock, result);
	*result += ft_putchar(c);
	print_width(stock, result);
}

void	print_width(t_element *stock, int *result)
{
	if (!((stock->precision < 0 && stock->zero == '0') && digit_t(stock->type)))
		if (stock->p_on == 1 && !(stock->type == 's' || stock->type == 'c'))
			stock->zero = ' ';
	if (stock->reverse == 1)
		stock->zero = ' ';
	while (--stock->width >= 0)
		*result += ft_putchar(stock->zero);
}

void	print(t_element *stock, va_list ap, int *result)
{
	if (stock->type == 'd' || stock->type == 'i' || stock->type == 'u')
		print_digit(stock, ap, result);
	if (stock->type == 'x' || stock->type == 'X')
		print_hexa(stock, ap, result);
	if (stock->type == 'c' || stock->type == '%')
		print_char(stock, ap, result);
	if (stock->type == 's')
		print_str(stock, ap, result);
	if (stock->type == 'p')
		print_ptr(stock, ap, result);
}
