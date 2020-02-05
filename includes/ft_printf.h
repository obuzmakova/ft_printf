/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/02/05 17:59:58 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"

//#define ALL_FLAGS #0-+ 

typedef struct	s_flar
{
	const char	*format; //строка формата

	int			i; //index для строки формата
	int			result; //кол-во напечатанных символов
	
	char		flag_sh; //#
	char		flag_0;  //0=N видит 0 только если он сразу после %
	char		flag_min; //-
	char		flag_pl;  //+
	char		flag_sp;  //space = S
	
	int			width; // ширина
	int			precision; //точность
	int			length; //длина 1 - h, 2 - hh, 3 - l, 4 - ll, 5 - L
	
	char		specifier; //спецификатор
}				t_flag;

int		ft_spec_x(t_flag *all_mod, char *pointer);
int	ft_spec_p(t_flag *all_mod, char *pointer);
void	ft_percent(t_flag *all_mod);
int		ft_simple_width(int simple_width, int result);
int		ft_width(t_flag *all_mod, int len);
void	ft_putstr_len(char const *str, size_t len_prec);
int		ft_spec_s(va_list all_arg, t_flag *all_mod);
int		ft_spec_c(va_list all_arg, t_flag *all_mod);
t_flag	*ft_free_allmod(t_flag *all_mod);
int		ft_length(va_list all_arg, t_flag *all_mod);
int		ft_spec(va_list all_arg, t_flag *all_mod);
int		ft_flags(va_list all_arg, t_flag *all_mod);
int		ft_wid_and_prec(va_list all_arg, t_flag *all_mod);
int		ft_printf(const char *format, ...);
int		ft_findfunction(va_list all_arg, t_flag *all_mod);
int		*ft_itoa_base(va_list all_arg, t_flag *all_mod, int base);
size_t	count_for_malloc(long long nbr, int base);

#endif
