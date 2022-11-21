/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:06:18 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/12 17:41:24 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*ft_strjoin_free(char const *s1, char const *s2);
int		ft_find_bsn(char *str);
char	*ft_read(int fd, char *buffer);
char	*ft_new_buffer(char *buffer);
char	*ft_recup_line(char *buffer);

#endif
