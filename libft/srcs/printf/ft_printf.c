/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:54:33 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/19 12:07:53 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (len);
			else
				len += ft_print_args(format[i], args);
		}
		else
			len += ft_putchar_fd_len(format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_print_args(char c, va_list args)
{
	int		len;

	len = 0;
	if (c == '%')
		len = ft_putchar_fd_len('%', 1);
	if (c == 'c')
		len = ft_putchar_fd_len(va_arg(args, int), 1);
	if (c == 's')
		len = ft_putstr_fd_len(va_arg(args, char *), 1);
	if (c == 'p')
		len = ft_put_memory((unsigned long)va_arg(args, void *), 1);
	if (c == 'd' || c == 'i')
		len = ft_putnbr_fd_len(va_arg(args, int), 1);
	if (c == 'u')
		len = ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	if (c == 'x')
		len = ft_putnbr_base(va_arg(args, unsigned int), 1, 1);
	if (c == 'X')
		len = ft_putnbr_base(va_arg(args, unsigned int), 1, 2);
	return (len);
}
