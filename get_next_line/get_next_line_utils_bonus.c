/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaguiar- <gaguiar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:32:48 by gaguiar-          #+#    #+#             */
/*   Updated: 2025/09/05 10:34:51 by gaguiar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(const char *s)
{
	char	*aux;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	aux = (char *)malloc((len + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	i = 0;
	while (i < len)
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	aux = (char *)malloc((len + 1) * sizeof(char));
	if (aux == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
			aux[i] = s[start + i];
			i++;
	}
	aux[i] = '\0';
	return (aux);
}
