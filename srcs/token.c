/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/26 23:22:46 by ussef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int             check_token(char **arr, int i)
{
        int     j;

        j = 0;
        while (arr[i][j])
        {
                if (arr[i][j] != '*' && (arr[i][j] != '.'))
                        return (0);
                j++;
        }
        return (1);
}

char            **create_token(int x, int y)
{
        char    **token;
        int     i;

        i = 0;
        token = ft_memalloc(sizeof(char *) * (x + 1));
        token[x] = 0;
        while (i < x)
        {
                token[i] = ft_strnew(y);
                i++;
        }
        return (token);
}

char            **fill_token(int x, int y)
{
        char    *line;
        int     i;
        int     check;
        char    **token;

        i = 0;
        check = 0;
        token = create_token(x, y);
        while (i < x)
        {
                check = get_next_line(0, &line);
                if (check != 1)
                {
                        free_two_dim_arr(token, x);
                        return (NULL);
                }
                ft_strcpy(token[i], line);
                check = check_token(token, i);
                if (!check)
                {
                        free_two_dim_arr(token, x);
                        return (NULL);
                }
                ft_strdel(&line);
                i++;
        }
        return (token);
}
