/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcacere <alcacere@student42madrid.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 09:36:08 by alcacere          #+#    #+#             */
/*   Updated: 2025/09/18 09:36:10 by alcacere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	is_valid_number(char *str)
{
	int	is_dot;

	is_dot = 0;
	if (*str == '\0')
		return (0);
	if (ft_issign(*str))
		str++;
	while (*str)
	{
		if (*str == '.' && *(str + 1))
		{
			is_dot++;
			str++;
		}
		if (!ft_isdigit(*str) || is_dot > 1)
			return (0);
		str++;
	}
	return (1);
}

static double	get_value(char *str)
{
	double	res;
	double	pow;

	res = 0.0;
	pow = 1.0;
	while (ft_isdigit(*str))
	{
		res = res * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		str++;
	while (ft_isdigit(*str))
	{
		pow /= 10;
		res = res * 10.0 + (*str - '0');
		str++;
	}
	return (res * pow);
}

double	ft_atod(char *str)
{
	double	res;
	double	sign;

	res = 0.0;
	sign = 1.0;
	if (!is_valid_number(str))
		arg_error();
	if (ft_issign(*str))
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	res = get_value(str);
	return (res * sign);
}
