/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:07:07 by eates             #+#    #+#             */
/*   Updated: 2023/08/28 15:13:44 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_to_stash(char *stash, char *buf)
{
	char	*res;

	if (!stash && buf)
		return (gnl_strdup(buf));
	return (res = ft_strjoin(stash, buf), ft_free_stash(&stash, 0), res);
}

char	*gnl_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	i = -1;
	while (res && (++i == 0 || s1[i - 1] != '\0'))
		res[i] = s1[i];
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	j;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (gnl_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = malloc(sizeof(char) * (len + 1));
	j = 0;
	while (ret && start <= (unsigned int)ft_strlen(s) && j <= len)
		ret[j++] = s[start++];
	return (ret);
}

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (create_line == 0 && *stash)
		free(*stash);
	else if (create_line == 1 && *stash)
		return (line = gnl_strdup(*stash), free(*stash), *stash = NULL, line);
	return (*stash = NULL);
}
