/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:57:00 by abreuil           #+#    #+#             */
/*   Updated: 2024/12/18 14:24:09 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_separator(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

size_t	count_words(char *str, char c)
{
	int		i;
	size_t	count;
	bool	in_word;

	i = 0;
	count = 0;
	while (str[i])
	{
		in_word = false;
		while (is_separator(str[i], c))
			i++;
		while (str[i] && !is_separator(str[i], c))
		{
			if (!in_word)
			{
				in_word = true;
				count++;
			}
		}
		i++;
	}
	return (count);
}

char	*get_next_word(char *str, char c)
{
	static int	pointer;
	int			i;
	size_t		len;
	char		*word;
	
	len = 0;
	pointer = 0;
	i = 0;
	while (is_separator(str[pointer], c))
		pointer++;
	while (str[pointer + len] && !is_separator(str[pointer + len], c))
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (str[pointer] && !is_separator(str[pointer], c))
	{
		word[i] = str[pointer];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_diff(char *str, char c)
{
	char	**tab;
	int		i;
	size_t		count;
	
	i = 0;
	count = count_words(str, c);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (count >= 0)
	{
		if (i == 0)
		{
			tab[i] = malloc(sizeof(char) * (count + 1));
			if (!tab[i])
				return (NULL);
			tab[i][0] = '\0';
			continue ;
		}
		tab[i] = get_next_word(str, c);
	}
	tab[i] = NULL;
	return (tab);
}