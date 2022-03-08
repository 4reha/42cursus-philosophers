/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:01:12 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/08 10:39:57 by ael-hadd         ###   ########.fr       */
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
		while (++i < ph[0].num_of_mfks)
		{
			if (current_time() - ph[i].reset > ph[i].times.to_die)
			{
				*ph[i].state = DEAD;
				print_log(ph[i].start, ph[i].philo_id, "just died", 0);
				if (ph[i].num_of_mfks == 1)
					pthread_mutex_unlock(ph[i].l_fork);
				return (NULL);
			}
		}
		if (*ph[0].mfks_count != ph[0].num_of_mfks)
			return (NULL);
	}
	return (NULL);
}

int	threading_part2(t_philosophers *philosophers)
{
	int	i;

	i = -1;
	while (++i < philosophers->num_of_philo)
	{
		philosophers->ph[i].times = philosophers->time;
		philosophers->ph[i].philo_id = i + 1;
		philosophers->ph[i].l_fork = &philosophers->forks[i];
		philosophers->ph[i].r_fork = &philosophers->forks[(i + 1)
			% philosophers->num_of_philo];
		philosophers->state = ALIVE;
		philosophers->ph[i].start = current_time();
		philosophers->ph[i].reset = philosophers->ph[i].start;
		philosophers->ph[i].state = &philosophers->state;
		philosophers->ph[i].num_of_mfks = philosophers->num_of_philo;
		philosophers->ph[i].mfks_count = &philosophers->num_of_philo;
		if (pthread_create(&philosophers->thread[i], NULL, &routine,
				(void *)(&philosophers->ph[i])))
			return (1);
	}
	return (0);
}

int	threading(t_philosophers *philosophers)
{
	int			i;
	pthread_t	death;

	i = -1;
	print_header();
	philosophers->thread = malloc
		(philosophers->num_of_philo * sizeof(pthread_t));
	philosophers->forks = malloc
		(philosophers->num_of_philo * sizeof(pthread_mutex_t));
	if (!philosophers->thread || !philosophers->forks)
		return (1);
	while (++i < philosophers->num_of_philo)
		pthread_mutex_init(&philosophers->forks[i], NULL);
	if (threading_part2(philosophers))
		return (ft_error("Cannot create philo thread!"));
	if (pthread_create(&death, NULL, death_caller, (void *)philosophers->ph))
		return (ft_error("Cannot create death thread!"));
	if (pthread_join(death, NULL))
		return (ft_error("Cannot join death thread!"));
	i = -1;
	while (++i < philosophers->num_of_philo)
		if (pthread_join(philosophers->thread[i], NULL))
			return (ft_error("Cannot join philo thread!"));
	return (0);
}

int	arg_init(int ac, char **av, t_philosophers *philosophers)
{
	int	i;

	i = 1;
	philosophers->num_of_philo = ft_atoi(av[1]);
	philosophers->ph = malloc(philosophers->num_of_philo * sizeof(t_philo));
	if (!philosophers->ph)
		return (1);
	philosophers->time.to_die = ft_atoi(av[2]);
	philosophers->time.to_eat = ft_atoi(av[3]);
	philosophers->time.to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philosophers->time.s_eat = ft_atoi(av[5]);
	else
		philosophers->time.s_eat = -1;
	arg_checker(philosophers);
	return (0);
}

int	main(int ac, char **av)
{
	t_philosophers	philosophers;

	if (ac == 5 || ac == 6)
	{
		if (arg_init(ac, av, &philosophers))
			return (1);
		if (threading(&philosophers))
			return (1);
		end_threading(philosophers);
		ft_free(philosophers);
	}
	else
		usage();
	return (0);
}
