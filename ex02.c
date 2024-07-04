/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex02.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:00:00 by usuario           #+#    #+#             */
/*   Updated: 2024/07/04 09:33:25 by nmatondo         ###   ########.fr       */
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

	// Inicializando a estrutura sigaction
	sa.sa_handler = sigint_handler;
	sa.sa_flags = SA_RESTART; // Reiniciar chamadas de sistema interrompidas
	sigemptyset(&sa.sa_mask); // Limpar a máscara de sinal

	// Registrando o manipulador de sinal usando sigaction
	sigaction(SIGINT, &sa, NULL);

	// Obtendo o PID do processo
	pid_t pid;
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
