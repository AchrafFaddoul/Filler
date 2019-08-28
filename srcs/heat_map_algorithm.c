/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  heat_map_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/26 23:22:46 by ussef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void    		get_result(t_board board, t_token *token, t_hmap coord,
		t_game *game)
{
	int		inter;
	int		score;
	int		i;
	int		x;
	int		y;

	i = 0;
	inter = 0;
	score = 0;
	while (i < token->stars)
	{
		x = token->pos[i].x + coord.i;
		y = token->pos[i].y + coord.j;
		if ((x < 0 || x >= board.x) || (y < 0 || y >= board.y))
			return ;
		if (board.h_map[x][y] == board.target)
			return ;
		if (board.h_map[x][y] == -board.player)
			inter++;
		score += board.h_map[x][y];
		i++;
	}
	if  (inter == 1 && score < game->score)
	{
		game->score = score;
		game->x = (coord.i) - token->min_x;
		game->y = (coord.j) - token->min_y;
	}
}

t_game                          *put_token(t_board board, t_pos *pos, t_token *token)
{
        t_hmap                  h_map;
        t_game                  *game;
        int                     player;

        h_map.i = 0;
        game = ft_memalloc(sizeof(t_game));
        game->score = 5e5;
        token->pos = pos;
        player = -board.player;
        if (player == -1)
                board.target = -2;
        else if (player == -2)
                board.target = -1;
        while (h_map.i < board.x)
        {
                h_map.j = 0;
                while (h_map.j < board.y)
                {
                        get_result(board, token, h_map, game);
                        h_map.j++;
                }
                h_map.i++;
        }
        return (game);
}
