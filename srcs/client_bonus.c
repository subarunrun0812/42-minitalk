/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subarunrun <subarunrun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:15:38 by susasaki          #+#    #+#             */
/*   Updated: 2022/12/13 15:57:05 by subarunrun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

static void	received_achievement(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Message successfully sent and received", 1);
	exit(0);
}

void	send_char(int str, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__;
	while (bit-- > 0)
	{
		if (str & (1 << bit))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(500);
	}
	return ;
}

void	send_message(char *msg, pid_t pid)
{
	size_t	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_char(msg[i], pid);
		i++;
	}
	send_char('\n', pid);
	return ;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Error : arguments is not 3\n", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (signal(SIGUSR1, &received_achievement) == SIG_ERR)
		exit (1);
	send_message(argv[2], pid);
	while (1)
		pause();
}
