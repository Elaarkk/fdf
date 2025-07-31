/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:36:21 by acolonne          #+#    #+#             */
/*   Updated: 2025/01/22 18:11:27 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	plot_line_low_step(t_calcul *calcul, int *y, int yi)
{
	if (calcul->d > 0)
	{
		*y = *y + yi;
		calcul->d = calcul->d + ((2 * (calcul->dy - calcul->dx)));
	}
	else
		calcul->d = calcul->d + 2 * calcul->dy;
}

void	plot_line_low(t_stack *point, t_stack *point_next, t_data *img)
{
	t_calcul	calcul;
	int			yi;
	int			y;
	int			x;

	calcul.dx = point_next->x - point->x;
	calcul.dy = point_next->y - point->y;
	y = point->y;
	x = point->x;
	yi = 1;
	if (calcul.dy < 0)
	{
		yi = -1;
		calcul.dy = -calcul.dy;
	}
	calcul.d = (2 * calcul.dy) - calcul.dx;
	while (x < point_next->x)
	{
		if (x < img->x && y < img->y && x > 0 && y > 0)
		{
			my_mlx_pixel_put(img, x, y, point->color);
		}
		plot_line_low_step(&calcul, &y, yi);
		x++;
	}
}

void	plot_line_high_step(t_calcul *calcul, int *x, int xi)
{
	if (calcul->d > 0)
	{
		*x = *x + xi;
		calcul->d = calcul->d + ((2 * (calcul->dx - calcul->dy)));
	}
	else
		calcul->d = calcul->d + 2 * calcul->dx;
}

void	plot_line_high(t_stack *point, t_stack *point_next, t_data *img)
{
	t_calcul	calcul;
	int			xi;
	int			y;
	int			x;

	calcul.dx = point_next->x - point->x;
	calcul.dy = point_next->y - point->y;
	xi = 1;
	if (calcul.dx < 0)
	{
		xi = -1;
		calcul.dx = -calcul.dx;
	}
	calcul.d = (2 * calcul.dx) - calcul.dy;
	y = point->y;
	x = point->x;
	while (y < point_next->y)
	{
		if (x < img->x && y < img->y && x > 0 && y > 0)
		{
			my_mlx_pixel_put(img, x, y, point->color);
		}
		plot_line_high_step(&calcul, &x, xi);
		y++;
	}
}
