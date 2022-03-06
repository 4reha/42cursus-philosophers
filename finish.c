/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:47:25 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/06 12:52:17 by ael-hadd         ###   ########.fr       */
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
	while (++i < philosophers.num_of_philo)
	{
		pthread_mutex_unlock(&philosophers.forks[i]);
		pthread_mutex_destroy(&philosophers.forks[i]);
	}
	pthread_mutex_unlock(&philosophers.print);
	pthread_mutex_destroy(&philosophers.print);
	return (0);
}
