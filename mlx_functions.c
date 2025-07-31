/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:44:45 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/12 17:31:03 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	zoom_coord(t_stack **point, t_data data)
{
	t_stack	*tmp;
	int		zoom;

	tmp = *point;
	zoom = 1;
	zoom_z(point);
	while (check_overflow(tmp, data, zoom) == 0)
		zoom++;
	while (tmp)
	{
		tmp->x *= zoom;
		tmp->y *= zoom;
		tmp = tmp->next;
	}
}

void	offset(t_stack **point, t_data data)
{
	t_stack		*tmp;
	t_offset	offset;
	int			offx;
	int			offy;

	tmp = *point;
	offx = 0;
	offy = 0;
	get_offset_size(point, &offset);
	while (offset.midx < data.x / 2)
	{
		offset.midx++;
		offx++;
	}
	while (offset.midy < data.y / 2)
	{
		offset.midy++;
		offy++;
	}
	while (tmp)
	{
		tmp->x += offx;
		tmp->y += offy;
		tmp = tmp->next;
	}
}

void	put_points(t_data *data, t_stack **point)
{
	zoom_coord(point, *data);
	isometric_projection(point);
	check_negative(point);
	offset(point, *data);
	trace_line(*point, data);
}

void	visual_part(t_stack *point)
{
	t_data		data;

	data.x = 1200;
	data.y = 800;
	data.fdf = &point;
	data.mlx_ptr = NULL;
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		ft_error(1, "MLX INIT ERROR\n");
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.x, data.y, "FdF");
	if (data.win_ptr == NULL)
		ft_error(1, "MLX WINDOW ERROR\n");
	data.img = mlx_new_image(data.mlx_ptr, data.x, data.y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	put_points(&data, &point);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_window, &data);
	mlx_loop(data.mlx_ptr);
}
