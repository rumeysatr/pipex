/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:58:51 by rutatar           #+#    #+#             */
/*   Updated: 2023/10/25 05:29:12 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	r_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] && str[i] != c
			&& (str[i + 1] == c || str[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static int	l_len(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

static char	**ft_free(char **res, int x)
{
	while (x-- > 0)
		free(res[x]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int		rlen;
	int		x;
	int		i;
	int		len;
	char	**res;

	rlen = r_len(str, c);
	x = 0;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (rlen + 1));
	if (!res)
		return (NULL);
	res[rlen] = NULL;
	while (x < rlen)
	{
		while (str[i] == c || str[i] == '\0')
			i++;
		len = l_len(str + i, c);
		res[x] = ft_substr(str, i, len);
		if (!(res[x]))
			return (ft_free(res, x));
		i += len + 1;
		x++;
	}
	return (res);
}
