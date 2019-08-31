/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/31 19:10:37 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		ft_putresult(int x, int y)
{
	ft_putnbr(x);
	ft_putstr(" ");
	ft_putnbr(y);
	ft_putstr("\n");
}

static int		ft_initdata(t_board *board, t_token *token)
{
	if (get_dim_board(&board->x, &board->y) == -1)
		return (0);
	if (!(board->arr = fill_board(board->x, board->y)))
		return (0);
	if (get_dim_token(&token->x, &token->y) == -1)
		return (0);
	if (!(token->piece = fill_token(token->x, token->y)))
	{
		free_two_dim_arr(board->arr, board->x);
		return (0);
	}
	return (1);
}

static int		ft_destroyall(t_game *game, t_pos *pos,
					t_board *board, t_token *token)
{
	free(game);
	free(pos);
	free_two_dim_arr(board->arr, board->x);
	free_two_dim_arr(token->piece, token->x);
	free_int_two_dim_arr(board->h_map, board->x);
	return (0);
}

int				main(void)
{
	t_board		board;
	t_token		token;
	t_game		*game;
	t_pos		*pos;

	board.player = 1;
	if (get_player(&board.player) == -1)
		return (0);
	while (1)
	{
		if (ft_initdata(&board, &token) == 0)
			return (0);
		board.h_map = create_h_map(board.x, board.y);
		init_h_map(board.h_map, board.arr);
		fill_h_map(board.h_map, board, board.player);
		if (!(pos = get_stars_pos_dispatcher(&token)))
			return (ft_destroyall(NULL, NULL, &board, &token));
		if (!(game = put_token(board, pos, &token)))
			return (ft_destroyall(NULL, pos, &board, &token));
		ft_putresult(game->x, game->y);
		ft_destroyall(game, pos, &board, &token);
	}
	return (0);
}
