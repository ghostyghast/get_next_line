/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:14:27 by amaligno          #+#    #+#             */
/*   Updated: 2022/11/23 19:52:28 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	if (!dst || !src)
		return (0);
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	while (src[j] && (dst_len + j) < dst_len)
		dst[i++] = src[j++];
	if ((dst_len + j) == dst_len)
		dst[--i] = '\0';
	else
		dst[i] = '\0';
	return (src_len + dst_len);
}

char	*newstr(char *stash, char *buf)
{
	
}

size_t	ft_strlen(const char *str)
{
	int		num;
	char	*ptr;

	num = 0;
	ptr = (char *)str;
	while (true)
	{
		if (*ptr == '\0')
			break ;
		ptr++;
		num++;
	}
	return (num);
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
	}
	return (0);
}
