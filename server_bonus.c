/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:17:30 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/15 12:08:09 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

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

char	bin_to_char(int *byte)
{
	int	i;
	int	c;

	i = 7;
	c = 0;
	while (i >= 0)
	{
		if (byte[i] == 1)
		{
			c += ft_pow(i);
		}
		i--;
	}
	return (c);
}

int	fill_byte(int signal)
{
	if (signal == SIGUSR1)
		return (1);
	return (0);
}

void	req_trt(int signal, siginfo_t *info, void *context)
{
	static int		byte[8];
	char			character;
	static int		i = 0;
	pid_t			client_pid;

	(void)context;
	client_pid = info->si_pid;
	byte[i] = fill_byte(signal);
	i++;
	if (i > 7)
	{
		character = bin_to_char(byte);
		if (character != 0)
			write (1, &character, 1);
		if (character == 0)
		{
			write (1, "\n", 1);
			kill(client_pid, SIGUSR2);
		}
		i = 0;
	}
	usleep(100);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_signal;

	pid = getpid();
	ft_printf("\n\n\n\t\tBienvenue sur minitalk !\n\n\n");
	ft_printf("Utilisez le PID [%d] pour entamer un échange avec moi.\n\n\n", pid);
	sa_signal.sa_sigaction = req_trt;
	sa_signal.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &sa_signal, 0);
		sigaction(SIGUSR2, &sa_signal, 0);
		pause();
	}
	return (EXIT_SUCCESS);
}
