/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:17:11 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/23 17:40:01 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	ft_ispid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	send_len(int server_pid, unsigned int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 8)
		{
			if (len % 2 == 1)
				kill(server_pid, SIGUSR1);
			else if (len % 2 == 0)
				kill(server_pid, SIGUSR2);
			len /= 2;
			usleep(100);
			j++;
		}
		i++;
	}
}

void	send(char *str, int server_pid, unsigned int len)
{
	unsigned int	i;
	int				j;

	i = 0;
	send_len(server_pid, len);
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
			usleep(100);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	unsigned int		len;

	if (argc == 3)
	{
		len = ft_strlen(argv[2]);
		if (!len)
		{
			ft_printf("MESSAGE TOO LONG\n");
			return (EXIT_FAILURE);
		}
		if (!ft_ispid(argv[1]))
		{
			ft_printf("ERROR : INVALID PID\n");
			return (EXIT_FAILURE);
		}
		server_pid = ft_atoi(argv[1]);
		send(argv[2], server_pid, len);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("EXPECTED FORMAT : ./client [server pid] \"Text\"\n");
		return (EXIT_FAILURE);
	}
}
