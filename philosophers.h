/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:01:57 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/05 12:55:29 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define DEAD 0
# define ALIVE 1

# define LOCKED 0
# define UNLOCKED 1

typedef struct s_time
{
	int				to_eat;
	int				to_sleep;
	int				to_think;
	int				to_die;
	int				s_eat;
}	t_time;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				state;
}	t_fork;

typedef struct s_philo
{
	int				philo_id;
	int				*state;
	int				*num_of_mfks;
	long			start;
	long			end;
	long			reset;
	t_time			times;
	pthread_mutex_t	*l_fork;
	int				*l_fork_state;
	pthread_mutex_t	*r_fork;
	int				*r_fork_state;
	pthread_mutex_t	*print;
}	t_philo;

typedef struct s_philosophers
{
	t_philo			*ph;
	int				state;
	t_fork			*forks;
	int				num_of_philo;
	pthread_mutex_t	print;
	t_time			time;
}	t_philosophers;

int		ft_atoi(const char *nptr);
void	*routine(void *philo_arg);
long	current_time(void);
void	ft_putstr(char *str);
void	ft_putnbr(long long nn);

#endif