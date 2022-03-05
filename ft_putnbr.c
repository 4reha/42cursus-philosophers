/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aourhzal <aourhzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:24:12 by aourhzal          #+#    #+#             */
/*   Updated: 2022/03/04 18:14:27 by aourhzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putnbr(long long nn)
{
	int	c;

	c = 0;
	if (nn >= 10)
	{
		ft_putnbr(nn / 10);
		ft_putnbr(nn % 10);
	}
	else
	{
		c = nn + 48;
		write(1, &c, 1);
	}
}
