/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/26 23:22:46 by ussef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h" 
#include <stdio.h>

int 		main(void)
{
	t_board		board;
	t_token		token;
	t_game		*game;
	t_pos 		*pos;
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
		if (!(board.arr = fill_board(board.x, board.y)))
				return (0);
		check = get_dim_token(&(token.x), &(token.y));
		if (check == -1)
			return (0);
		if (!(token.piece = fill_token(token.x, token.y)))
		{
			free_two_dim_arr(board.arr, board.x);
			return (0);
		}
		board.player = player;
		board.h_map = create_h_map(board.x, board.y);
		init_h_map(board.h_map, board.arr);
		fill_h_map(board.h_map, board, player);
		if (!(pos = get_stars_pos_dispatcher(&token)))
		{
		free_two_dim_arr(board.arr, board.x);
		free_two_dim_arr(token.piece, token.x);
		free_int_two_dim_arr(board.h_map, board.x);
			return (0);
		}
		if (!(game = put_token(board, pos, &token)))
		{
			free(pos);
			return (0);
		}
		ft_putnbr(game->x);
		ft_putstr(" ");
		ft_putnbr(game->y);
		ft_putstr("\n");
		free(game);
		free(pos);
		free_two_dim_arr(board.arr, board.x);
		free_two_dim_arr(token.piece, token.x);
		free_int_two_dim_arr(board.h_map, board.x);
			//break ;
	}
	return (0);
}
