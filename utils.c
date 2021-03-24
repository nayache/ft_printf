/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:23:43 by nayache           #+#    #+#             */
/*   Updated: 2019/11/26 18:33:38 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

void	ft_putnbr(long n)
{
	if (n < 0)
		n *= -1;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

void	put_hexa(unsigned long n, char type)
{
	char base[17];

	if (type == 'X')
		ft_strcpy(base, "0123456789ABCDEF");
	else
		ft_strcpy(base, "0123456789abcdef");
	if (n > 15)
		put_hexa(n / 16, type);
	ft_putchar(base[n % 16]);
}
