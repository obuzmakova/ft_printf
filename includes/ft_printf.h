/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/02/25 17:12:58 by mleticia         ###   ########.fr       */
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
	const char	*format; //строка формата format

	int			i; //index для строки формата
	int			res; //кол-во напечатанных символов

	char		f_sh; //#
	char		f_0;  //0=N видит 0 только если он сразу после %
	char		f_min; //-
	char		flag_pl;  //+
	char		flag_sp;  //space = S

	int			width; // ширина
	int			prc; //точность precision
	int			length; //длина 1 - h, 2 - hh, 3 - l, 4 - ll, 5 - L
	char		spc; //спецификатор specifier
	long double	f; // храниться флот
	int			*fractional; //дробная часть флота
	int			index; //индекс для дробной части флота
}				t_flag;

typedef union			u_double //убрать
{
	long double			ld;
	struct
	{
		unsigned long int	mant : 64;
		unsigned int		expon : 15;
		unsigned int		sign : 1;
	}					s_parts;
}						t_double;

typedef struct			s_mant_list //убрать
{
	unsigned long		base_list;
	struct s_mant_list	*next;
}						t_mant_list;

int		ft_rounding(t_flag *all_mod);
void	ft_spec_f(va_list all_arg, t_flag *all_mod);
int	ft_spec_x(t_flag *all_mod, int len);
int	ft_wx(int len, char c);
int ft_sharp(t_flag *all_mod, int len);
void	ft_putnum(t_flag *all_mod, long long num, int base, int len);
int	ft_spec_x_add(t_flag *all_mod, int len);
//int		ft_spec_p(t_flag *all_mod, char *pointer);
void	ft_percent(t_flag *all_mod);
int		ft_simple_width(int simple_width, int result);
int base_put(t_flag *all_mod, long long num, int base);
void	ft_putstr_len(char const *str, size_t len_prec);
int		ft_spec_s(va_list all_arg, t_flag *all_mod);
int		ft_spec_c(va_list all_arg, t_flag *all_mod);
int	ft_width(t_flag *all_mod, int len);
t_flag	*ft_free_allmod(t_flag *all_mod);
int ft_spec_p(t_flag *all_mod, long long num, int base, int len);
void		ft_put_dec(t_flag *all_mod, long long num, int base);
int		ft_length(va_list all_arg, t_flag *all_mod);
int		ft_spec(va_list all_arg, t_flag *all_mod);
int		ft_flags(va_list all_arg, t_flag *all_mod);
int		ft_wid_and_prec(va_list all_arg, t_flag *all_mod);
int		ft_printf(const char *format, ...);
void ft_findout(t_flag *all_mod, long long num, int base, int len);
size_t ft_findfunction(va_list all_arg, t_flag *all_mod);
int   *ft_itoa_base(va_list all_arg, t_flag *all_mod, int base);
size_t	count_for_malloc(long long nbr, int base);

#endif
