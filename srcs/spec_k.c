/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_k.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:20:54 by soyster           #+#    #+#             */
/*   Updated: 2020/02/28 23:35:56 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
#include <time.h>

void	ft_spec_k(va_list all_arg, t_flag *all_mod)
{
	time_t t = time(NULL);
 // struct tm tm = *localtime(&t);
 // ft_printf("now: %d-%02d-%02d %02d:%02d:%02d\n", 
 // tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
      ft_printf("local:     %s", asctime(localtime(&t)));

  
}