/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/10 15:46:04 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_player(void)
{
	int player;
	char **arr;
	char *line;

	get_next_line(0, &line);
	arr = ft_strsplit(line, ' ');
	player = ft_atoi(arr[2] + 1);
	free(arr);
	free(line);
	return (player);
}
/// $$$ exec p12  : [PLAYER_NAME]
int 	main()
{
	int player;

	player = get_player();
	printf("|||%d|||\n", player);
	return (0);
}
