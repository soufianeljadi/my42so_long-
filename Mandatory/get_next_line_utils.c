/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:43:38 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/23 20:44:22 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_search(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_join(char *dest, char *start, char *buff)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (start && start[i])
	{
		dest[i] = start[i];
		i++;
	}
	j = 0;
	while (buff && buff[j])
	{
		dest[i + j] = buff[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int		len;
	int		i;
	char	*p;

	len = ft_strlen(str);
	i = 0;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	while (i < len)
	{
		p[i] = str[i];
		i++;
	}
	p[len] = '\0';
	return (p);
}

char	*ft_strjoin_gnl(char *start, char *buff)
{
	char	*ptr;

	if (!start && !buff)
		return (NULL);
	else if (!buff)
		return (ft_strdup(start));
	else if (!start)
		return (ft_strdup(buff));
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff));
	if (!ptr)
		return (NULL);
	ptr = ft_join(ptr, start, buff);
	free(start);
	return (ptr);
}
