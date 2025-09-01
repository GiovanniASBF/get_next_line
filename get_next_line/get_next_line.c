/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:36:15 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/09/01 13:57:47 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		add_content(int fd, char **buf);
char	*get_line(char **buf);
void	update_buf(char **buf);

char	*get_next_line(int fd)
{
	static char	*buf_content;
	int			content_read;
	char		*line;

	if (!fd)
		return (NULL);
	if (!buf_content)
		buf_content = malloc(sizeof(char) * 1);
	content_read = add_content(fd, &buf_content);
	if (!content_read)
	{
		/* code */
	}
	line = get_line(&buf_content);
	update_buf(&buf_content);
}

int	add_content(int fd, char **buf)
{
	char	*buf_temp;
	int		content_read;
	char	*read_buffer;

	read_buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	content_read = 1;
	while (content_read > 0 && !ft_strchr(*buf, '\n'))
	{
		content_read = read(fd, read_buffer, BUFFER_SIZE);
		if (content_read <= 0)
			break ;
		read_buffer[content_read] = '\0';
		buf_temp = ft_strjoin(*buf, buf_temp);
		free(*buf);
		*buf = buf_temp;
	}
	return (content_read);
}

char	*get_line(char **buf)
{
	size_t	counter;
	char	*len;
	char	*line;

	counter = 1;
	len = *buf;
	while (*len != '\n')
	{
		counter++;
		len++;
	}
	line = malloc(sizeof(char) * (counter));
	line = ft_strlcpy(line, buf, counter);
	return (line);
}

void	update_buf(char **buf)
{
	size_t	len;
	char	*sup_buf;
	char	*updated_buf;

	sup_buf = ft_strchr(*buf, '\n');
	len = ft_strlen(sup_buf);
	updated_buf = malloc(sizeof(char) * len);
	updated_buf = *(sup_buf + 1);
	updated_buf[len] = '\0';
	free(*buf);
	*buf = update_buf;
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