/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:08:28 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/19 12:00:18 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_putnbr_base(unsigned int n, int fd, int b)
{
	int				len;
	char			*base;
	unsigned int	len_base;

	len = 1;
	if (b == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len_base = ft_strlen(base);
	if (n < len_base)
	{
		ft_putchar_fd_len(base[n], fd);
		return (len);
	}
	else
	{
		len += ft_putnbr_base(n / len_base, fd, b);
		ft_putnbr_base(n % len_base, fd, b);
	}
	return (len);
}

int	ft_put_memory(unsigned long n, int fd)
{
	int	len;

	len = 0;
	if (n == 0)
		len += write(fd, "(nil)", 5);
	else
	{
		len += write(fd, "0x", 2);
		len += ft_put_memory_bis(n, fd, "0123456789abcdef");
	}
	return (len);
}

int	ft_put_memory_bis(unsigned long n, int fd, char *base)
{
	int				len;
	unsigned int	len_base;

	len = 1;
	len_base = ft_strlen(base);
	if (n < len_base)
	{
		ft_putchar_fd_len(base[n], fd);
		return (len);
	}
	else
	{
		len += ft_put_memory_bis(n / len_base, fd, base);
		ft_put_memory_bis(n % len_base, fd, base);
	}
	return (len);
}
