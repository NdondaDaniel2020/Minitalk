# Minitalk - Projeto da 42

O **Minitalk** é um projeto de comunicação entre processos (IPC) desenvolvido como parte do currículo da Escola 42. O objetivo principal é criar uma infraestrutura de comunicação baseada em cliente-servidor utilizando apenas **Sinais UNIX** (`SIGUSR1` e `SIGUSR2`).

---

## 🛠️ Funcionamento do Projeto

A comunicação é baseada na transmissão de dados bit a bit. O cliente envia uma mensagem de texto (caractere por caractere) convertendo cada byte em uma sequência de 8 bits:
- **Bit 0** é representado pelo sinal `SIGUSR1`.
- **Bit 1** é representado pelo sinal `SIGUSR2`.

O servidor recebe estes sinais um a um, reconstrói o byte correspondente (deslocando os bits recebidos) e imprime o caractere correspondente assim que completa os 8 bits.

### 🌟 Funcionalidades Bônus
Na versão bônus, é implementada uma confirmação de recebimento (Handshake):
1. O cliente transmite os caracteres da string incluindo o caractere nulo (`\0`) no final para indicar o término da transmissão.
2. O servidor envia de volta um sinal de confirmação (`SIGUSR1`) para o PID do cliente que enviou os dados (obtido via `siginfo_t` na função tratadora).
3. O cliente, ao receber a confirmação, exibe na tela `"Recebida"` e encerra sua execução com sucesso.

---

## 📁 Estrutura de Arquivos

* [client.c](file:///spot/NdDaniel/Code/42/Minitalk/client.c) / [client_bonus.c](file:///spot/NdDaniel/Code/42/Minitalk/client_bonus.c) - Código-fonte do programa cliente.
* [server.c](file:///spot/NdDaniel/Code/42/Minitalk/server.c) / [server_bonus.c](file:///spot/NdDaniel/Code/42/Minitalk/server_bonus.c) - Código-fonte do programa servidor.
* [minitalk.h](file:///spot/NdDaniel/Code/42/Minitalk/minitalk.h) / [minitalk_bonus.h](file:///spot/NdDaniel/Code/42/Minitalk/minitalk_bonus.h) - Cabeçalhos do projeto.
* [libft/](file:///spot/NdDaniel/Code/42/Minitalk/libft) - Biblioteca utilitária contendo implementações básicas (como `ft_printf`, `ft_atoi`, `ft_strjoin`).
* [Makefile](file:///spot/NdDaniel/Code/42/Minitalk/Makefile) - Arquivo de automação de compilação.

---

## ⚙️ Instruções de Compilação

O `Makefile` incluído no projeto disponibiliza os seguintes comandos:

| Comando | Descrição |
| :--- | :--- |
| `make m` | Compila o cliente e o servidor na versão padrão (obrigatória). |
| `make b` | Compila o cliente e o servidor na versão bônus. |
| `make clean` | Remove os arquivos temporários de compilação (`.o`). |
| `make fclean` | Remove os arquivos temporários e o executável do servidor. |
| `make eclean` | Executa uma limpeza completa, apagando todos os executáveis e a biblioteca estática compilada (`minitalk.a`). |
| `make re` | Recompila a biblioteca estática. |
| `make n` | Executa a verificação de estilo do código usando a `norminette`. |

---

## 🚀 Como Executar

### 1. Iniciar o Servidor
Primeiro, compile os binários com a versão desejada (ex: obrigatória com `make m` ou bônus com `make b`).
Depois, execute o servidor:
```bash
./server
```
O servidor será iniciado e exibirá o seu **PID** (Process ID) no terminal, por exemplo:
```text
PID do processo: 12345
```
Ele ficará aguardando por sinais continuamente.

### 2. Enviar Mensagem do Cliente
Em outro terminal (ou outra sessão), execute o programa cliente informando o **PID** do servidor e a mensagem que deseja transmitir:
```bash
./client <PID_DO_SERVIDOR> "Sua mensagem aqui"
```
Exemplo:
```bash
./client 12345 "Ola Mundo!"
```

---

## 📜 Licença

Este projeto está sob a licença [MIT License](file:///spot/NdDaniel/Code/42/Minitalk/LICENSE).
