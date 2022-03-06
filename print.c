/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:43:04 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/06 14:25:39 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	long	t1;

	t1 = current_time() - time;
	if (t1 <= 9999)
		printf("┃        %.4ld        ┃       %d       ┃    %s     ┃\n",
			t1, philo_id, action);
	else if (t1 <= 99999)
		printf("┃        %.4ld       ┃       %d       ┃    %s     ┃\n",
			t1, philo_id, action);
	else if (t1 <= 999999)
		printf("┃       %.4ld       ┃       %d       ┃    %s     ┃\n",
			t1, philo_id, action);
	if (x == 0)
		print_footer();
}
