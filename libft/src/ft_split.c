/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:19:43 by ynishimu          #+#    #+#             */
/*   Updated: 2023/04/12 18:09:35 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_split(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	delimd_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**free_array(char **str, size_t i)
{
	size_t index;

	index = 0;
	while (index < i)
	{
		free(str[index]);
		index++;
	}
	free(str);
	return (NULL);
}

static void	insert_array(char *str, char const *s, size_t len, size_t *ctn)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[len] = '\0';
	*ctn += len;
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	str_array = (char **)malloc(sizeof(char *) * (count_split(s, c) + 1));
	if (!str_array)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str_array[j] = (char *)malloc(delimd_len(s + i, c) + 1);
			if (!str_array[j])
				return (free_array(str_array, j));
			insert_array(str_array[j++], s + i, delimd_len(s + i, c), &i);
		}
		else
			i++;
	}
	str_array[count_split(s, c)] = NULL;
	return (str_array);
}
