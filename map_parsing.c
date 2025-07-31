/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:27:15 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/12 17:23:45 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != ' '
				&& str[i] != '\n' && str[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

void	parse_line(char *line, t_stack **point, int y)
{
	char	**split;
	int		split_len;
	int		i;
	int		x;

	i = 0;
	x = 0;
	split_len = 0;
	split = ft_split(line, ' ', &split_len);
	while (split && split[i])
	{
		if (!(*point))
			*point = create_list(ft_atoi(split[i]), x, y);
		else
			ft_lstadd_back(point, create_list((ft_atoi(split[i])),
					x, y));
		i++;
		x++;
	}
	if (split)
		free_split(split, split_len);
}

void	check_map(t_stack *map)
{
	int		x;
	t_stack	*tmp;
	int		tmp_nb;
	int		i;

	i = 1;
	tmp = map;
	while (tmp && tmp->y == 0)
	{
		x = tmp->x;
		tmp = tmp->next;
	}
	while (tmp && tmp->y == i)
	{
		while (tmp && tmp->y == i)
		{
			tmp_nb = tmp->x;
			tmp = tmp->next;
		}
		if (tmp_nb != x)
			ft_error_list(&map, "Bad map format.\n");
		i++;
	}
}

void	get_map_points(t_stack **point, int fd, char *line)
{
	int	y;

	y = 0;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		if (check_line(line) == 0)
		{
			free(line);
			get_next_line(fd, 1);
			ft_error_list(point, "Map not readable.\n");
		}
		parse_line(line, point, y);
		free(line);
		y++;
	}
}

void	parse_map(char *filename, int fd, t_stack **point)
{
	char		*line;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	get_map_points(point, fd, line);
	close(fd);
	if (!(*point))
		ft_error(1, "Map not parsed.\n");
	check_map(*point);
}
