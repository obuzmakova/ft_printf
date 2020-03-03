/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:54:26 by soyster           #+#    #+#             */
/*   Updated: 2020/03/03 12:56:55 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_color_check(t_flag *all_mod)
{
	int	res;

	res = all_mod->res;
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{black}", 7))
		return(1);
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{red}", 5))
		return(1);
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{green}", 7))
		return(1);
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{yellow}", 8))
		return(1);
	if (ft_color_check_2(all_mod))
		return(1);
	return (0);
}

int		ft_color_check_2(t_flag *all_mod)
{
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{darkblue}", 10))
		return(1);
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{purple}", 8))
		return(1);
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{blue}", 6))
		return(1);
	if (!ft_strncmp_st(all_mod->format, all_mod->i, "{white}", 7))
		return(1);
	return(0);
}
