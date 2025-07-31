/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:32:57 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/11 16:34:24 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd == -1)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	check_file_format(char *str, char *ext)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (i == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == ext[j])
		{
			while (str[i + j] == ext[j])
			{
				if (str[i + j] == '\0')
					return (1);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}

t_stack	*find_down(int x, int y, t_stack *point)
{
	while (point)
	{
		if (point->x == x && point->y == y)
			return (point);
		point = point->next;
	}
	return (NULL);
}

void	link_point(t_stack **point)
{
	t_stack	*tmp;

	tmp = *point;
	while (tmp)
	{
		tmp->next_down = find_down(tmp->x, tmp->y + 1, (*point));
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*point;
	int		fd;

	point = NULL;
	fd = 0;
	if (argc < 2)
		ft_error(1, "No arguments.\n");
	if (argc > 3)
		ft_error(1, "Too many arguments\n");
	if (check_file_format(argv[1], ".fdf") == 0)
		ft_error(1, "Wrong file name.\n");
	parse_map(argv[1], fd, &point);
	get_dimension(&point);
	link_point(&point);
	get_color(&point);
	visual_part(point);
	ft_free_list(&point);
}
