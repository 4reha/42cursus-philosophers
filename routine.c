/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:55:01 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/07 14:51:46 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	takes_fork(t_philo	*philo, int *stop)
{
	if (philo->philo_id % 2 == 1 && *stop == 0)
	{
		*stop += 1;
		ft_usleep(philo->times.to_eat);
	}
	pthread_mutex_lock(philo->l_fork);
	if (*philo->state == ALIVE)
		print_log(philo->start, philo->philo_id, "has taken a fork", 1);
	pthread_mutex_lock(philo->r_fork);
	if (*philo->state == ALIVE)
		print_log(philo->start, philo->philo_id, "has taken a fork", 1);
}

void	thinking(t_philo	*philo)
{
	if (*philo->state == ALIVE)
		print_log(philo->start, philo->philo_id, "is thinking", 1);
}

void	sleeping(t_philo	*philo)
{
	if (*philo->state == ALIVE)
		print_log(philo->start, philo->philo_id, "is sleeping", 1);
	if (*philo->state == ALIVE)
		ft_usleep(philo->times.to_sleep);
}

void	eating(t_philo	*philo)
{
	int	i;

	i = 1;
	if (*philo->state == ALIVE)
	{
		philo->times.s_eat--;
		if (philo->times.s_eat == 0)
		{
			*philo->mfks_count -= 1;
			if (*philo->mfks_count == 0)
				i = 0;
		}
		print_log(philo->start, philo->philo_id, "is eating", i);
		philo->reset = current_time();
		ft_usleep(philo->times.to_eat);
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *philo_arg)
{
	int		stop;
	t_philo	*philo;

	philo = philo_arg;
	stop = 0;
	while (1)
	{
		if (*philo->state == DEAD)
			break ;
		takes_fork(philo, &stop);
		eating(philo);
		if (philo->times.s_eat == 0)
			break ;
		if (*philo->state == DEAD)
			break ;
		sleeping(philo);
		if (*philo->state == DEAD)
			break ;
		thinking(philo);
		if (*philo->state == DEAD)
			break ;
	}
	return (NULL);
}
