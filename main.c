/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/10 10:30:59 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int main()
{
	int 	fd;
	char 	*str;
	int		i;

	fd = 0;

	int x = 8;
	int y = 2;
	i = -1;
	while (get_next_line(fd, &str) > 0)
	{	
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	printf("%d %d\n", 8, 2);
	return (0);
}
