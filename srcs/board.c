/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:33:20 by afaddoul          #+#    #+#             */
/*   Updated: 2019/08/26 23:22:46 by ussef            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

char            **create_board(int x, int y)
{
        char    **board;
        int     i;

        i = 0;
        board = ft_memalloc(sizeof(char *) * (x + 1));
        board[x] = 0;
        while (x)
        {
                board[i] = ft_strnew(y);
                i++;
                x--;
        }
        return (board);
}

char            **fill_board(int x, int y)
{
        char    *line;
        int     i;
        int     check;
        char    **board;

        i = 0;
        check = 0;
        check = get_next_line(0, &line);
        if (check != 1)
                return (NULL);
        board = create_board(x, y);
        ft_strdel (&line);
        while (i < x)
        {
                check = get_next_line(0, &line);
                if (check != 1)
                        return (NULL);
                ft_strcpy(board[i], (ft_strchr(line, ' ') + 1));
                check = check_board(board, i);
                if (!check)
                        return (NULL);
                ft_strdel(&line);
                i++;
        }
        return (board);
}

int             check_board(char **arr, int i)
{
        int     j;

        j = 0;
        while (arr[i][j])
        {
                if (arr[i][j] != 'o' && arr[i][j] != 'O' && arr[i][j] != 'x' &&
                                arr[i][j] != 'X'  && arr[i][j] != '.')
                        return (0);
                j++;
        }
        return (1);
}
