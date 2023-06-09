/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:23:37 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/05/31 12:16:03 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_to_server(int pid, char c)
{
	int	bit;

	bit = 0;
	if (c >= 0)
	{
		while (bit < 8)
		{
			if ((c & (1 << bit)) == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(250);
			bit++;
		}
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	i = 0;
	if (ac != 3)
		ft_printf("Error!\nYou need a process ID and a message as inputs\n");
	else
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			message_to_server(pid, av[2][i]);
			i++;
		}
		message_to_server(pid, '\n');
	}
}
