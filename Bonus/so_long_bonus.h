/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:07:04 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 21:13:37 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define B16L "0123456789abcdef"
# define B16U "0123456789ABCDEF"
# define B10 "0123456789"

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <libc.h>

# define ESC 53

# define W 13
# define A 0
# define S 1
# define D 2 

# define KEYUP 126 
# define KEYLEFT 123 
# define KEYDOWN 125 
# define KEYRIGHT 124

typedef struct s
{
	char	**map;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	void	*wall;
	void	*space;
	void	*down;
	void	*up;
	void	*left;
	void	*right;
	void	*coin;
	void	*enemy;
	void	*exit_o;
	void	*exit_c;
	int		x;
	int		y;
	int		e_x;
	int		e_y;
	int		moves;
	int		player;
	int		coins;
	int		exit;
}	t_struct;

int		ft_close(t_struct *s);
//iniatialisation
void	init_mlx(t_struct *s);
void	init_struct(t_struct *s, char *av);
char	**get_map(int fd);
void	ber_check(char *map);
//parse_map
void	parse_map(t_struct *s, char *av);
void	map_ckeck_extremes(char **map);
void	map_ckeck_middle(char **map);
void	map_ckeck_lines_lenght(char **map);
void	map_ckeck_present(t_struct *s);
//valid_path
void	ft_flood_fill(char **map, int x, int y);
void	ft_check_flood_fill(char **map);
void	check_valid_path(t_struct *s, char *av);
//handle_img
void	load_img(t_struct *s);
void	draw_img(t_struct *s, int x, int y);
void	put_img(t_struct *s);
void	check_image(t_struct	*s);
//get map info 
void	get_player_position(t_struct *s);
void	get_exit_position(t_struct *s);
int		get_element_number(t_struct *s, char c);
int		line_num(char **tab);
//directions
void	up(t_struct *s);
void	down(t_struct *s);
void	left(t_struct *s);
void	right(t_struct *s);
//handle_keycode
int		key_hook(int keycode, t_struct *s);
void	move_up(t_struct *s);
void	move_down(t_struct *s);
void	move_left(t_struct *s);
void	move_right(t_struct *s);
// gnl
char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_search(char *s, int c);
char	*ft_strjoin_gnl(char *start, char *buff);
char	*ft_strdup(char *str);
//printf
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_put_d(long long n, char *base);
int		ft_put_u(unsigned long long n, char *base);
//others
char	*ft_itoa(int nbr);
void	ft_free_tab(char **tab);
char	**ft_split(char const *str, char c);
int		ft_strstr(const char *s, const char *to_find);
char	*ft_strjoin(char *s1, char *s2);
#endif