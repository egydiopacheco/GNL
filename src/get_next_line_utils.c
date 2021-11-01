/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:02:13 by epacheco          #+#    #+#             */
/*   Updated: 2021/10/31 14:41:01 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Given a string S, search for C
 * If found, return the pointer position of C in S
 * Otherwise return NULL.
 */

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
	if (c == NULL_BYTE)
		return (p);
	return (NULL);
}

/*
 * Copy the content of source into destiny, with a fixed 
 * buffer size.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (*(src + i) != NULL_BYTE && i < dstsize - 1)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = NULL_BYTE;
	}
	while (*(src + i) != NULL_BYTE)
		i++;
	return (i);
}

/*
 * Given a string s, synthetize a substring that
 * begins on the integer (start) position of the s array.
 * Substring is limited the len size.
 */

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

/*
 * Given two strings s1 and 2, allocate memory
 * to concatenate s2 at the end of s1.
 * Null terminate the the string.
 */

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
	*(str + size1 + size2) = NULL_BYTE;
	return (str);
}

/*
 * Given a string s, allocate memory for a copy of s.
 * Return the duplicated pointer
 */

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
