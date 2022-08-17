/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:18:37 by kiijima           #+#    #+#             */
/*   Updated: 2022/08/17 18:58:28 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_signal;

void	put_pid(void)
{
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	put_character(int signal)
{
	if (signal == SIGUSR1)
		g_signal.character += (0b00000001 << g_signal.count);
	if (g_signal.count == 8)
	{
		ft_putchar_fd(g_signal.character, STDOUT_FILENO);
		g_signal.character = 0;
		g_signal.count = 0;
		return ;
	}
	g_signal.count++;
}

int	main(void)
{
	g_signal.character = 0;
	g_signal.count = 0;
	put_pid();
	signal(SIGUSR1, put_character);
	signal(SIGUSR2, put_character);
	while(1)
		pause();
}
