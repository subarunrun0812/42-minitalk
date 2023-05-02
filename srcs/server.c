/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:35:44 by marvin            #+#    #+#             */
/*   Updated: 2022/11/20 15:35:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static	void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static int	num;

	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
		num = (num << 1) + 1;
	else
		num = num << 1;
	if (++bit == 8)
	{
		ft_putchar_fd(num, 1);
		num = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("pid = ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) != 0
		|| sigaction(SIGUSR2, &sa, NULL) != 0)
	{
		ft_putstr_fd("Error : failed sigaction.", 1);
		exit(1);
	}
	while (1)
		pause();
}
