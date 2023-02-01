/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:14:27 by amaligno          #+#    #+#             */
/*   Updated: 2023/02/01 19:15:49 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		len;
	char		*str;

	i = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
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
	return (str);
}

int	strcheck(char *s)
{
	int	count;
	int	index;

	count = -1;
	index = strlen(s) + 1;
	while (++count < index)
	{
		if (s[count] == '\n')
			return (count);
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	int		num;

	num = 0;
	while (str[num])
		num++;
	return (num);
}

char	*to_send(char *str)
{
	char	*nl;
	int		index;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		++ index;
	if (str[index] == '\n')
		++ index;
	// printf("index : %d\n", index);
	nl = (char *)malloc((index + 1) * sizeof(char));
	if (!nl)
		return (NULL);
	nl[index + 1] = '\0';
	while (--index > 0)
		nl[index] = str[index];
	// printf("nl : %c", nl[index]);
	nl[index] = str[index];
	printf("nl : %s", nl);
	return (nl);
}
