/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:17:27 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/26 14:31:10 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/libft.h"

// server.c

void						compose_message(char *str, char c);
void						req_trt(int signal);
void						make_empty_string(int *byte, int len);
// server_utils.c
char						bin_to_char(int *byte);
int							ft_pow(int exp);
int							fill_byte(int signal);
// server_bonus.c
void						req_trt_bonus(int signal, siginfo_t *info,
								void *context);
int							ft_display_bonus(char *str, char c, int client_pid);
// server_bonus_utils.c
char						bin_to_char_bonus(int *byte);
int							ft_pow_bonus(int exp);
int							fill_byte_bonus(int signal);

#endif