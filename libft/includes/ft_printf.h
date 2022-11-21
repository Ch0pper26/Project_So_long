/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:34:00 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/18 15:38:57 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_putnbr_fd_len(int n, int fd);
int	ft_putchar_fd_len(char c, int fd);
int	ft_putstr_fd_len(char *s, int fd);
int	ft_putnbr_base(unsigned int n, int fd, int b);
int	ft_print_args(char c, va_list args);
int	ft_put_memory(unsigned long n, int fd);
int	ft_put_memory_bis(unsigned long n, int fd, char *base);

#endif
