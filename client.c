/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiijima <kiijima@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:17:30 by kiijima           #+#    #+#             */
/*   Updated: 2022/07/26 17:59:29 by kiijima          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_msg(char *str)
{
	ft_putstr_fd(str, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	send_msg(int pid, char *msg)
{
	int		kill_status;
	int		i;
	int		shift_count;

	i = 0;
	while (msg[i] != '\0')
	{
		shift_count = 0;
		while (shift_count < 8)
		{
			if (msg[i] >> shift_count & 0b00000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			if (kill_status == -1)
				error_msg("kill error");
			shift_count++;
			usleep(150);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		error_msg("invalid argument\n");
	pid = ft_atoi(argv[1]);
	send_msg(pid, argv[2]);
}
