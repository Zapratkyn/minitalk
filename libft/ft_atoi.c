/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:35:38 by gponcele          #+#    #+#             */
/*   Updated: 2022/07/12 17:43:10 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	atoi_limits(unsigned long long result, int sign, int size)
{
	unsigned long long	max;

	max = 9223372036854775807U;
	if (((result > max) || size > 19) && sign > 0)
		return (-1);
	else if (((result > (max + 1)) || size > 19) && sign < 0)
		return (0);
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					i;
	int					sign;
	int					size;

	result = 0;
	i = 0;
	sign = 1;
	size = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		size ++;
	}
	return (atoi_limits(result, sign, size));
}

/*int	main(void)
{
	char	s[] = "1";

	printf("%d\n", ft_atoi(s));
	return (0);
}*/