/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:44 by amaligno          #+#    #+#             */
/*   Updated: 2022/12/13 17:44:34 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newstr(char *stash, char *buf)
{
	char		*temp;

	temp = stash;
	printf("this is temp %s\n", temp);
	stash = ft_strjoin(temp, buf);
	if (temp)
		free(temp);
	return (stash);
}

char	*strtrim(char *tocut, char *line)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	if (!line)
		return (NULL);
	start = 0;
	i = 0;
	end = strlen(line);
	while (tocut[start] == line[start] && tocut[start] && line[start])
		start++;
	new = malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	while (start < end)
		new[i++] = line[start++];
	return (new);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*stash;
	char		*send;
	int			read_value;

	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		buf[read_value] = '\0';
		// printf("[this is buf after read [%s]\n", buf);
		// printf("this is stash before newstr %s\n", stash);
		stash = newstr(stash, buf);
		printf("[this is stash after newstr [%s]\n", stash);
	}
	send = malloc(sizeof(char) * (strcheck(stash) + 1));
	send = memcpy(send, stash, strcheck(stash));
	printf("this is send %s\n", send);
	strtrim(send, stash);
	return (send);
}

int	main(void)
{
	static int	fd;
	int	i = 0;

    fd = open("dumb.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open & read file.\n");
        return (1);
    }
	while (i++ < 3)
	{
		printf("main: %s\n", get_next_line(fd));
	}
}