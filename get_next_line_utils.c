/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:50:41 by ccouliba          #+#    #+#             */
/*   Updated: 2021/03/04 15:45:35 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	if (!s1)
	{
		if (!(s1 = malloc(sizeof(char*))))
			return (0);
		s1[0] = 0;
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1 && s1[++i] != '\0')
		tab[i] = s1[i];
	while (s2 && s2[++j] != '\0')
		tab[i + j] = s2[j];
	free(s1);
	tab[i + j] = '\0';
	return (tab);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;

	if (!(sub = malloc(sizeof(char) * (len - start + 1))))
		return (NULL);
	i = 0;
	while (s && s[start] && start < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
