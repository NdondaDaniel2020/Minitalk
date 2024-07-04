/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:09:01 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/04 11:43:09 by nmatondo         ###   ########.fr       */
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

int	main(void)
{
	struct sigaction sa;
	pid_t pid;

	// Inicializando a estrutura sigaction para SIGINT
	sa.sa_handler = sigint_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	// Adicionando SIGINT e SIGTERM ao conjunto de sinais a serem bloqueados
	if (sigaddset(&sa.sa_mask, SIGINT) == -1)
	{
		perror("Erro ao adicionar SIGINT ao conjunto de sinais");
		return (1);
	}
	if (sigaddset(&sa.sa_mask, SIGTERM) == -1)
	{
		perror("Erro ao adicionar SIGTERM ao conjunto de sinais");
		return (1);
	}

	// Registrando o manipulador de sinal usando sigaction
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("Erro ao registrar manipulador de sinal");
		return (1);
	}

	// Obtendo o PID do processo
	pid = getpid();
	printf("PID do processo: %d\n", pid);

	// Loop infinito para manter o programa rodando
	while (1)
	{
		printf("Executando... Pressione Ctrl+C para testar SIGINT.\n");
		sleep(1);
	}
	return (0);
}
