/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/15 16:32:03 by afaddoul         ###   ########.fr       */
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

void 		free_int_two_dim_arr(int **arr, int size)
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
		if (ft_strnequ(line, "$$$ exec p", 10))
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
		if (ft_strnequ(line, "Plateau", 7))
		{
			*x = ft_atoi(arr[1]);
			*y = ft_atoi(arr[2]);
		}
		else
			return (-1);
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
	board = ft_memalloc(sizeof(char *) * (x + 1));
	board[x] = 0;
	while (x)
	{
		board[i] = ft_strnew(y);
		i++;
		x--;
	}
	return (board);
}

int 		check_board(char **arr, int i)
{
	int 	j;

	j = 0;
	while (arr[i][j])
	{
		if (arr[i][j] != 'o' && arr[i][j] != 'O' && arr[i][j] != 'x' &&
				arr[i][j] != 'X'  && arr[i][j] != '.')
			return (0);
		j++;
	}
	return (1);
}

int 		check_token(char **arr, int i)
{
	int 	j;

	j = 0;
	while (arr[i][j])
	{
		if (arr[i][j] != '*' && (arr[i][j] != '.'))
			return (0);
		j++;
	}
	return (1);
}

char 		**fill_board(int x, int y)
{
	char 	*line;
	int  	i;
	int 	check;
	char 	**board;

	i = 0;
	check = 0;
	check = get_next_line(0, &line);
	if (check != 1)
		return (NULL);
	board = create_board(x, y);
	ft_strdel (&line);
	while (i < x)
	{
		check = get_next_line(0, &line);
		if (check != 1)
			return (NULL);
		ft_strcpy(board[i], (ft_strchr(line, ' ') + 1));
		check = check_board(board, i);
		if (!check)
			return (NULL);
		ft_strdel(&line);
		i++;
	}	
	return (board);
}

char 		**create_token(int x, int y)
{
	char 	**token;
	int 	i;

	i = 0;
	token = ft_memalloc(sizeof(char *) * (x + 1));
	token[x] = 0;
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
	int 	check;
	char 	**token;

	i = 0;
	check = 0;
	token = create_token(x, y);
	while (x)
	{
		check = get_next_line(0, &line);
		if (check != 1)
			return (NULL);
		ft_strcpy(token[i], line);
		check = check_token(token, i);
		if (!check)
			return (NULL);
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
		if (ft_strnequ(line, "Piece", 5))
		{
			*x = ft_atoi(arr[1]);
			*y = ft_atoi(arr[2]);
		}
		else
			return (-1);
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

int 		**create_h_map(int x, int y)
{
	int 		**h_map;
	int 		i;

	i = 0;
	h_map = ft_memalloc(sizeof(int *) * x);
	while (x)
	{
		h_map[i] = ft_memalloc(sizeof(int) * y);
		i++;
		x--;
	}
	return (h_map);
}

void		init_h_map(int **h_map, char **board)
{
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	while (board[i])
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] == 'o' || board[i][j] == 'O')
				h_map[i][j] = -1;
			else if (board[i][j] == 'x' || board[i][j] == 'X')
				h_map[i][j] = -2;
			j++;

		}
		i++;
	}
}

void 		put_score(int **h_map, t_hmap map, t_board board, int score)
{
	if ((map.i + 1) < board.x && h_map[map.i + 1][map.j] == 0)
		h_map[map.i + 1][map.j] = score;
	if ((map.i - 1) >= 0 && h_map[map.i - 1][map.j] == 0)
		h_map[map.i - 1][map.j] = score;
	if ((map.j + 1) < board.y && h_map[map.i][map.j + 1] == 0)
		h_map[map.i][map.j + 1] = score;
	if ((map.j - 1) >= 0 && h_map[map.i][map.j - 1] == 0)
		h_map[map.i][map.j - 1] = score;
	if ((map.i + 1) < board.x && (map.j + 1) < board.y &&
			h_map[map.i + 1][map.j + 1] == 0)
		h_map[map.i + 1][map.j + 1] = score;
	if ((map.i - 1) >= 0 &&
			(map.j - 1) >= 0 && h_map[map.i - 1][map.j - 1] == 0)
		h_map[map.i - 1][map.j - 1] = score;
	if ((map.j + 1) < board.y && (map.i - 1) >= 0 &&
			h_map[map.i - 1][map.j + 1] == 0)
		h_map[map.i - 1][map.j + 1] = score;
	if ((map.j - 1) >= 0 && (map.i + 1) < board.x &&
			h_map[map.i][map.j - 1] == 0)
		h_map[map.i + 1][map.j - 1] = score;
}

void			surround_enemy(int **h_map, t_board board, int target, int scr)
{
	t_hmap		map;

	map.i = 0;
	while (map.i < board.x)
	{
		map.j = 0;
		while (map.j < board.y)
		{
			if (h_map[map.i][map.j] == target)
				put_score(h_map, map, board, scr);
			map.j++;
		}
		map.i++;
	}
}

void 			fill_h_map(int **h_map, t_board board, int player)
{
	int 		i;
	int 		j;
	int 		target;
	int 		score;

	i = 0;
	target = 0;
	score = 1;
	if (player == 1)
		target = -2;
	else if (player == 2)
		target = -1;
	while (i < board.x)
	{
		j = 0;
		while (j < board.y)
		{
			if (h_map[i][j] == target)
			{
				i = 0;
				j = 0;
				surround_enemy(h_map, board, target, score);
				if (target == -1 || target == -2)
					target = 1;
				target = score;
				score++;
			}
			j++;
		}
		i++;
	}
}

int 			count_star(t_count_star *star, t_token token)
{
	int 		i;
	int 		j;

	i = 0;
	while (i < token.x)
	{
		j = 0;
		while (j < token.y)
		{
			if (token.piece[i][j] == '*')
			{
				star->min_x = i;
				star->min_y = j;
				star->target++;
			}
			j++;
		}
		i++;
	}
	return (star->target);
}

void			get_min_max_coord(t_count_star *star, t_token token)
{
	int 		i;
	int 		j;

	i = 0;
	while (i < token.x)
	{
		j = 0;
		while (j < token.y)
		{
			if (token.piece[i][j] == '*')
			{
				if (i < star->min_x)
					star->min_x = i;
				if (j < star->min_y)
					star->min_y = j;
			}
			j++;
		}
		i++;
	}
}

t_pos			*get_stars_pos(t_count_star *star, t_token token, t_pos *pos)
{
	int 			i;
	int 			j;

	i = 0;
	while (i < token.x)
	{
		j = 0;
		while (j < token.y)
		{
			if (token.piece[i][j] == '*')
			{
				(pos[star->k]).x = i - star->min_x;
				(pos[star->k]).y = j - star->min_y;
				star->k++;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_pos				*get_stars_pos_dispatcher(t_token token)
{
	t_pos			*pos;
	t_count_star	*star;

	star = ft_memalloc(sizeof(t_count_star));
	pos = ft_memalloc(sizeof(t_pos) * count_star(star, token));
	get_min_max_coord(star, token);
	pos = get_stars_pos(star, token, pos);
	free(star);
	return (pos);
}

int 		main(void)
{
	t_board		board;
	t_token		token;
	t_pos 		*pos;
	int 		**h_map;
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
		h_map = create_h_map(board.x, board.y);
		init_h_map(h_map, board.arr);
		fill_h_map(h_map, board, player);

		pos = get_stars_pos_dispatcher(token);
		
		int i = 0;
			while (i < 4)
			{
				printf("(%d %d)\n", pos[i].x, pos[i].y);
				i++;
			}
		free(pos);
		free_two_dim_arr(board.arr, board.x);
		free_two_dim_arr(token.piece, token.x);
		free_int_two_dim_arr(h_map, board.x);
		break ;
	}
	return (0);
}

/*
   int i = 0;
   int j = 0;
   while (i < board.x)
   {
   j = 0;
   while (j < board.y)
   {
   printf("%d", h_map[i][j]);
   j++;
   }
   printf("\n");
   i++;
   }
   */

/*
   int i = 0;
   int j = 0;
   while (i < board.x)
   {
   j = 0;
   while (j < board.y)
   {
   printf("%d", h_map[i][j]);
   j++;
   }
   printf("\n");
   i++;
   }
   i = 0;
   j = 0;
   while (i < board.x)
   {
   j = 0;
   while (j < board.y)
   {
   printf("%c", board.arr[i][j]);
   j++;
   }
   printf("\n");
   i++;
   }
   int i = 0;
   int j = 0;
   printf("\n");
   while (i < board.x)
   {
   j = 0;
   while (j < board.y)
   {
   printf("%c", board.arr[i][j]);
   j++;
   }
   printf("\n");
   i++;
   }
   printf("\n");
   i = 0;
   while (i < token.x)
   {
   j = 0;
   while (j < token.y)
   {
   printf("%c", token.piece[i][j]);
   j++;
   }
   printf("\n");
   i++;
   }
   printf("\n");
   i = 0;
   while (i < board.x)
   {
   j = 0;
   while (j < board.y)
   {
   printf("%d", h_map[i][j]);
   j++;
   }
   printf("\n");
   i++;
   }
   printf("\n");
   */
