/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:44 by amaligno          #+#    #+#             */
/*   Updated: 2022/11/24 16:15:10 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, len);
	return (str);
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

char	*get_next_line(int fd)
{
	char	*buf;
	char	*stash;
	char	*send;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	stash = malloc(BUFFER_SIZE * (sizeof(char)));
	if (!buf || !stash)
		return (NULL);
	while (strcheck(stash))
	{
		read(fd, buf, BUFFER_SIZE);
		stash = newstr(stash, buf);
	}
	send = malloc(sizeof(char) * strcheck(stash));
	send = memcpy(send, stash, strcheck(stash));
	return (send);
}
