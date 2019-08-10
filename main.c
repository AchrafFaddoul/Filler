/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/10 22:34:18 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void 	free_two_dim_arr(char **arr, int size)
{
	int 	i;

	i = 0;
	while (size)
	{
		free(arr[i]);
		i++;
		size--;
	}
	free(arr);
}

void	get_player(int *p)
{
	char **arr;
	char *line;

	get_next_line(0, &line);
	arr = ft_strsplit(line, ' ');
	*p = ft_atoi(arr[2] + 1);
	free_two_dim_arr(arr, 5);
	free(line);
}

void 	get_dimensions(int *x, int *y)
{
	char	**arr;
	char 	*line;

	get_next_line(0, &line);
	arr = ft_strsplit(line, ' ');
	*x = ft_atoi(arr[1]);
	*y = ft_atoi(arr[2]);
	free_two_dim_arr(arr, 3);
	free(line);
}

int 	main()
{
	int player;
	int x;
	int y;

	player = 1;
	x = 0;
	y = 0;
	get_player(&player);
	get_dimensions(&x, &y);
	printf("%d\n%d\n%d\n", player, x, y);
	return (0);
}
