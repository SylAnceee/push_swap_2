/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:43:43 by abreuil           #+#    #+#             */
/*   Updated: 2024/11/15 11:59:15 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if ((unsigned char) *s == (unsigned char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if ((unsigned char) *s == (unsigned char)c)
		return ((char *)s);
	return (last_occurrence);
}
