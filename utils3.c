/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:24:08 by nayache           #+#    #+#             */
/*   Updated: 2019/11/27 13:07:31 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		work_reverse(t_element *stock)
{
	stock->reverse = 1;
	return (1);
}

int		work_precision(t_element *stock, const char *str, va_list ap)
{
	int i;

	i = 1;
	stock->p_on = 1;
	if (str[i] == '*')
	{
		stock->precision = va_arg(ap, int);
		return (++i);
	}
	while (is_digit(str[i]))
	{
		stock->precision = stock->precision * 10 + (str[i] - 48);
		i++;
	}
	return (i);
}

int		work_star(t_element *stock, const char *str, va_list ap)
{
	int	i;

	i = 0;
	while (str[i] == '*')
	{
		stock->width = va_arg(ap, int);
		if (stock->width < 0)
			stock->reverse = 1;
		i++;
	}
	return (i);
}

int		work_width(t_element *stock, const char *str)
{
	int i;

	i = 0;
	stock->width = (str[i] - 48);
	i++;
	while (is_digit(str[i]))
	{
		stock->width = stock->width * 10 + (str[i] - 48);
		i++;
	}
	return (i);
}

void	stock_flags(t_element *stock, const char *str, va_list ap)
{
	while (flags_occurs(*str))
	{
		if (*str == '.')
			str += work_precision(stock, str, ap);
		if (*str == '-')
			str += work_reverse(stock);
		if (*str == '*')
			str += work_star(stock, str, ap);
		if (*str == '0')
			str += work_zero(stock);
		if (is_digit(*str))
			str += work_width(stock, str);
	}
	stock->type = *str;
	if (stock->width < 0)
	{
		stock->width *= -1;
		stock->reverse = 1;
	}
}
