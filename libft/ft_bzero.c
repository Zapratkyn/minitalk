/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:17:43 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/11 14:37:13 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <strings.h>*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	zero;

	i = 0;
	zero = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)zero;
		i++;
	}
}

/*int	main(void)
{
	char	b[] = "Coucou les amis !";

	printf("%s\n", b);

	//printf("%s\n", ft_bzero(b, 7));//
	printf("%s", bzero(b, 7));

	return(0);
}*/