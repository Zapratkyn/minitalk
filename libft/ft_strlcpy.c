/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:19:07 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/12 15:41:26 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = (int)dstsize;
	if (size < 0)
	{
		while (i < ft_strlen(src))
		{
			dst[i] = src[i];
			i++;
		}
		return (ft_strlen(src));
	}
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int	main(void)
{
	char  src[] = "coucou";
	char  dest[10];
	memset(dest, 'A', 10);
	ft_strlcpy(dest, src, -1);
	return (0);
}*/
