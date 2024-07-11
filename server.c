/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/11 10:21:12 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int sig)
{
	static int	i = 0;
	static char	cha = 0;

	cha <<= 1;
	cha |= (sig == SIGUSR2);
	i++;
	if (i == 8)
	{
		ft_printf("%c", cha);
		i = 0;
		cha = 0;
	}
}

int	main(void)
{
	ft_printf("PID do processo: %d\n", getpid());
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	while (1)
		pause();
	return (0);
}
