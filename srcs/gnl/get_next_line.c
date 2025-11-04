/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:22:44 by chnaranj          #+#    #+#             */
/*   Updated: 2024/10/30 20:45:09 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub.h"

static char	*ft_concat(char *accum, char *read_buf)
{
	char	*temp;

	temp = ft_strjoin(accum, read_buf);
	if (temp[0] == '\0')
	{
		free (temp);
		free(accum);
		return (NULL);
	}
	free(accum);
	return (temp);
}

static char	*ft_next(char *accum)
{
	char	*new_buffer;
	char	*newline_pos;

	newline_pos = ft_strchr(accum, '\n');
	if (!newline_pos)
	{
		free(accum);
		return (NULL);
	}
	new_buffer = ft_strdup(newline_pos + 1);
	if (!new_buffer)
	{
		free(accum);
		return (NULL);
	}
	if (new_buffer[0] == '\0')
	{
		free(new_buffer);
		new_buffer = NULL;
	}
	free(accum);
	return (new_buffer);
}

static char	*ft_line(char *accum)
{
	char	*line;
	size_t	len;
	char	*newline_pos;

	if (!*accum)
		return (NULL);
	newline_pos = ft_strchr(accum, '\n');
	if (newline_pos)
		len = newline_pos - accum + 1;
	else
		len = ft_strlen(accum);
	line = ft_substr(accum, 0, len);
	return (line);
}

static char	*read_file(int fd, char *accum, char *read_buf)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(accum, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(accum);
			return (NULL);
		}
		read_buf[bytes_read] = '\0';
		accum = ft_concat(accum, read_buf);
		if (!accum)
			return (NULL);
	}
	return (accum);
}

char	*get_next_line(int fd)
{
	static char	*accum;
	char		*line;
	char		*read_buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!accum)
	{
		accum = (char *)malloc(1);
		if (!accum)
			return (NULL);
		*accum = '\0';
	}
	read_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	accum = read_file(fd, accum, read_buf);
	free(read_buf);
	if (!accum)
		return (NULL);
	line = ft_line(accum);
	accum = ft_next(accum);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int     main(void)
{
        int             fd;
        char    *line;

        fd = open("vacio.txt", O_RDONLY);
        if (fd < 0)
        {
                perror("Error al abrir el archivo");
                return (1);
        }
        while ((line = get_next_line(fd)) != NULL)
        {
                printf("%s", line);
                free(line);
        }
        close(fd);
        return (0);
}*/
