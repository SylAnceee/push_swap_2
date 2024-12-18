/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:39:50 by abreuil           #+#    #+#             */
/*   Updated: 2024/11/15 11:56:52 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char) c)
			return ((char *) s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char) c)
		return ((char *)s);
	return (NULL);
}
