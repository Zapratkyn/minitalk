/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:17:30 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/06 14:00:35 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	req_trt(int signum)
{
	static int	len;
	static char	*str;
	static int	octet;
	int 		i;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_signal;

	pid = getpid();
	ft_printf("\n\n\n\t\tBienvenue sur minitalk !\n\n\n");
	ft_printf("Utilisez le PID [%d] pour entamer un échange avec moi.\n", pid);
	sa_signal.sa_handler = req_trt;
	while (1)
	{
		sigaction(SIGUSR1, &sa_signal, 0);
		sigaction(SIGUSR2, &sa_signal, 0);
		pause();
	}
	return (EXIT_SUCCESS);
}