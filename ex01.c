/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:58:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/03 15:21:13 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Manipulador para SIGINT
void	sigint_handler(int sig)
{
	printf("Recebi o sinal SIGINT (Ctrl+C). Código do sinal: %d\n", sig);
}

// Manipulador para SIGTERM
void	sigterm_handler(int sig)
{
	printf("Recebi o sinal SIGTERM. Código do sinal: %d\n", sig);
}

// Manipulador para SIGUSR1
void	sigusr1_handler(int sig)
{
	printf("Recebi o sinal SIGUSR1. Código do sinal: %d\n", sig);
}

// Manipulador para SIGUSR2
void	sigusr2_handler(int sig)
{
	printf("Recebi o sinal SIGUSR2. Código do sinal: %d\n", sig);
}

int	main(void)
{
	// Obtendo o PID do processo
	pid_t pid;

	pid = getpid();
	printf("PID do processo: %d\n", pid);

	// Registrando os manipuladores de sinal
	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigterm_handler);
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);

	// Loop infinito para manter o programa rodando
	while (1)
	{
		printf("Executando... Pressione Ctrl+C para interromper ou envie outros sinais.\n");
		sleep(1);
	}
	return (0);
}