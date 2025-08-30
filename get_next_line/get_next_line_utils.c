/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:36:45 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/08/30 14:02:37 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	len_s1_s2;
	char	*result;

	len_s1_s2 = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(((len_s1_s2 + 1) * sizeof(char)));
	if (result == NULL)
		return (NULL);
	aux = result;
	while (*s1)
	{
		*aux = *s1;
		aux++;
		s1++;
	}
	while (*s2)
	{
		*aux = *s2;
		aux++;
		s2++;
	}
	*aux = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	unch_c;

	unch_c = (unsigned char)c;
	while (*s)
	{
		if ((unsigned char)*s == unch_c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (unch_c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
