/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 17:36:14 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/13 15:45:21 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "get_next_line.h"

int 					get_next_line(const int fd, char **line);

typedef struct			s_board
{
	char 				**arr;
	int 				x;
	int 				y;
}						t_board;

typedef struct			s_token
{
	char 				**piece;
	int 				x;
	int 				y;
}						t_token;

#endif
