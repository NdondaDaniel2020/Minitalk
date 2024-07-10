/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/10 15:32:16 by nmatondo         ###   ########.fr       */
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

void	sigusr_handler(int sig)
{
	static int	i = 0;
	static char	bits[32];
	int			bit;

	bit = 0;
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	bits[i] = bit + '0';
	i++;
	if (i == 32)
	{
		i = 0;
		ft_printf("%c", bin_to_char(bits));
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
