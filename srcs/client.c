/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susasaki <susasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:15:38 by susasaki          #+#    #+#             */
/*   Updated: 2022/12/01 13:15:38 by susasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

void	send_char(int chara, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__;
	while (bit-- > 0)
	{
		if (chara & (1 << bit))
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
	send_message(argv[2], pid);
}
