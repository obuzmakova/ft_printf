/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleticia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:22 by mleticia          #+#    #+#             */
/*   Updated: 2020/03/02 16:52:21 by mleticia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t		count_for_len(__int128_t nbr, int base, t_flag *all_mod)
{
	int				count;
	__int128_t		copy;
	__int128_t		spec;

	count = 0;
	spec = nbr;
	copy = nbr;
	if (all_mod->spc == 'u' && (all_mod->len == 3 || all_mod->len == 4))
	{
		count = count_for_len_llu(nbr, base);
		return (count);
	}
	(nbr < 0 || nbr == 0) ? count += 1 : 0;
	nbr < 0 ? nbr *= -1 : nbr;
	while (nbr > 0)
	{
		nbr /= base;
		count += 1;
	}
	if (all_mod->f_sh == '#')
		(copy != 0) ? count += ft_check(all_mod, spec) : 0;
	(all_mod->f_pl == '+' && all_mod->spc != 'u') ? \
	count += ft_check(all_mod, spec) : 0;
	all_mod->res = all_mod->res + count;
	return (count);
}

static long long	ft_finder(va_list all_arg, t_flag *all_mod)
{
	if (all_mod->len == 1 && ft_memchr("di", (int)all_mod->spc, 2))
		return ((short)va_arg(all_arg, int));
	if (all_mod->len == 2 && ft_memchr("di", (int)all_mod->spc, 2))
		return ((signed char)va_arg(all_arg, int));
	if (all_mod->len == 3 && ft_memchr("di", (int)all_mod->spc, 2))
		return ((long)va_arg(all_arg, long));
	if (all_mod->len == 4 && ft_memchr("di", (int)all_mod->spc, 2))
		return (va_arg(all_arg, unsigned long long));
	if (!all_mod->len && ft_memchr("oxXu", (int)all_mod->spc, 4))
		return ((unsigned int)va_arg(all_arg, unsigned int));
	if (all_mod->len == 1 && ft_memchr("oxXu", (int)all_mod->spc, 4))
		return ((unsigned short)va_arg(all_arg, int));
	if (all_mod->len == 2 && ft_memchr("oxXu", (int)all_mod->spc, 4))
		return ((unsigned char)va_arg(all_arg, int));
	if (all_mod->len == 3 && ft_memchr("oxXu", (int)all_mod->spc, 4))
		return (va_arg(all_arg, unsigned long long));
	if (all_mod->len == 4 && ft_memchr("oxXub", (int)all_mod->spc, 5))
		return (va_arg(all_arg, unsigned long long));
	if (all_mod->spc == 'p')
		return (uintptr_t)(va_arg(all_arg, void*));
	else
		return (va_arg(all_arg, int));
}

static void			ft_next_for_def(t_flag *all_mod, char *sign, long long nbr,\
int len)
{
	int				base;

	base = 0;
	if (!(ft_memchr("pid", (int)all_mod->spc, 3)) && nbr == 0 && \
	all_mod->width <= 0 && all_mod->prc <= 0)
	{
		ft_zero(all_mod);
		return ;
	}
	(all_mod->spc == 'p') ? ft_spec_p(all_mod, nbr, len) : 0;
	(all_mod->spc == 'i' || all_mod->spc == 'd') ? \
	ft_digit(all_mod, sign, nbr, len) : 0;
	(all_mod->spc == 'b') ? base = 2 : 0;
	(all_mod->spc == 'o') ? base = 8 : 0;
	(all_mod->spc == 'u') ? base = 10 : 0;
	((all_mod->spc == 'X') || (all_mod->spc == 'x')) ? base = 16 : 0;
	(ft_memchr("uboXx", (int)all_mod->spc, 5)) ? \
	ft_x(all_mod, nbr, base, len) : 0;
}

static int			*ft_base(va_list all_arg, t_flag *all_mod, int base)
{
	int				len;
	long long		nbr;
	char			*sign;

	nbr = ft_finder(all_arg, all_mod);
	if (all_mod->spc != 'i' && all_mod->spc != 'd')
		sign = nbr >= 0 ? "+" : "-";
	else
		sign = nbr >= 0 ? "0" : "-";
	len = count_for_len(nbr, base, all_mod);
	if (all_mod->spc == 'u' && (all_mod->len == 3 || all_mod->len == 4))
	{
		ft_llu(all_mod, nbr, base, len);
		return (0);
	}
	nbr < 0 ? nbr *= -1 : nbr;
	if (all_mod->spc != 'i' && all_mod->spc != 'd')
	{
		((*sign == '-') && (!(ft_memchr("di", (int)all_mod->spc, 2) && \
		all_mod->width > 0 && all_mod->width > all_mod->prc))) ? \
		write(1, sign, 1) : 0;
	}
	(ft_memchr("uboXxpid", (int)all_mod->spc, 8)) ? \
	ft_next_for_def(all_mod, sign, nbr, len) : 0;
	return (0);
}

size_t				ft_function(va_list all_arg, t_flag *all_mod)
{
	(all_mod->spc == 'c') ? ft_spec_c(all_arg, all_mod) : 0;
	(all_mod->spc == 's') ? ft_spec_s(all_arg, all_mod) : 0;
	((all_mod->spc == 'd') || (all_mod->spc == 'i') || (all_mod->spc == 'u')) \
	? ft_base(all_arg, all_mod, 10) : 0;
	(all_mod->spc == 'b') ? ft_base(all_arg, all_mod, 2) : 0;
	(all_mod->spc == 'o') ? ft_base(all_arg, all_mod, 8) : 0;
	((all_mod->spc == 'X') || (all_mod->spc == 'x') || (all_mod->spc == 'p')) \
	? ft_base(all_arg, all_mod, 16) : 0;
	(all_mod->spc == '%') ? ft_percent(all_mod) : 0;
	(all_mod->spc == 'f') ? ft_spec_f(all_arg, all_mod) : 0;
	(all_mod->spc == 'k') ? ft_spec_k(all_arg, all_mod) : 0;
	(all_mod->spc == 'r') ? ft_spec_r(all_arg, all_mod) : 0;
	return (0);
}
