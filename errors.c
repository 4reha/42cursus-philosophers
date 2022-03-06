/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:16:27 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/06 14:43:29 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(char	*msg)
{
	printf("Error: %s\n", msg);
	return (1);
}

int	usage(void)
{
	printf("╭--------------------------------------------------------------╮\n");
	printf("| Usage error: you have to run ./philo with these parameters:  |\n");
	printf("| [1]- Number of philosophers                                  |\n");
	printf("| [2]- Time to die (in ms)                                     |\n");
	printf("| [3]- Time to eat (in ms)                                     |\n");
	printf("| [4]- Time to sleep (in ms)                                   |\n");
	printf("| [5]- Number of meals (optinal)                               |\n");
	printf("| [E.g] ./philo 3 1000 300 400 3                               |\n");
	printf("╰--------------------------------------------------------------╯\n");
	return (1);
}

int	arg_checker(t_philosophers *philosophers)
{
	if (philosophers->time.to_die <= 0 || philosophers->time.to_eat <= 0
		|| philosophers->time.to_sleep <= 0)
		return (ft_error("Arguments cannot be zero or negative!"));
	return (0);
}
