/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:09:42 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/11 15:24:56 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)ch;
		i++;
	}
	return (b);
}

/*int	main(void)
{
	char	b[] = "Coucou les amis !";

	//printf("%s\n", b);//

	//printf("%s\n", ft_memset(b, '$', 7));//
	printf("%s\n", memset(b, '$', 7));

	return(0);
}*/