/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:47:25 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/03 17:48:28 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	get_xtot(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack && stack->y != 1)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_ytot(t_stack *stack)
{
	int	i;
	int	tmp;

	tmp = -1;
	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		if (tmp != stack->y)
		{
			i++;
			tmp = stack->y;
		}
		stack = stack->next;
	}
	return (i);
}

void	check_negative(t_stack **point)
{
	t_stack	*tmp;
	int		min_x;
	int		min_y;

	tmp = (*point);
	min_x = 0;
	min_y = 0;
	while (tmp)
	{
		if (tmp->x < min_x)
			min_x = tmp->x;
		if (tmp->y < min_y)
			min_y = tmp->y;
		tmp = tmp->next;
	}
	tmp = (*point);
	if (min_x < 0 || min_y < 0)
	{
		while (tmp)
		{
			tmp->x = tmp->x + -min_x;
			tmp->y = tmp->y + -min_y;
			tmp = tmp->next;
		}
	}
}

int	get_z_min(t_stack *point)
{
	int	min;

	if (!point)
		return (0);
	min = point->value;
	while (point)
	{
		if (min > point->value)
			min = point->value;
		point = point->next;
	}
	return (min);
}

int	get_z_max(t_stack *point)
{
	int	max;

	if (!point)
		return (0);
	max = point->value;
	while (point)
	{
		if (max < point->value)
			max = point->value;
		point = point->next;
	}
	return (max);
}
