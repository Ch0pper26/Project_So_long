/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bis.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:14:03 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/02 14:14:06 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BIS_H
# define LIBFT_BIS_H

/* ft_atoll */
long long	ft_atoll(const char *nptr);
/* ft_strcmp */
int			ft_strcmp(const char *s1, const char *s2);
/* ft_strcpy */
void		ft_strcpy(char *dst, const char *src);
/* ft_search_int_in_tab */
int			ft_find_min(int *tab, int len);
int			ft_find_max(int *tab, int len);
int			ft_find_med(int *tab, int len);
int			ft_next_int(int *tab, int len, int current_int);
int			ft_prev_int(int *tab, int len, int current_int);
/* ft_free */
void		ft_free_split(char **split);
/* ft_len */
int			ft_len_split_with_null(char **split);
int			ft_len_split_no_null(char **split);

#endif
