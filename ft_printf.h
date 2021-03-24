/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:23:25 by nayache           #+#    #+#             */
/*   Updated: 2019/11/26 18:33:13 by nayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_element
{
	int			width;
	int			p_on;
	int			precision;
	int			reverse;
	char		zero;
	char		type;
}				t_element;

int				digit_t(char c);
int				size_digit(long n);
int				size_hexa(unsigned long n);
int				ft_printf(const char *str, ...);
void			init(t_element *elem);
int				ft_strlen(char *str);
void			ft_strcpy(char *dest, char *src);
int				ft_putchar(char c);
int				ft_putstr(char *str);
void			ft_putnbr(long n);
void			put_hexa(unsigned long n, char type);
int				flags_occurs(char c);
int				type_occurs(char c);
int				available(const char *str);
int				is_digit(char c);
void			stock_flags(t_element *stock, const char *str, va_list ap);
int				work_reverse(t_element *stock);
int				work_zero(t_element *stock);
int				work_precision(t_element *stock, const char *str, va_list ap);
int				work_star(t_element *stock, const char *str, va_list ap);
int				work_width(t_element *stock, const char *str);
void			print(t_element *stock, va_list ap, int *result);
void			print_width(t_element *stock, int *result);
void			print_digit(t_element *stock, va_list ap, int *result);
void			print_char(t_element *stock, va_list ap, int *result);
void			print_hexa(t_element *stock, va_list ap, int *result);
void			print_null(t_element *stock, int *result);
void			print_str(t_element *stock, va_list ap, int *result);
void			print_ptr(t_element *stock, va_list ap, int *result);
#endif
