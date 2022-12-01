/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:44 by amaligno          #+#    #+#             */
/*   Updated: 2022/12/01 17:07:46 by amaligno         ###   ########.fr       */
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
	char			buf[BUFFER_SIZE + 1];
	static char		*stash;
	char			*send;
	int				read_value;

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
	stash += (strcheck(stash) + 1);
	printf("this is stash after plus [%s]\n", stash);
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