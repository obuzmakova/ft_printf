/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <soyster@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:18:14 by soyster           #+#    #+#             */
/*   Updated: 2020/03/03 20:26:44 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef	struct	s_flag
{
	char		*format;
	int			i;
	int			res;
	char		f_sh;
	char		f_0;
	char		f_min;
	char		f_pl;
	char		f_sp;
	int			width;
	int			check_prec;
	int			prc;
	int			len;
	char		spc;
}				t_flag;

typedef struct	s_float
{
	long double	f;
	long		n_st;
	long double	n_ed;
	int			*frt;
	int			i;
	int			k;
	int			ch_s;
	int			len_wh;
}				t_float;

typedef struct	s_np
{
	char	*src;
	int		i;
}				t_np;

void			ft_helper_ll(t_flag *all_mod, int len);
void			ft_digit2_part2(t_flag *all_mod, int len);
void			ft_helper_sign(t_flag *all_mod, char *sign, int len);
int				ft_color_check_2(t_flag *all_mod);
int				ft_color_check(t_flag *all_mod);
void			ft_helper_id(t_flag *all_mod);
__int128_t		ft_helper(__int128_t num, int base);
void			check_zero(t_flag *all_mod, char *sign, int len);
int				ft_check(t_flag *all_mod, long long nbr);
void			ft_put_dec(t_flag *all_mod, __int128_t num, int base);
void			ft_llu(t_flag *all_mod, unsigned long long num, int base,
		int len);
int				count_for_len_llu(unsigned long long nbr, int base);
void			ft_putstr_res(char *src, int res, t_flag *all_mod);
void			ft_np_2(t_np *np, t_flag *all_mod);
void			ft_np_1(t_np *np, t_flag *all_mod);
void			ft_spec_r(va_list all_arg, t_flag *all_mod);
void			ft_space(t_flag *all_mod, char *sign, int len);
void			ft_zero(t_flag *all_mod);
int				base_put(t_flag *all_mod, long long num, int base);
int				ft_sharp(t_flag *all_mod, int len);
void			to_spec_id(t_flag *all_mod, int len);
void			ft_negative(t_flag *all_mod, char *sign, int len);
void			to_spec_plus(t_flag *all_mod, int len);
void			ft_doublesign(t_flag *all_mod, char *sign, int len);
void			ft_doublesignend(t_flag *all_mod, char *sign, int len);
void			ft_digit(t_flag *all_mod, char *sign, long long num, int len);
void			ft_spec_k(va_list all_arg, t_flag *all_mod);
void			ft_color_2(t_flag *all_mod);
void			ft_eoc(t_flag *all_mod);
void			ft_color(t_flag *all_mod);
int				ft_strncmp_st(const char *s1, int k, const char *s2, int n);
int				ft_gen_parser(va_list all_arg, char *format);
int				ft_c(int prc, char s);
int				ft_wid_prec(t_flag *all_mod);
void			ft_sign_dig(t_flag *all_mod, char *sign, int len);
void			ft_putlongnbr(long n, t_flag *all_mod);
void			ft_print_fl(t_float *fl, t_flag *all_mod);
int				ft_act_width(t_float *fl, t_flag *all_mod);
int				ft_len_whole(long num_start);
void			ft_print_sp(t_float *fl, t_flag *all_mod);
void			ft_print_fl_min(t_float *fl, t_flag *all_mod);
void			ft_check_s(t_float *fl, t_flag *all_mod);
void			ft_fill_frt(t_float *fl, t_flag *all_mod);
void			ft_separ_fl(t_float *fl, t_flag *all_mod);
int				ft_float_1(long double f, int prc);
void			ft_fill_fl(t_float *fl);
int				ft_rounding(t_float *fl);
void			ft_spec_f(va_list all_arg, t_flag *all_mod);
void			ft_spec_x(t_flag *all_mod, int len);
int				ft_wx(int len, char c);
int				ft_sharp(t_flag *all_mod, int len);
void			ft_num(t_flag *all_mod, unsigned long long num, int base,
		int len);
int				ft_spec_x_add(t_flag *all_mod, int len);
void			ft_percent(t_flag *all_mod);
int				ft_simple_width(int simple_width, t_flag *all_mod);
int				base_put(t_flag *all_mod, long long num, int base);
void			ft_putstr_len(char const *str, size_t len_prec,
		t_flag *all_mod);
int				ft_spec_s(va_list all_arg, t_flag *all_mod);
int				ft_spec_c(va_list all_arg, t_flag *all_mod);
int				ft_width(t_flag *all_mod, int len);
void			ft_free_allmod(t_flag *all_mod);
int				ft_spec_p(t_flag *all_mod, long long num, int len);
int				ft_length(t_flag *all_mod);
int				ft_spec(t_flag *all_mod);
int				ft_flags(t_flag *all_mod);
int				ft_wid_and_prec(va_list all_arg, t_flag *all_mod);
int				ft_printf(const char *format, ...);
void			ft_x(t_flag *all_mod, unsigned long long num, int base,
		int len);
size_t			ft_function(va_list all_arg, t_flag *all_mod);
int				ft_gen_parser(va_list all_arg, char *format);

#endif
