/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:36:14 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/16 12:07:21 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "get_next_line.h"

int				get_next_line(const int fd, char **line);

typedef struct 			s_pos
{
	int 			x;
	int 			y;
}				t_pos;

typedef struct			s_board
{
	char 			**arr;
	int 			**h_map;
	int 			x;
	int 			y;
	int 			player;
	int 			target;
}				t_board;

typedef struct			s_token
{
	char 			**piece;
	int 			x;
	int 			y;
	int 			min_x;
	int 			min_y;
	int 			stars;
	t_pos			*pos;
}				t_token;

typedef struct 			s_hmap
{
	int 			i;
	int 			j;
}				t_hmap;

typedef	struct			s_count_star
{
	int 			k;
	int 			target;
}				t_count_star;

typedef struct 			s_game
{
	int 			x;
	int 			y;
	int 			score;
}				t_game;

void				free_two_dim_arr(char **arr, int size);
void				free_int_two_dim_arr(int **arr, int size);
int				get_player(int *p);
int				get_dim_board(int *x, int *y);
int				get_dim_token(int *x, int *y);
char				**create_board(int x, int y);
char				**fill_board(int x, int y);
int				check_board(char **arr, int i);
char				**create_token(int x, int y);
char				**fill_token(int x, int y);
int				check_token(char **arr, int i);
int				**create_h_map(int x, int y);
void				init_h_map(int **h_map, char **board);
void				fill_h_map(int **h_map, t_board board,
		int player);
void				surround_enemy(int **h_map, t_board board,
		int target, int scr);
void				put_score(int **h_map, t_hmap map,
		t_board board, int score);
void				get_result(t_board board, t_token *token,
		t_hmap coord, t_game *game);
t_game                          *put_token(t_board board, t_pos *pos,
		t_token *token);
int				count_star(t_count_star *star, t_token *token);
void				get_min_coord(t_token *token);
t_pos				*get_stars_pos(t_count_star *star,
		t_token *token, t_pos     *pos);
t_pos				*get_stars_pos_dispatcher(t_token *token);



#endif
