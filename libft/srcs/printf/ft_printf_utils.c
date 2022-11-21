/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:30:13 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/18 15:37:23 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	len;

	len = 1;
	if (n > 9)
	{
		len += ft_putnbr_unsigned_fd(n / 10, fd);
		ft_putchar_fd_len((n % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd_len(n + '0', fd);
		return (len);
	}
	return (len);
}

int	ft_putnbr_fd_len(int n, int fd)
{
	int	len;

	len = 1;
	if (n == -2147483648)
	{
		len += write(fd, "-2147483648", 11);
		return (len - 1);
	}
	if (n > 9)
	{
		len += ft_putnbr_fd_len(n / 10, fd);
		ft_putchar_fd_len((n % 10) + '0', fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd_len('-', fd);
		len += ft_putnbr_fd_len(-n, fd);
	}
	else
	{
		ft_putchar_fd_len(n + '0', fd);
		return (len);
	}
	return (len);
}

int	ft_putchar_fd_len(char c, int fd)
{
	int	i;

	i = write(fd, &c, 1);
	return (i);
}

int	ft_putstr_fd_len(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		i += write(fd, "(null)", 6);
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd_len(s[i], fd);
			i++;
		}
	}
	return (i);
}
