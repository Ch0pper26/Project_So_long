/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:13:43 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/18 10:24:43 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 4096)
		return (NULL);
	if (buffer[fd] == NULL)
	{
		buffer[fd] = malloc(sizeof(char *) * 1);
		if (buffer[fd] == NULL)
			return (NULL);
		buffer[fd][0] = '\0';
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_recup_line(buffer[fd]);
	buffer[fd] = ft_new_buffer(buffer[fd]);
	if (line[0] == '\0')
	{
		free(buffer[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*ft_read(int fd, char *content)
{
	char			*buffread;
	long			rd;

	buffread = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (buffread == NULL)
	{
		free(content);
		return (NULL);
	}
	rd = 1;
	while (ft_find_bsn(content) == -1 && rd != 0)
	{
		rd = read(fd, buffread, BUFFER_SIZE);
		if (rd == -1)
		{
			free(content);
			free(buffread);
			return (NULL);
		}
		buffread[rd] = '\0';
		content = ft_strjoin(content, buffread);
	}
	free(buffread);
	return (content);
}

char	*ft_recup_line(char *buffer)
{
	long	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (ft_substr(buffer, 0, i + 1));
}

char	*ft_new_buffer(char *old_buffer)
{
	char	*new_buffer;
	long	len;
	long	i;

	i = 0;
	if (ft_strlen(old_buffer) == 0)
	{
		free(old_buffer);
		return (NULL);
	}
	while (old_buffer[i] != '\n' && old_buffer[i] != '\0')
		i++;
	if (old_buffer[i] == '\n')
	{
		len = ft_strlen(old_buffer + i + 1);
		new_buffer = ft_substr(old_buffer, (i + 1), len);
	}
	else
	{
		new_buffer = ft_substr(old_buffer, i, 1);
	}
	free(old_buffer);
	return (new_buffer);
}
