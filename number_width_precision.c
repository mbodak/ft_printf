/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_width_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbodak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:30:18 by mbodak            #+#    #+#             */
/*   Updated: 2017/03/22 15:30:26 by mbodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_min_width(t_saver *saver, char *str)
{
	char		*tmp;
	char		*res;
	size_t		i;

	if ((saver->width > 0) && (saver->width > ft_strlen(str)))
	{
		i = 0;
		saver->width = saver->width - (int)ft_strlen(str);
		tmp = ft_strnew((size_t)saver->width + 1);
		while (i < saver->width)
		{
			if (saver->minus_null == '0' && saver->precision < 0)
				tmp[i] = '0';
			else
				tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		if (saver->minus_null == '0')
		{
			if (str[1] == 'x')
				str = ft_strjoin(ft_strjoin("0x", tmp), str + 2);
			else if (str[1] == 'X')
				str = ft_strjoin(ft_strjoin("0X", tmp), str + 2);
			else
				str = ft_strjoin(tmp, str);
			res = ft_strdup(str);
		}
		else if (saver->minus_null == '-')
			res = ft_strjoin(str, tmp);
		else
			res = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		return (res);
	}
	return (str);
}

char		*add_precision(t_saver *saver, char *str)
{
	char 		*tmp;
	char		*res;
	size_t		len;
	size_t		size;
	size_t		i;

	len = ft_strlen(str);
	if (str[0] == '-' || (saver->specifier == 'o' && saver->hash == '#'))
		len = ft_strlen(str) - 1;
	else if (str[1] == 'x' || str[1] == 'X')
		len = ft_strlen(str) - 2;
	if (saver->precision > (int)len)
	{
		i = 0;
		size = (size_t)saver->precision - len;
		tmp = ft_strnew(size + 1);
		while (i < size)
			tmp[i++] = '0';
		tmp[i] = '\0';
		if (str[0] == '-')
			res = ft_strjoin(ft_strjoin("-", tmp), str + 1);
		else if (saver->specifier == 'o' && saver->hash == '#')
			res = ft_strjoin(tmp, str + 1);
		else if (str[1] == 'x')
			res = ft_strjoin(ft_strjoin("0x", tmp), str + 2);
		else if (str[1] == 'X')
			res = ft_strjoin(ft_strjoin("0X", tmp), str + 2);
		else
			res = ft_strjoin(tmp, str);
		free(tmp);
		free(str);
		return (res);
	}
	return (str);
}
