/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:14:27 by amaligno          #+#    #+#             */
/*   Updated: 2022/12/13 17:46:43 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		len;
	char		*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i++])
		str[i] = s1[i];
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

int	strcheck(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == '\n')
		{
			// printf("this is count %d\n", count);
			return (count);
		}
		count++;
		s++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
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
size_t	ft_strlen(char *str)
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