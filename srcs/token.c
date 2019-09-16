/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/16 12:27:06 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			check_token(char **arr, int i)
{
	int		j;

	j = 0;
	while (arr[i][j])
	{
		if (arr[i][j] != '*' && (arr[i][j] != '.'))
			return (0);
		j++;
	}
	return (1);
}

char		**create_token(int x, int y)
{
	char	**token;
	int		i;

	i = 0;
	if (!(token = ft_memalloc(sizeof(char *) * (x + 1))))
		return (NULL);
	token[x] = 0;
	while (i < x)
	{
		token[i] = ft_strnew(y);
		if (!token[i])
			return (NULL);
		i++;
	}
	return (token);
}

char		**fill_token(int x, int y)
{
	char	*line;
	int		i;
	int		check;
	char	**token;

	i = -1;
	check = 0;
	if (!(token = create_token(x, y)))
		return (NULL);
	while (++i < x)
	{
		if ((check = get_next_line(0, &line)) != 1)
		{
			free_two_dim_arr(token, x);
			return (NULL);
		}
		ft_strcpy(token[i], line);
		if (!(check = check_token(token, i)))
		{
			free_two_dim_arr(token, x);
			return (NULL);
		}
		ft_strdel(&line);
	}
	return (token);
}
