/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:55:01 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/05 12:55:29 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	current_time(void)
{
	struct timeval	time;
	long			total;

	gettimeofday(&time, NULL);
	total = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (total);
}

void	thinking(t_philo	*philo)
{
	philo->times.to_think = ((philo->times.to_die
				- (current_time() - philo->reset)) / 3) * 2;
	pthread_mutex_lock(philo->print);
	if (*philo->state == ALIVE)
		printf("in %.4ld philo %d is thinking\n",
			(current_time() - philo->start), philo->philo_id);
	pthread_mutex_unlock(philo->print);
	if (*philo->state == ALIVE)
		usleep(philo->times.to_think * 1000);
}

void	sleeping(t_philo	*philo)
{
	pthread_mutex_lock(philo->print);
	if (*philo->state == ALIVE)
		printf("in %.4ld philo %d is sleeping\n",
			(current_time() - philo->start), philo->philo_id);
	pthread_mutex_unlock(philo->print);
	if (*philo->state == ALIVE)
		usleep(philo->times.to_sleep * 1000);
}

void	eating(t_philo	*philo, int *stop)
{
	(void)stop;
	if (philo->philo_id % 2 == 1 && *stop == 0)
	{
		*stop += 1;
		usleep(philo->times.to_eat);
	}
	pthread_mutex_lock(philo->l_fork);
	if (*philo->state == ALIVE)
		printf("in %.4ld philo %d has taken a fork\n",
			(current_time() - philo->start), philo->philo_id);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->print);
	if (*philo->state == ALIVE)
		printf("in %.4ld philo %d is eating\n",
			(current_time() - philo->start), philo->philo_id);
	pthread_mutex_unlock(philo->print);
	philo->reset = current_time();
	if (*philo->state == ALIVE)
		usleep(philo->times.to_eat * 500);
	if (*philo->state == ALIVE)
		usleep(philo->times.to_eat * 500);
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
		if (*philo->state == DEAD || philo->times.s_eat == 0)
			break ;
		eating(philo, &stop);
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
