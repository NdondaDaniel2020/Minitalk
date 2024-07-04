/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:37 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/04 15:42:06 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr1_handler(int sig, siginfo_t *info, void *context)
{
	(void)context; // contexto não utilizado
	printf("Processo filho: Recebi o sinal SIGUSR1. Código do sinal: %d\n", sig);
	printf("Processo filho: Sinal enviado pelo processo com PID: %d\n", info->si_pid);
}

int	main(void)
{
	struct sigaction sa_usr1;
	struct sigaction sa_usr2;
	pid_t pid;

	// Configurando manipuladores para SIGUSR1 com sa_sigaction
	sa_usr1.sa_sigaction = sigusr1_handler;
	sa_usr1.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_usr1.sa_mask);
	sigaction(SIGUSR1, &sa_usr1, NULL);

	// Configurando manipuladores para SIGUSR2 com sa_sigaction
	sa_usr2.sa_sigaction = sigusr1_handler;
	sa_usr2.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_usr2.sa_mask);
	sigaction(SIGUSR2, &sa_usr2, NULL);

	// Obtendo o PID do processo filho
	pid = getpid();
	printf("Processo filho iniciado. PID: %d\n", pid);

	// Loop infinito para manter o processo filho rodando
	while (1)
	{
		pause(); // Espera por sinais
	}
	return (0);
}