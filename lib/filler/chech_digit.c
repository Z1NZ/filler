/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chech_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 06:59:03 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 06:59:07 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_digit(char *tmp)
{
	while (*tmp != '\0')
	{
		ft_isdigit(*tmp);
		tmp++;
	}
	if (*tmp == '\0')
		return (1);
	else
		return (0);
}
