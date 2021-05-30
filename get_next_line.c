/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:46:46 by ccouliba          #+#    #+#             */
/*   Updated: 2021/03/04 15:57:02 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_bs_n(char *str)
{
	int i;

	i = -1;
	while (str && str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

static int	get_stock(int fd, char **stock)
{
	char	buf[BUFFER_SIZE + 1];
	int		res;

	while ((find_bs_n(*stock) == -1) && (res = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[res] = '\0';
		if (!(*stock = ft_strjoin(*stock, buf)))
			return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char *stock = NULL;
	char		*rest;

	if (fd < 0 || !line || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(get_stock(fd, &stock)))
		return (-1);
	if (find_bs_n(stock) > -1)
	{
		*line = ft_substr(stock, 0, find_bs_n(stock));
		rest = ft_substr(stock, (find_bs_n(stock) + 1), ft_strlen(stock));
		free(stock);
		stock = ft_substr(rest, 0, ft_strlen(rest));
		free(rest);
		return (1);
	}
	*line = ft_substr(stock, 0, ft_strlen(stock));
	free(stock);
	stock = NULL;
	return (0);
}
