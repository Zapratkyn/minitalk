/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:17:11 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/14 16:11:47 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send(char *str, int server_pid)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		j = 0;
		while (j < 8)
		{
			if (str[i] % 2 == 1)
				kill(server_pid, SIGUSR1);
			else if (str[i] % 2 == 0)
				kill(server_pid, SIGUSR2);
			str[i] /= 2;
			usleep(300);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (!server_pid)
		{
			ft_printf("ERROR : INVALID PID\n");
			return (EXIT_FAILURE);
		}
		send(argv[2], server_pid);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("\nWRONG FORMAT\n");
		ft_printf("EXPECTED FORMAT : ./client [server pid] \"Text\"\n");
		return (EXIT_FAILURE);
	}
}
