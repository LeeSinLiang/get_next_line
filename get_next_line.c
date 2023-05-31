/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:30:35 by sinlee            #+#    #+#             */
/*   Updated: 2023/05/31 10:26:30 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*extract_and_return(char *str, int mode, char *remain_str)
{
	int		index;
	char	*extract;

	index = ft_strchr(str, '\n');
	if (index != -1 && index != BUFFER_SIZE - 1)
	{
		if (mode == 1 || mode == 2)
		{
			extract = ft_substr(str, index + 1, ft_strlen(str) + 1);
			if (remain_str != NULL && ft_strlen(remain_str) > 0 && mode == 1)
				extract = ft_strjoin(remain_str, extract);
			free(remain_str);
			return (extract);
		}
		else
			return (ft_substr(str, 0, index + 1));
	}
	else if (ft_strlen(str) > 0 && mode == 0)
		return (ft_substr(str, 0, ft_strlen(str) + 1));
	else
	{
		if (mode == 2)
			free(str);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	int			read_size;
	char		*buffer;
	static char	*remain;
	char		*buff_all;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_size = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buff_all = extract_and_return(remain, 0, remain);
	remain = extract_and_return(remain, 2, remain);
	while (ft_strchr(buff_all, '\n') == -1 && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		buffer[read_size] = '\0';
		buff_all = ft_strjoin(buff_all, extract_and_return(buffer, 0, remain));
		remain = extract_and_return(buffer, 1, remain);
	}
	free(buffer);
	return (buff_all);
}
