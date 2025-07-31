/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:50:14 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/13 16:45:38 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	ft_error(int exit_code, char *errormsg)
{
	ft_putstr_fd(errormsg, 2);
	exit(exit_code);
}

void	ft_error_list(t_stack **point, char *str)
{
	if ((*point))
		ft_free_list(point);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_free_list(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	free_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	check_overflow(t_stack *point, t_data data, int zoom)
{
	t_stack	*tmp;

	tmp = point;
	while (tmp)
	{
		if (tmp->x * zoom > (data.x - 500) || tmp->y * zoom > (data.y - 300))
			return (1);
		if (tmp->x * zoom < 0 || tmp->y * zoom < 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
