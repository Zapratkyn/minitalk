/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:57:09 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/12 18:27:52 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (src[j] && (--dstsize - i) && (dstsize))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*int	main(void)
{
	char src[] = "Salut les amis !";
	char dst[50];
	int	dstsize;

	dstsize = ft_strlen(src);
	printf("%d\n", ft_strlcpy(dst, src, dstsize));
	return (0);
}*/