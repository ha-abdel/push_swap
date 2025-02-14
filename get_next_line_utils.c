/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ha <abdel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:04:42 by abdel-ha          #+#    #+#             */
/*   Updated: 2024/12/02 14:04:43 by abdel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*result;

	len = ft_strlen(s1) + 1;
	result = (char *)ft_calloc(len, 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	totallen;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	totallen = s1len + s2len;
	ptr = (char *)malloc(totallen + 1);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcpy(ptr + s1len, s2);
	ptr[totallen] = '\0';
	return (ptr);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	if ((start) >= ft_strlen(s))
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
