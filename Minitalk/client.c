/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:31:46 by yanis             #+#    #+#             */
/*   Updated: 2025/12/04 09:14:59 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static volatile int	g_ack = 0;

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if (c & 0x80)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		while (!g_ack)
			;
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	if (argc != 3)
		return (write(2, "./client <PID> <message>\n", 25), 1);
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	return (0);
}
