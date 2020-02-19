/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/02/19 20:59:59 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	//ft_printf("%-05.0f\n", 7.3); // иногда segfault
	//printf("%-05.0f", 7.3);
	ft_printf("% 5.0f\n", 7.3);
	printf("% 5.0f\n", 7.3);
	//ft_printf("%f\n", 0.000001); //иногда segfault
	//ft_printf("%f\n", 0.999999); //иногда segfault
	//ft_printf("%f\n", 43.43999949); //иногда segfault
	//ft_printf("%f\n", -985.765426499); //иногда segfault
	//printf("%f\n", -985.765426499); //иногда segfault
	return (0);
}