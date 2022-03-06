/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:01:57 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/06 13:57:01 by ael-hadd         ###   ########.fr       */
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

typedef struct s_philo
{
	int				philo_id;
	int				*state;
	int				*num_of_mfks;
	long			start;
	long			reset;
	t_time			times;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
}	t_philo;

typedef struct s_philosophers
{
	pthread_t		*thread;
	t_philo			*ph;
	int				state;
	pthread_mutex_t	*forks;
	int				num_of_philo;
	pthread_mutex_t	print;
	t_time			time;
}	t_philosophers;

long	current_time(void);
void	*routine(void *philo_arg);

int		ft_atoi(const char *nptr);
void	print_header(void);
void	print_log(long time, int philo_id, char *action, int x);

int		ft_error(char	*msg);
int		arg_checker(t_philosophers *philosophers);
int		usage(void);

int		end_threading(t_philosophers philosophers);
int		ft_free(t_philosophers philosophers);

#endif