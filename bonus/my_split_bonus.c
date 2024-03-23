/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaqad <aennaqad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:42:43 by aennaqad          #+#    #+#             */
/*   Updated: 2024/01/30 11:41:43 by aennaqad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker_bonus.h"

char	**freeit(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*allocsingleword(char const *s, size_t *start, char c)
{
	char		*oneword;
	size_t		end;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[*start] == c && s[*start] != '\0')
		(*start)++;
	end = *start;
	while (s[end] != c && s[end] != '\0')
		end++;
	oneword = malloc(sizeof(char) * (end - *start) + 1);
	if (!oneword)
		return (NULL);
	while (*start < end)
		oneword[i++] = s[(*start)++];
	oneword[i] = '\0';
	return (oneword);
}

static size_t	countword(char const *s, char c)
{
	size_t	counter;
	int		k;

	counter = 0;
	k = 0;
	while (*s)
	{
		if (*s != c && k == 0)
		{
			k = 1;
			counter++;
		}
		else if (*s == c)
			k = 0;
		s++;
	}
	return (counter);
}

char	**ft_split(char *s, char c)
{
	char	**all;
	size_t	i;
	size_t	start;
	size_t	countw;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	countw = countword(s, c);
	all = malloc(sizeof(char *) * (countw + 1));
	if (!all)
		return (NULL);
	while (i < countw)
	{
		all[i] = allocsingleword(s, &start, c);
		if (!(all[i]))
			return (freeit(all));
		i++;
	}
	all[countw] = NULL;
	return (free(s), all);
}
