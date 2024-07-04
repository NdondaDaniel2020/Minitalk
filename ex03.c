/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:55:17 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/04 09:55:19 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Manipulador para SIGALRM
void	sigalrm_handler(int sig)
{
	printf("Recebi o sinal SIGALRM. Código do sinal: %d\n", sig);
}

int	main(void)
{
	struct sigaction sa;
	pid_t pid;

	// Inicializando a estrutura sigaction para SIGALRM
	sa.sa_handler = sigalrm_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	// Registrando o manipulador de sinal usando sigaction
	sigaction(SIGALRM, &sa, NULL);

	// Obtendo o PID do processo
	pid = getpid();
	printf("PID do processo: %d\n", pid);

	// Enviando SIGALRM para o próprio processo após 5 segundos
	printf("Enviando SIGALRM para o próprio processo após 5 segundos...\n");
	sleep(5);
	kill(pid, SIGALRM);

	// Loop infinito para manter o programa rodando
	while (1)
	{
		printf("Executando... Pressione Ctrl+C para sair.\n");
		sleep(1);
	}
	return (0);
}
