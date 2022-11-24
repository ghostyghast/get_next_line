/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:14:27 by amaligno          #+#    #+#             */
/*   Updated: 2022/11/24 16:13:38 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	move(const char *s1, const char *s2, char *str)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		len;
	char		*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	move(s1, s2, str);
	return (str);
}

char	*newstr(char *stash, char *buf)
{
	char		*temp;
	static int	size;

	size += BUFFER_SIZE;
	temp = stash;
	stash = malloc(sizeof(char) * (size));
	stash = memcpy(stash, temp, size);
	stash = ft_strjoin(stash, buf);
	free(temp);
	return (stash);
}

int	strcheck(char *s)
{
	int	count;

	count = 0;
	while (s)
	{
		if (*s == '\n')
			return (count);
		count++;
		s++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
