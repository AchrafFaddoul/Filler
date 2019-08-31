/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_game_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/31 19:10:42 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_player(int *p)
{
	char	**arr;
	char	*line;
	int		check;
	int		ret;
	int		i;

	i = 0;
	check = get_next_line(0, &line);
	if (check != 1)
		return (-1);
	if (!(arr = ft_strsplit(line, ' ')))
		return (-1);
	while ((i < 5) && arr[i])
		i++;
	if (i == 5)
	{
		if (ft_strnequ(line, "$$$ exec p", 10))
			*p = ft_atoi(arr[2] + 1);
		else
			return (-1);
	}
	free_two_dim_arr(arr, (i + 1));
	free(line);
	ret = (i == 5 && check == 1) ? 1 : -1;
	return (ret);
}

static int	is_plateau_line_true(char *line, char **arr, int *x, int *y)
{
	if (ft_strnequ(line, "Plateau", 7))
	{
		*x = ft_atoi(arr[1]);
		*y = ft_atoi(arr[2]);
	}
	else
		return (0);
	return (1);
}

int			get_dim_board(int *x, int *y)
{
	char	**arr;
	char	*line;
	int		check;
	int		ret;
	int		i;

	i = 0;
	check = get_next_line(0, &line);
	if (check != 1)
		return (-1);
	arr = ft_strsplit(line, ' ');
	while ((i < 3) && arr && arr[i])
		i++;
	if (i == 3)
	{
		if (!(is_plateau_line_true(line, arr, x, y)))
			return (-1);
	}
	free_two_dim_arr(arr, i + 1);
	free(line);
	ret = (i == 3) ? 1 : -1;
	return (ret);
}

static int	is_piece_line_true(char *line, char **arr, int *x, int *y)
{
	if (ft_strnequ(line, "Piece", 5))
	{
		*x = ft_atoi(arr[1]);
		*y = ft_atoi(arr[2]);
	}
	else
		return (0);
	return (1);
}

int			get_dim_token(int *x, int *y)
{
	char	**arr;
	char	*line;
	int		ret;
	int		i;

	i = 0;
	get_next_line(0, &line);
	arr = ft_strsplit(line, ' ');
	while ((i < 3) && arr[i])
		i++;
	if (i == 3)
	{
		if (!(is_piece_line_true(line, arr, x, y)))
			return (-1);
	}
	free_two_dim_arr(arr, i + 1);
	free(line);
	ret = (i == 3) ? 1 : -1;
	return (ret);
}
