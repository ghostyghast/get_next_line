/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:44 by amaligno          #+#    #+#             */
/*   Updated: 2022/12/16 15:30:11 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*newstr(char *stash, char *buf, int start)
{
	char		*temp;

	if (start == 0)
	{
		stash = malloc(1 * sizeof (char));
		stash[1] = '\0';
	}
	// printf("this is stash before strjoin %s]\n", stash);
	// printf("this is buf %s]\n", buf);
	temp = ft_strjoin(stash, buf);
	printf("temp before free %s]\n", temp);
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*stash;
	char			*send;
	int				read_value;
	int				start;

	read_value = 1;
	stash = NULL;
	if (!stash)
		start = 0;
	while (read_value > 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		buf[read_value] = '\0';
		printf("this is stash before newstr %s\n", stash);
		stash = newstr(stash, buf, start);
		start = 1;
		printf("[this is start after newstr [%d]\n", start);
		if (strcheck(stash))
			break ;
	}
	send = malloc(sizeof(char) * (strcheck(stash) + 1));
	send = memcpy(send, stash, strcheck(stash));
	printf("this is send %s\n", send);
	stash = strtrim(send, stash);
	printf("this is trim stash [%s]\n", stash);
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