/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:47:42 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/11 17:51:17 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		c;
	char	*copy;

	i = 0;
	c = 0;
	while (src[i])
		i++;
	i++;
	copy = malloc (sizeof(char) * i);
	if (!copy)
		return (0);
	while (src[c])
	{
		copy[c] = src[c];
		c++;
	}
	copy[c] = '\0';
	return (copy);
}
