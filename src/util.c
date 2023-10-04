/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:23:19 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/02 18:35:31 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

float	calpoints(float x1, float x2, float y1, float y2)
{
	float	x;
	float	y;

	x = x2 - x1;
	y = y2 - y1;
	return (sqrt((x * x) + (y * y)));
}

float	dist_point(t_play *p, t_hit *ref)
{
	float	res;

	res = 2147483647;
	if (ref->wallhit == TRUE)
		res = calpoints(p->px, ref->hitx, p->py, ref->hity);
	return (res);
}
