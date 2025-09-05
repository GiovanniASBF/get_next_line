/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:36:15 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/09/05 11:27:24 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_content(int fd, char *buf)
{
	char		*buf_temp;
	ssize_t		content_read;
	char		*read_buf;

	read_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buf)
		return (NULL);
	content_read = 1;
	while (content_read > 0 && !ft_strchr(buf, '\n'))
	{
		content_read = read(fd, read_buf, BUFFER_SIZE);
		if (content_read < 0)
			return (free(read_buf), free(buf), NULL);
		read_buf[content_read] = '\0';
		buf_temp = ft_strjoin(buf, read_buf);
		free(buf);
		buf = buf_temp;
	}
	free(read_buf);
	if (!*buf)
		return (free(buf), NULL);
	return (buf);
}

char	*get_one_line(char *buf)
{
	size_t	len;

	if (!(buf))
		return (NULL);
	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] == '\n')
		len++;
	return (ft_substr(buf, 0, len));
}

static char	*update_buf(char *buf)
{
	size_t	len;
	char	*updated_buf;

	len = 0;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (buf[len] == '\0')
		return (free(buf), NULL);
	updated_buf = ft_substr(buf, len + 1, ft_strlen(buf) - len - 1);
	free(buf);
	return (updated_buf);
}

char	*get_next_line(int fd)
{
	static char	*buf_content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf_content)
	{
		buf_content = malloc(sizeof(char) * 1);
		buf_content[0] = '\0';
	}
	buf_content = add_content(fd, buf_content);
	if (!buf_content)
		return (NULL);
	line = get_one_line(buf_content);
	buf_content = update_buf(buf_content);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open(0, O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)))
	{
    	printf("%s", line);
    	free(line);
	}
	close (fd);
	return (0);
}

The comma operator ( , ) evaluates its first operand, 
discards the result, and then evaluates the second operand, 
returning its value.

free(static_buf) is executed first. 
Since free has a void return type, there's no result to consider.
NULL is then evaluated, 
and its value becomes the result of the entire expression.
The return statement then returns that NULL value.
*/