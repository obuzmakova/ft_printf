/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 21:03:03 by soyster           #+#    #+#             */
/*   Updated: 2020/02/27 23:08:52 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	all_arg;
	int		result;

	if (*format == '\0')
		return (0);
	va_start(all_arg, format);
	result = ft_gen_parser(all_arg, (char*)format);
	va_end(all_arg);
	// while (1) ;
	return (result);
}