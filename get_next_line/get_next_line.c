/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:36:15 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/30 14:17:45 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_content(int fd, char **buf);

char	*get_next_line(int fd)
{
	static char	*buf_content;
	int			content_read;

	if (!fd)
		return (NULL);
	if (!buf_content)
		buf_content = malloc(sizeof(char) * 1);
	content_read = add_content(fd, &buf_content);
}

char	*add_content(int fd, char **buf)
{
	char	*buf_temp;
	int		content_read;
	char	*line;

	buf_temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf_temp)
		return (NULL);
	content_read = 1;
	while (content_read > 0 && !ft_strchr(*buf, '\n'))
	{
		content_read = read(fd, buf_temp, BUFFER_SIZE);
		if (content_read <= 0)
			break ;
		buf_temp[content_read] = '\0';
		buf = ft_strjoin(*buf, *buf_temp);
	}
	if (content_read < 0)
	{
		free(buf);
		return (NULL);
	}
	line = get_line(&buf);
}

char	*get_line(char **buf)
{
	size_t	counter;
	char	*len;
	char	*line;

	counter = 1;
	len = buf;
	while (*len != '\n')
	{
		counter++;
		len++;
	}
	line = malloc(sizeof(char) * (counter));
	line = ft_strlcpy(line, buf, counter);
	return (line);
	//*buf = update_buf();
}

/*
size_t get_line_size();
	char	*buffer_support;
	buffer_support = malloc(sizeof(char) * line_size);


	A função read carrega o conteúdo de um arquivo na memória, 
	parcial ou totalmente, usando seu file descriptor.
	Portanto, a função read para de ler quando atinge 
	o número de caracteres que indicamos ou o final do arquivo (EOF).
*/