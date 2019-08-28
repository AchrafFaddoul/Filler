/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/28 19:50:43 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					count_star(t_count_star *star, t_token *token)
{
	int				i;
	int				j;

	i = 0;
	token->min_x = -1;
	token->min_y = -1;
	while (i < token->x)
	{
		j = 0;
		while (j < token->y)
		{
			if (token->piece[i][j] == '*')
				star->target++;
			j++;
		}
		i++;
	}
	return (star->target);
}

void				get_min_coord(t_token *token)
{
	int				i;
	int				j;

	i = 0;
	token->min_x = token->x;
	token->min_y = token->y;
	while (i < token->x)
	{
		j = 0;
		while (j < token->y)
		{
			if (token->piece[i][j] == '*')
			{
				if (i < token->min_x)
					token->min_x = i;
				if (j < token->min_y)
					token->min_y = j;
			}
			j++;
		}
		i++;
	}
}

t_pos				*get_stars_pos(t_count_star *star, t_token *token,
		t_pos *pos)
{
	int				i;
	int				j;

	i = 0;
	while (i < token->x)
	{
		j = 0;
		while (j < token->y)
		{
			if (token->piece[i][j] == '*')
			{
				(pos[star->k]).x = i - token->min_x;
				(pos[star->k]).y = j - token->min_y;
				star->k++;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_pos				*get_stars_pos_dispatcher(t_token *token)
{
	t_pos			*pos;
	t_count_star	*star;
	int				star_nb;

	if (!(star = ft_memalloc(sizeof(t_count_star))))
		return (NULL);
	star_nb = count_star(star, token);
	pos = ft_memalloc(sizeof(t_pos) * star_nb);
	get_min_coord(token);
	pos = get_stars_pos(star, token, pos);
	token->stars = star_nb;
	free(star);
	return (pos);
}
