/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:06:44 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/18 12:17:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*my_dest;
	unsigned char	*my_src;

	my_dest = (unsigned char *)(dst);
	my_src = (unsigned char *)(src); // On crée les chaînes temporaires
	i = 0;
	if (!my_dest && !my_src)
		return (0);
	if (my_dest > my_src) // Si dst est plus grande que src
	{
		while (len > 0)
		{
			my_dest[len - 1] = my_src[len - 1];
			len--;
		}
	}
	while (i < len) // Si src est plus grande que dst
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (my_dest);
}
