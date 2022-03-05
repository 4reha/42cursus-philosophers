/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:01:12 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/05 12:55:29 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*death_caller(void *arg)
{
	t_philo	*ph;
	int		i;

	ph = arg;
	
	while (1)
	{
		i = -1;
		while (++i < *ph[0].num_of_mfks)
		{
			if (current_time() - ph[i].reset > ph[i].times.to_die)
			{
				*ph[i].state = DEAD;
				pthread_mutex_lock(ph[i].print);
				printf("in %ld philo %d just died\n",
					current_time() - ph[i].start, ph[i].philo_id);
				if (*ph[i].num_of_mfks == 1)
					pthread_mutex_unlock(ph[i].l_fork);
				return (NULL);
			}
		}
	}
}

int	threading_part2(t_philosophers *philosophers, int i, pthread_t	*thread)
{
	int	i;

	i = -1;
	while (++i < philosophers->num_of_philo)
	{
		philosophers->ph[i].times = philosophers->time;
		philosophers->ph[i].philo_id = i + 1;
		philosophers->ph[i].l_fork = &philosophers->forks[i].fork;
		philosophers->ph[i].r_fork = &philosophers->forks[(i + 1)
			% philosophers->num_of_philo].fork;
		philosophers->state = ALIVE;
		philosophers->ph[i].start = current_time();
		philosophers->ph[i].reset = philosophers->ph[i].start;
		philosophers->ph[i].state = &philosophers->state;
		philosophers->ph[i].print = &philosophers->print;
		philosophers->ph[i].num_of_mfks = &philosophers->num_of_philo;
		if (!pthread_create(&thread[i], NULL, &routine,
				(void *)(&philosophers->ph[i])))
			return (0);
	}
	return (1);
}

int	threading(t_philosophers *philosophers)
{
	int			i;
	pthread_t	*thread;
	pthread_t	death;

	i = -1;
	thread = (philosophers->num_of_philo * sizeof(pthread_t));
	philosophers->forks = malloc
		(philosophers->num_of_philo * sizeof(pthread_mutex_t));
	if (!thread || !philosophers->forks)
		return (0);
	while (++i < philosophers->num_of_philo)
		pthread_mutex_init(&philosophers->forks[i].fork, NULL);
	threading_part2(philosophers, i, thread);
	if (!pthread_create(&death, NULL, death_caller, (void *)philosophers->ph))
		return (0);
	i = -1;
	while (++i < philosophers->num_of_philo)
		pthread_join(thread[i], NULL);
	return (1);
}

int	arg_init(int ac, char **av, t_philosophers *philosophers)
{
	int	i;

	i = 1;
	philosophers->num_of_philo = ft_atoi(av[1]);
	philosophers->ph = malloc(philosophers->num_of_philo * sizeof(t_philo));
	if (!philosophers->ph)
		return (0);
	philosophers->time.to_die = ft_atoi(av[2]);
	philosophers->time.to_eat = ft_atoi(av[3]);
	philosophers->time.to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philosophers->time.s_eat = ft_atoi(av[5]);
	else
		philosophers->time.s_eat = -1;
	if (philosophers->time.to_die <= 0 || philosophers->time.to_eat <= 0
		|| philosophers->time.to_sleep <= 0
		|| philosophers->time.to_die < philosophers->time.to_eat)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_philosophers	philosophers;

	if (ac == 5 || ac == 6)
	{
		if (!arg_init(ac, av, &philosophers))
			return (0);
		if (!threading(&philosophers))
			return (0);
	}
	return (0);
}
