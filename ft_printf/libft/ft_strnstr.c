/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:22:38 by abreuil           #+#    #+#             */
/*   Updated: 2024/11/15 16:49:10 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	char	*hay;

	i = 0;
	hay = (char *) haystack;
	needle_len = ft_strlen(needle);
	if (haystack == needle || needle_len == 0)
		return (hay);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] && (i + j) < len
			&& haystack[i + j] == needle[j])
			j++;
		if (j == needle_len)
			return (hay + i);
		i++;
	}
	return (NULL);
}
