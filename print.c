/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:43:04 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/08 10:39:00 by ael-hadd         ###   ########.fr       */
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

void	ft_usleep(int ms)
{
	long	time;

	time = current_time();
	usleep(ms * 920);
	while (current_time() < time + ms)
		usleep(ms * 3);
}

void	print_footer(void)
{
	printf("┗━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void	print_header(void)
{
	printf("┏━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃        Time        ┃     Philo     ┃          Action         ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
}

void	print_log(long time, int philo_id, char *action, int x)
{
	long			t1;

	t1 = current_time() - time;
	printf("┃%-20.4ld┃%-15d┃%-25s┃\n", t1, philo_id, action);
	if (x == 0)
		print_footer();
}
