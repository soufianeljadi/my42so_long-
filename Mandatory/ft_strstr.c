/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:22:36 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 00:55:27 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strstr(const char *s, const char *to_find)
{
	size_t	j;
	size_t	i;
	size_t	x;
	char	*str;

	i = 0;
	j = 0;
	x = 0;
	str = (char *)s;
	if (to_find[j] == 0)
		return (0);
	if (str == NULL)
		return (0);
	while (str[i++] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
		{
			j++;
			x = i;
		}
		if (to_find[j] == '\0' && str[x + j] == '\0')
			return (1);
		j = 0;
	}
	return (0);
}
