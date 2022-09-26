/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:17:30 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/26 14:19:01 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	get_len(int sig, int step)
{
	int	result;
	int	exp;

	exp = step - 1;
	result = 1;
	if (sig == SIGUSR1)
	{
		while (exp > 0)
		{
			result = result * 2;
			exp--;
		}
		return (result);
	}
	return (0);
}

int	ft_display(char *str, char c)
{
	static int	a = 0;

	str[a] = c;
	if (str[a] == '\0')
	{
		ft_printf("%s\n", str);
		free(str);
		a = 0;
		return (1);
	}
	a++;
	return (33);
}

void	req_trt(int signal)
{
	static int		byte[8];
	static int		i = 0;
	static int		step = 1;
	static int		k = 0;
	static char		*str = NULL;

	if (step < 32)
		k += get_len(signal, step++);
	else if (step++ == 32)
		str = malloc(sizeof(char) * (k + 1));
	else if (step > 32)
	{
		if (!str)
			exit (0);
		byte[i++] = fill_byte(signal);
		if (i > 7)
		{
			step = ft_display(str, bin_to_char(byte));
			if (step == 1)
				k = 0;
			i = 0;
		}
	}
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	ft_printf("\n\n\n\t\tBienvenue sur minitalk !\n\n\n");
	ft_printf("Utilisez le PID [%d] pour entamer un échange avec moi.\n\n\n", pid);
	while (1)
	{
		signal(SIGUSR1, req_trt);
		signal(SIGUSR2, req_trt);
		pause();
	}
	return (EXIT_SUCCESS);
}
