/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:45:37 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/12 17:23:45 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	handle_input(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		free_mlx(data);
		ft_free_list((data->fdf));
		exit(1);
	}
	return (0);
}

int	close_window(t_data *data)
{
	free_mlx(data);
	ft_free_list((data->fdf));
	exit(1);
}

void	get_offset_size(t_stack **point, t_offset *offset)
{
	t_stack	*tmp;

	tmp = *point;
	offset->xmin = tmp->x;
	offset->xmax = tmp->x;
	offset->ymin = tmp->y;
	offset->ymax = tmp->y;
	while (tmp)
	{
		if (offset->xmax < tmp->x)
			offset->xmax = tmp->x;
		if (offset->xmin > tmp->x)
			offset->xmin = tmp->x;
		if (offset->ymax < tmp->y)
			offset->ymax = tmp->y;
		if (offset->ymin > tmp->y)
			offset->ymin = tmp->y;
		tmp = tmp->next;
	}
	offset->midx = (offset->xmax - offset->xmin) / 2;
	offset->midy = (offset->ymax - offset->ymin) / 2;
}
