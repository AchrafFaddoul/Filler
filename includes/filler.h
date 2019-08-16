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

int 					get_next_line(const int fd, char **line);

typedef struct 			s_pos
{
	int 				x;
	int 				y;
}						t_pos;

typedef struct			s_board
{
	char 				**arr;
	int 				**h_map;
	int 				x;
	int 				y;
	int 				player;
	int 				target;
}						t_board;

typedef struct			s_token
{
	char 				**piece;
	int 				x;
	int 				y;
	int 				min_x;
	int 				min_y;
	int 				stars;
	t_pos				*pos;
}						t_token;

typedef struct 			s_hmap
{
	int 				i;
	int 				j;
}						t_hmap;

typedef	struct			s_count_star
{
	int 				k;
	int 				target;
}						t_count_star;

typedef struct 			s_game
{
	int 				x;
	int 				y;
	int 				score;
}						t_game;

#endif
