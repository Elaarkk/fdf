/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:05:04 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/11 19:54:48 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	isometric_projection(t_stack **point)
{
	t_stack	*tmp;
	int		alpha;
	int		map_x;
	int		map_y;
	int		map_z;

	tmp = *point;
	alpha = 120;
	while (tmp)
	{
		map_z = tmp->value;
		map_x = tmp->x;
		map_y = tmp->y;
		tmp->x = (map_x * cos(alpha)) + (map_y * cos(alpha + 2)
				+ (map_z * cos(alpha - 2)));
		tmp->y = (map_x * sin(alpha)) + (map_y * sin(alpha + 2)
				+ (map_z * sin(alpha - 2)));
		tmp = tmp->next;
	}
}

void	check_pent(t_stack *point, t_stack *point_next, t_data *img)
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;

	x0 = point->x;
	x1 = point_next->x;
	y0 = point->y;
	y1 = point_next->y;
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			plot_line_low(point_next, point, img);
		else
			plot_line_low(point, point_next, img);
	}
	else
	{
		if (y0 > y1)
			plot_line_high(point_next, point, img);
		else
			plot_line_high(point, point_next, img);
	}
}

void	trace_line(t_stack *point, t_data *img)
{
	int	i;
	int	line;

	i = 0;
	line = point->line;
	while (point)
	{
		while (point && i < line - 1)
		{
			if (point->next)
				check_pent(point, point->next, img);
			if (point->next_down)
				check_pent(point, point->next_down, img);
			point = point->next;
			i++;
		}
		if (point && point->next_down)
			check_pent(point, point->next_down, img);
		if (point)
			point = point->next;
		i = 0;
	}
}

void	get_color(t_stack **point)
{
	int		z_min;
	int		z_max;
	int		color_max;
	int		color_min;
	t_stack	*tmp;

	z_min = get_z_min(*point);
	z_max = get_z_max(*point);
	color_max = 0xFF96FF;
	color_min = 0x46A0F0;
	tmp = (*point);
	while (tmp)
	{
		if (tmp->value >= ((z_max - z_min) / 2))
			tmp->color = color_max;
		else
			tmp->color = color_min;
		tmp = tmp->next;
	}
}

void	zoom_z(t_stack **point)
{
	t_stack	*tmp;

	tmp = *point;
	while (tmp)
	{
		tmp->value *= 3;
		tmp = tmp->next;
	}
}
