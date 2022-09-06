/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:51:49 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/14 18:18:59 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned char *)s;
	if (n == 0)
		return (0);
	while (i != n)
	{
		if (str[i] == ch)
			return ((void *)s + i);
		else
			i++;
	}
	return (0);
}
