/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:02:13 by epacheco          #+#    #+#             */
/*   Updated: 2021/10/12 06:14:37 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (!s)
		return (NULL);
	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	max_copy;

	if (!s)
		return (NULL);
	max_copy = len + 1;
	size = 0;
	while (*(s + size))
		size++;
	if (start > size)
		return (ft_strdup(""));
	else if (start + len > size)
		max_copy = (size - start) + 1;
	substr = (char *)malloc((max_copy * sizeof(char)));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, max_copy);
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size1;
	int		size2;

	size1 = 0;
	size2 = 0;
	while (*(s1 + size1))
		size1++;
	while (*(s2 + size2))
		size2++;
	str = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size1 + 1);
	ft_strlcpy(&*(str + size1), s2, size2 + 1);
	*(str + size1 + size2) = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	int		j;
	int		size;

	if (!s)
		return (NULL);
	size = 0;
	while (*(s + size))
		size++;
	size++;
	j = -1;
	s_cpy = (char *)malloc(size * sizeof(char));
	if (!s_cpy)
		return (NULL);
	while (*(s + ++j))
		*(s_cpy + j) = *(s + j);
	*(s_cpy + j) = '\0';
	return (s_cpy);
}
