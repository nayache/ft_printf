/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:08:00 by nayache           #+#    #+#             */
/*   Updated: 2019/11/26 18:34:14 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_null(t_element *stock, int *result)
{
	char	str[7];
	int		size;
	int		i;

	ft_strcpy(str, "(null)");
	i = -1;
	size = ft_strlen(str);
	if (stock->p_on == 0 || (stock->precision < 0 || stock->precision > size))
		stock->precision = size;
	stock->width -= stock->precision;
	if (stock->reverse == 0)
		print_width(stock, result);
	while (--stock->precision >= 0)
		*result += ft_putchar(str[++i]);
	print_width(stock, result);
}

void	print_str(t_element *stock, va_list ap, int *result)
{
	char	*str;
	int		i;
	int		size;

	str = va_arg(ap, char *);
	if (stock->p_on == 1 && stock->precision == 0)
		return (print_width(stock, result));
	if (!str)
		return (print_null(stock, result));
	size = ft_strlen(str);
	if (stock->p_on == 0 || stock->precision < 0 || stock->precision > size)
		stock->precision = size;
	stock->width -= stock->precision;
	i = -1;
	if (stock->reverse == 0)
		print_width(stock, result);
	while (--stock->precision >= 0)
		*result += ft_putchar(str[++i]);
	print_width(stock, result);
}

void	print_ptr(t_element *stock, va_list ap, int *result)
{
	unsigned long	ptr;
	int				size;

	size = 0;
	ptr = va_arg(ap, unsigned long);
	if (ptr == 0 && (stock->p_on == 1 && stock->precision == 0))
	{
		*result += ft_putstr("0x");
		stock->width -= size;
		return (print_width(stock, result));
	}
	size = size_hexa(ptr);
	stock->width -= size + 2;
	if (stock->zero == '0')
		*result += ft_putstr("0x");
	if (stock->reverse == 0)
		print_width(stock, result);
	if (stock->zero == ' ')
		*result += ft_putstr("0x");
	put_hexa(ptr, 'p');
	*result += size;
	print_width(stock, result);
}
