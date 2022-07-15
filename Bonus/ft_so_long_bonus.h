/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:21:12 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/16 10:54:03 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SO_LONG_BONUS_H
# define FT_SO_LONG_BONUS_H

# include <time.h>
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/ashes.h"

/* win size (longeur [0] ,largeur [1]) */
typedef struct s_i {
	void	*img[6];
	int		len;
}				t_i;

typedef struct s_e {
	int	e_x;
	int	e_y;
}				t_e;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_i		*i;
	char	*map;
	char	**map_split;
	int		w_size[2];
	int		px;
	int		py;
	int		nb_move;
	int		nb_coin;
	int		nb_enemies;
	t_e		*en;
	int		pause;
	int		ex;
	int		ey;
}				t_vars;

/* ft_map */
size_t	ft_len_files(int fd);
char	*ft_recup_map(char	*name_file);
/* ft_check */
void	ft_check(char *file);
void	ft_check_extension(char *file);
/* ft_check_map */
int		ft_check_rectangle(char **map_split);
int		ft_check_characters(char *map);
int		ft_check_len(char **map_split);
int		ft_check_wall(char **map_split);
int		ft_check_one(char *map);
/* ft_check_args_bonus */
int		ft_check_is_int(char *nb);
int		ft_check_number(char *nb);
int		ft_check_int(char *nb);
/* ft_window */
void	ft_open_window(t_vars *vars, int nb);
int		ft_key(int keycode, t_vars *vars);
int		ft_close_cross(t_vars *vars);
void	ft_win_size(t_vars *v);
/* ft_free */
void	ft_final_free(t_vars *vars);
void	ft_destroy_img(t_vars *v);
/* ft_image */
t_i		*ft_init_img(t_vars *v, int nb);
void	ft_put_image(t_vars *v);
void	ft_good_put(int i, int j, char c, t_vars *v);
void	ft_init_img_player(t_vars *v, t_i *tab, int nb);
void	ft_blink_player(t_vars *v);
/* ft_find */
void	ft_find_all(t_vars *v);
void	ft_find_enemies(t_vars *v);	
/* ft_move*/
void	ft_move_player(t_vars *v, int i, char c);
void	ft_move_imgplayer(t_vars *v, int i, char c);
void	ft_coin(t_vars *v);
/* ft_end */
void	ft_end(t_vars *v);
/* ft_enemies */
int		ft_auto_move(t_vars *v);
void	ft_init_enemies(t_vars *v);
void	ft_enemie_position(t_vars *v);
void	ft_dead(t_vars *v);
/* ft_move_enemies */
void	ft_move_enemies(t_vars *v);
int		*ft_possible_move(int y, int x, t_vars *v);
void	ft_change_coord(int random, t_vars *v, int i, int *pos);
void	ft_move_imgenemy(t_vars *v, int i, char c, int e);
void	ft_display_pause(t_vars *v);
/* ft_display_string */
void	ft_display_move(t_vars *v);
void	ft_display_coin(t_vars *v);
void	ft_display_name(t_vars *v);

#endif
