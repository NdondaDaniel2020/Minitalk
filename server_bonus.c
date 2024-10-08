/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 13:06:35 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	cha = 0;

	(void)context;
	cha <<= 1;
	cha |= (sig == SIGUSR2);
	i++;
	if (i == 8)
	{
		ft_printf("%c", cha);
		if (cha == '\0')
			kill(info->si_pid, SIGUSR1);
		i = 0;
		cha = 0;
	}
}

int	main(void)
{
	struct sigaction	sa_usr;

	ft_printf("PID: %d\n", getpid());
	sa_usr.sa_sigaction = sigusr_handler;
	sa_usr.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_usr.sa_mask);
	sigaction(SIGUSR1, &sa_usr, NULL);
	sigaction(SIGUSR2, &sa_usr, NULL);
	while (1)
		pause();
	return (0);
}
