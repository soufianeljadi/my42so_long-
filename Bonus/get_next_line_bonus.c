/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jadi <sel-jadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:44:32 by sel-jadi          #+#    #+#             */
/*   Updated: 2024/01/26 21:16:20 by sel-jadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*ft_line(char *str)
{
	char	*line;
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = (char *)malloc(1 + i);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_move_start(char	*str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i += (str[i] == '\n');
	new_str = (char *)malloc(1 + ft_strlen(str) - i);
	if (!new_str)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		new_str[j] = str[i + j];
		j++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

static char	*ft_store(int fd, char *start_str)
{
	int			fd_read;
	char		*tmp;

	tmp = (char *)malloc(1 + (size_t)BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	fd_read = 1;
	while ((ft_search(start_str, '\n')) == 0 && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			free(start_str);
			return (NULL);
		}
		tmp[fd_read] = '\0';
		start_str = ft_strjoin_gnl(start_str, tmp);
	}
	free(tmp);
	return (start_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*start_str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	start_str[fd] = ft_store(fd, start_str[fd]);
	if (!start_str[fd])
	{
		free(start_str[fd]);
		return (NULL);
	}
	line = ft_line(start_str[fd]);
	start_str[fd] = ft_move_start(start_str[fd]);
	return (line);
}
