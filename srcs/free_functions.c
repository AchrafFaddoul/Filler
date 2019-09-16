/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/09/16 11:41:18 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			free_two_dim_arr(char **arr, int size)
{
	int			i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}

void			free_int_two_dim_arr(int **arr, int size)
{
	int			i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
}
