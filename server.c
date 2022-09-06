/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:17:30 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/01 18:13:17 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	req_trt(int signum, siginfo_t *info, void *context)
{
	

	(void)context;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_signal;

	pid = getpid();
	ft_printf("%d", pid);
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