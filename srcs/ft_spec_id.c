#include "../includes/ft_printf.h"

static void	ft_wid_and_prc(t_flag *all_mod, int len)
{
	if (all_mod->width > len)
	{
		if (all_mod->f_0 == 'N')
			all_mod->res += ft_wx(all_mod->width - len, '0');
		else if (all_mod->prc > 0)
		{
			all_mod->res += ft_wx(all_mod->width - all_mod->prc, ' ');
			if (all_mod->prc > len)
				all_mod->res += ft_wx(all_mod->prc - len, '0');
		}
		else
			all_mod->res += ft_wx(all_mod->width - len, ' ');
	}
	else if (all_mod->prc > len)
		all_mod->res += ft_wx(all_mod->prc - len, '0');
}

void		ft_digit(t_flag *all_mod, char *sign, long long num, int len)
{
	int	base;

	base = 10;
	if ((*sign == '-') && (all_mod->prc > len || (all_mod->f_0 == 'N')))
		write(1, sign, 1);
	else if (all_mod->f_pl == '+' && (all_mod->prc > len || \
	all_mod->f_0 == 'N'))
		write(1, "+", 1);
	((*sign == '-' || all_mod->f_pl == '+') && all_mod->prc > all_mod->width &&
	all_mod->prc > len) ? write(1, "0", 1) : 0;
	(*sign == '-' && all_mod->f_pl == '+') && ((all_mod->prc > len) || \
	(all_mod->width > len)) ? write(1, "0", 1) : 0;
	(all_mod->f_min != '-' && (all_mod->width > len || all_mod->prc > len)) ? \
	ft_wid_and_prc(all_mod, len) : 0;
	if (*sign == '-' && all_mod->f_0 != 'N' && ((all_mod->width <= len && \
	all_mod->prc <= len) || (all_mod->f_min == '-') || (all_mod->width > \
	all_mod->prc && all_mod->prc == -1)))
		write(1, sign, 1);
	else if (all_mod->f_pl == '+' && ((all_mod->width <= len && all_mod->prc \
	<= len) || (all_mod->f_min == '-') || (all_mod->width > all_mod->prc && \
	all_mod->prc == -1 && all_mod->f_0 != 'N')))
		write(1, "+", 1);
	ft_put_dec(all_mod, num, base);
	if (all_mod->f_min == '-' && all_mod->width > len)
		all_mod->res += ft_wx(all_mod->width - len, ' ');
}
