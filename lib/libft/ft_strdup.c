/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:03:10 by srabah            #+#    #+#             */
/*   Updated: 2015/01/27 14:05:19 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = (char*)ft_memalloc(ft_strlen(s1) * sizeof(char) + 1);
	if (p != NULL)
		ft_strcpy(p, s1);
	return (p);
}
