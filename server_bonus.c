/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/06 07:24:55 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	bin_to_char(char *bits)
{
	char	c;
	int		i;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c = (c << 1) | (bits[i] - '0');
		i++;
	}
	return (c);
}

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	bits[8];
	int			bit;
	char		cha;

	bit = 0;
	(void)context;
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	bits[i] = bit + '0';
	i++;
	if (i == 8)
	{
		i = 0;
		cha = bin_to_char(bits);
		ft_printf("%c", cha);
		if (cha == '\n')
			kill(info->si_pid, SIGUSR1);
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
