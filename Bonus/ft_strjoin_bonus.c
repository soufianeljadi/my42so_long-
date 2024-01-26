/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:22:08 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 03:45:31 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_join(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;

	if (!start)
		start = ft_strdup("");
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff));
	if (!ptr)
	{
		free(ptr);
		return (NULL);
	}
	ptr = ft_join(ptr, start, buff);
	free(start);
	return (ptr);
}
