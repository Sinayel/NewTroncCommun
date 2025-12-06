/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:45:34 by ylouvel           #+#    #+#             */
/*   Updated: 2025/12/04 09:21:41 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	sig_action(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	(void)context;
	if (sig == SIGUSR1)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID = %d\n", getpid());
	sa.sa_sigaction = sig_action;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
