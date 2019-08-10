/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 14:00:00 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/10 16:13:02 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_position(const int fd, char **p)
{
	int		i;

	i = 0;
	while (p[fd][i] != '\0' && p[fd][i] != '\n')
		i++;
	return (i);
}

int			read_line(const int fd, int *r, char **p, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (*r == -1)
		return (-1);
	if (ft_strlen(p[fd]) == 0)
		return (0);
	i = get_next_position(fd, p);
	*line = ft_strsub(p[fd], 0, i);
	tmp = p[fd];
	p[fd] = ft_strdup(p[fd] + i + 1);
	free(tmp);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				i;
	int				r;
	char			*buf;
	char			*tmp;
	static char		*p[1];

	buf = ft_strnew(BUFF_SIZE);
	if (!line || read(fd, buf, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	if (p[fd] == NULL)
		p[fd] = ft_strnew(0);
	while ((r = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[r] = '\0';
		tmp = p[fd];
		p[fd] = ft_strjoin(p[fd], buf);
		free(tmp);
		if (ft_strchr(buf, '\n') != NULL)
			break ;
	}
	free(buf);
	i = read_line(fd, &r, p, line);
	if (i == 0 || i == -1)
		return (i);
	return (1);
}
