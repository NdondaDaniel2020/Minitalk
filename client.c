/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:32:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/10 15:31:31 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sms(pid_t pid, char *sms)
{
	char	bits;
	int		n;

	while (*sms)
	{
		n = 32;
		while (n--)
		{
			bits = ((*sms >> n) & 1);
			if (bits == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
		}
		++sms;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		send_sms(ft_atoi(av[1]), ft_strjoin(av[2], "\n"));
	}
	else
		ft_printf("FALHA NOS ARGUMENTOD PASSADOS\n");
	return (0);
}
