/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhashan <mkhashan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:42:06 by mkhashan          #+#    #+#             */
/*   Updated: 2026/02/05 08:42:06 by mkhashan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printfloat(double nbr)
{
	int	res;
	int	true_nbr;

	true_nbr = 100 * (int)nbr;
	res = (int)(nbr * 100);
	res = res - true_nbr;
	ft_printnbr(true_nbr);
	write(2,".",1);
	ft_printnbr(res);
	return (1);
}
