/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/11 17:36:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void 		free_two_dim_arr(char **arr, int size)
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

int 		check_args(char **arr, int flg)
{
	int 	check;

	check = 0;
	if (flg == 0)
	{
		if (!ft_strstr(arr[0], "$$$"))
			return (0);
		if (!ft_strstr(arr[1], "exec"))
			return (0);
		if (!ft_strstr(arr[2], "p"))
			return (0);
	}
	if (flg == 1)
	{
		if (!ft_strstr(arr[0], "Plateau"))
			return (0);
	}
	return (1);
}

int			get_player(int *p)
{
	char 	**arr;
	char 	*line;
	int 	check;
	int 	i;

	i = 0;
	check = 0;
	get_next_line(0, &line);
	arr = ft_strsplit(line, ' ');
	while ((i < 5) && arr[i])
		i++;
	if (i == 5)
	{
		if ((check = check_args(arr, 0)))
			*p = ft_atoi(arr[2] + 1);
		else
			return (-1);
	}
	else if ((i != 5) || check == -1)
	{
		free_two_dim_arr(arr, (i + 1));
		free(line);
		return (-1);
	}
	free_two_dim_arr(arr, (i + 1));
	free(line);
	return (1);
}

int			get_dimensions(int *x, int *y)
{
	char	**arr;
	char 	*line;
	int 	check;
	int 	i;

	i = 0;
	check = 0;
	get_next_line(0, &line);
	arr = ft_strsplit(line, ' ');
	while ((i < 3) && arr[i])
		i++;
	if (i == 3)
	{
		if ((check = check_args(arr, 1)))
		{
			*x = ft_atoi(arr[1]);
			*y = ft_atoi(arr[2]);
		}
	}
	else
	{
		free_two_dim_arr(arr, i + 1);
		free(line);
		return (-1);
	}
	free_two_dim_arr(arr, i + 1);
	free(line);
	return (1);
}

char 		**create_board(int x, int y)
{
	char 	**board;
	int 	i;

	i = 0;
	board = ft_memalloc(sizeof(char **) * x);
	while (x)
	{
		board[i] = ft_memalloc(sizeof(char *) * y);
		i++;
		x--;
	}
	return (board);
}

char 		**fill_board(int x, int y)
{
	char 	*line;
	int  	i;
	char 	**board;

	i = 0;
	get_next_line(0, &line);
	board = create_board(x, y);
	ft_strdel (&line);
	while (x)
	{
		get_next_line(0, &line);
		ft_strcpy(board[i], (ft_strchr(line, ' ') + 1));
		ft_strdel(&line);
		i++;
		x--;
	}
	return (board);
}

int 		main()
{
	int 	player;
	char 	**board;
	int 	x;
	int 	y;
	int 	check;

	player = 1;
	x = 0;
	y = 0;
	check = 0;
	check = get_player(&player);
	check = get_dimensions(&x, &y);
	if (check == -1)
		return (0);
	board = fill_board(x, y);
	int i = 0;
	int j = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			write(1, &board[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
