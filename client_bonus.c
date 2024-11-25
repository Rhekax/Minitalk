/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:38:27 by mdursun           #+#    #+#             */
/*   Updated: 2024/11/15 13:46:11 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_flag;

static void	client_handler(int sig)
{
	g_flag = 1;
	if (sig == SIGUSR1)
		return ;
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (*message)
	{
		i = 8;
		while (i--)
		{
			g_flag = 0;
			if (((*message >> i) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			if (!g_flag)
				pause();
		}
		message++;
	}
}

int	main(int argc, char *argv[])
{
	char				*message;
	pid_t				server_pid;
	struct sigaction	sa;

	sa.sa_handler = client_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
		return (ft_printf("Please enter a valid argument\n"), 1);
	message = argv[2];
	server_pid = ft_atoi(argv[1]);
	send_message(server_pid, message);
	return (0);
}
