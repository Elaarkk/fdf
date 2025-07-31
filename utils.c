/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:05 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/11 16:34:22 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	number;

	i = 0;
	signe = 1;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = (nptr[i] - 48) + (number * 10);
		i++;
	}
	return (number * signe);
}

t_stack	*create_list(int n, int x, int y)
{
	t_stack		*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (0);
	list->value = n;
	list->y = y;
	list->x = x;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*p;

	p = *lst;
	if (!new)
		return ;
	if (*lst)
	{
		while (p->next)
			p = p->next;
		p->next = new;
		p = new;
	}
	else
		*lst = new;
	return ;
}

int	count_node(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	get_dimension(t_stack **point)
{
	t_stack	*tmp;

	tmp = (*point);
	while (tmp)
	{
		tmp->line = get_xtot((*point));
		tmp->column = get_ytot((*point));
		tmp = tmp->next;
	}
}
