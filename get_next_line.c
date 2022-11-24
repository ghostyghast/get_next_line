/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:44 by amaligno          #+#    #+#             */
/*   Updated: 2022/11/24 15:41:28 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*stash;
	char	*send;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
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
