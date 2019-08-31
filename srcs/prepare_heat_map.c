/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.heat_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/31 19:10:49 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				**create_h_map(int x, int y)
{
	int			**h_map;
	int			i;

	i = 0;
	h_map = ft_memalloc(sizeof(int *) * x);
	while (i < x)
	{
		h_map[i] = ft_memalloc(sizeof(int) * y);
		i++;
	}
	return (h_map);
}

void			init_h_map(int **h_map, char **board)
{
	int			i;
	int			j;

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

void			put_score(int **h_map, t_hmap map, t_board board, int score)
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

void			fill_h_map(int **h_map, t_board board, int player)
{
	int			i;
	int			j;
	int			target;
	int			score;

	i = 0;
	target = 0;
	score = 1;
	target = (player == 1) ? -2 : -1;
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
				target = score++;
			}
			j++;
		}
		i++;
	}
}
