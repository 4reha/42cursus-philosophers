/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:47:25 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/08 10:40:21 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_free(t_philosophers philosophers)
{
	free(philosophers.ph);
	free(philosophers.thread);
	free(philosophers.forks);
	return (0);
}

int	end_threading(t_philosophers philosophers)
{
	int	i;

	i = -1;
	while (++i < philosophers.ph[0].num_of_mfks)
	{
		pthread_mutex_unlock(&philosophers.forks[i]);
		pthread_mutex_destroy(&philosophers.forks[i]);
	}
	return (0);
}
