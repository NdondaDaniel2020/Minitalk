/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:32:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 13:10:33 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	receive(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Recebida\n");
	exit(0);
}

void	send_sms(pid_t pid, char *sms)
{
	char	bits;
	int		n;
	int		ok;

	ok = 1;
	while (*sms || ok == 1)
	{
		n = 8;
		while (n--)
		{
			bits = ((*sms >> n) & 1);
			if (bits == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
		}
		if (*sms == '\0')
			break ;
		++sms;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac == 3)
	{
		sa.sa_handler = receive;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_sms(ft_atoi(av[1]), ft_strjoin(av[2], "\n"));
		while (1)
			pause();
	}
	else
		ft_printf("FALHA NOS ARGUMENTOD PASSADOS\n");
	return (0);
}
