/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:24:44 by csinglet          #+#    #+#             */
/*   Updated: 2018/10/06 15:24:44 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	arg -> precision -> sign (+ or -) -> padding
**
**	if there's precision pad the left of the argument with
**	num_precision - numlen(arg) '0' characters
**	  if num is negative or positive is explicit append to the
**	  beginning of the argument
*/
/*
static void			append_sign(char **sign, char **fill, char **precision,
					char **str)
{
	if (*fill != NULL && *fill[0] == '0' && *sign != NULL)
		*fill = ft_strjoin(*sign, *fill);
	else if (*precision != NULL && *sign != NULL)
		*precision = ft_strjoin_free(*sign, *precision);
	else if (*precision == NULL && *sign != NULL)
		*str = ft_strjoin_free(*sign, *str);
	else if (*fill == NULL && *precision == NULL && *sign != NULL)
		*str = ft_strjoin_free(*sign, *str);
}

static void			append_precision(char **str, char **precision)
{
	if (*precision != NULL)
		*str = ft_strjoin_free(*precision, *str);
}

static void			append_fill(char **str, char **fill, t_pf *pf)
{
	if (*fill != NULL)
	{
		if (pf->flags & F_REV)
			*str = ft_strjoin_free(*str, *fill);
		else
			*str = ft_strjoin_free(*fill, *str);
	}
}

static void			combine_all(char **str, t_pf *pf)
{
	char			*precision;
	char			*fill;

	precision = signed_get_precision(*str, pf);
	fill = signed_get_fill(*str, pf);
	append_sign(&sign, &fill, &precision, str);
	append_precision(str, &precision);
	append_fill(str, &fill, pf);
}
*/
void				handle_signed(t_pf *pf)
{
	char			*ret;
	char			*temp;

	ret = get_signed_data_type(pf, 10, 0);
	if (ft_strcmp(ret, "0") == 0 && pf->precision == 0)
	{
		free(ret);
		ret = ft_strnew(0);
	}
	else if (ret[0] == '-')
	{
		BIT_ON(pf->flags, F_MINUS);
		BIT_OFF(pf->flags, F_PLUS);
		temp = ft_strdup(ret + 1);
		free(ret);
		ret = temp;
	}
	handle_padding(pf, &ret);
	// write_to_buffer(pf, ret, ft_strlen(ret));
	free(ret);
}

/*
**	if (rev == 0)
**		if (flag->rev == 0)
**			add padding
**		add sign
**
**	add arg
**
**	if (rev == 1) happens after the above
**		add padding
*/
