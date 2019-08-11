/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/11 20:47:31 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h" 
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
	if (flg == 2)
	{
		if (!ft_strstr(arr[0], "Piece"))
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

int			get_dim_board(int *x, int *y)
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
	board = ft_memalloc(sizeof(char **) * (x + 1));
	board[x + 1] = 0;
	while (x)
	{
		board[i] = ft_strnew(y);
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

char 		**create_token(int x, int y)
{
	char 	**token;
	int 	i;

	i = 0;
	token = ft_memalloc(sizeof(char **) * (x + 1));
	token[x + 1] = 0;
	while (x)
	{
		token[i] = ft_strnew(y);
		i++;
		x--;
	}
	return (token);
}

char 		**fill_token(int x, int y)
{
	char 	*line;
	int  	i;
	char 	**token;

	i = 0;
	token = create_board(x, y);
	while (x)
	{
		get_next_line(0, &line);
		ft_strcpy(token[i], line);
		ft_strdel(&line);
		i++;
		x--;
	}
	return (token);
}

int			get_dim_token(int *x, int *y)
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
		if ((check = check_args(arr, 2)))
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

int 			main()
{
	t_board		board;
	t_token		token;
	int 		player;
	int 		check;

	player = 1;
	check = 0;
	check = get_player(&player);
	if (check == -1)
		return (0);
	while (1)
	{
		check = get_dim_board(&(board.x), &(board.y));
		if (check == -1)
			return (0);
		board.arr = fill_board(board.x, board.y);
		check = get_dim_token(&(token.x), &(token.y));
		if (check == -1)
			return (0);
		token.piece = fill_token(token.x, token.y);
		/*
		 *algorithm
		 */
		free_two_dim_arr(board.arr, board.x);
		free_two_dim_arr(token.piece, token.x);
	}
	return (0);
}
