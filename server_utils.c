/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:20:45 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/26 12:59:27 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

char	bin_to_char(int *byte)
{
	int	i;
	int	c;

	i = 7;
	c = 0;
	while (i >= 0)
	{
		if (byte[i] == 1)
			c += ft_pow(i);
		i--;
	}
	return (c);
}

int	ft_pow(int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result = result * 2;
		exp--;
	}
	return (result);
}

int	fill_byte(int signal)
{
	if (signal == SIGUSR1)
		return (1);
	return (0);
}
