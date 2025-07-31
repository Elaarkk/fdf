/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:51:02 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/12 17:23:44 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>

typedef struct s_stack
{
	int				x;
	int				y;
	int				line;
	int				column;
	int				value;
	int				color;
	struct s_stack	*next;
	struct s_stack	*next_down;
}				t_stack;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	t_stack	**fdf;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_data;

typedef struct s_calcul
{
	int	dx;
	int	dy;
	int	d;
}				t_calcul;

typedef struct s_offset
{
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
	int		midx;
	int		midy;
}				t_offset;

void	ft_error(int exit_code, char *errormsg);

void	parse_map(char *filename, int fd, t_stack **point);

char	**ft_split(char const *s, char c, int *split_len);

int		ft_atoi(const char *nptr);

t_stack	*create_list(int n, int x, int y);

void	ft_lstadd_back(t_stack **lst, t_stack *new);

void	ft_free(t_stack **lst);

void	ft_error_list(t_stack **point, char *str);

char	**free_split(char **split, int a);

void	ft_free_list(t_stack **lst);

void	visual_part(t_stack *point);

int		count_node(t_stack *stack);

int		get_xtot(t_stack *stack);

int		get_ytot(t_stack *stack);

void	get_dimension(t_stack **point);

void	check_negative(t_stack **point);

void	isometric_projection(t_stack **point);

void	trace_line(t_stack *point, t_data *img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	plot_line_low(t_stack *point, t_stack *point_next, t_data *img);

void	plot_line_high(t_stack *point, t_stack *point_next, t_data *img);

void	check_coord(t_stack *point, int x, int y, t_data *data);

void	free_mlx(t_data *data);

int		handle_input(int keycode, t_data *data);

int		close_window(t_data *data);

void	ft_putstr_fd(char *s, int fd);

int		get_z_min(t_stack *point);

int		get_z_max(t_stack *point);

void	get_color(t_stack **point);

void	get_color(t_stack **point);

int		check_overflow(t_stack *point, t_data data, int zoom);

void	zoom_z(t_stack **point);

void	get_offset_size(t_stack **point, t_offset *offset);

#endif