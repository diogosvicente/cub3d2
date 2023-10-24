/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:31:29 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 15:54:09 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

// vertical(tmp, angle, all); ok !!! aparentemente.

// angle = remainder(angle, TWO_PI);
// angle = fmod(angle, TWO_PI);
// printf("%f\n", angle);
// if (angle < 0)

static void	buildray(t_all *all, t_hit *ref, int col)
{
	all->rays[col].wallhitx = ref->hitx;
	all->rays[col].wallhity = ref->hity;
	all->rays[col].wallhitcontent = ref->content;
}

static void	castray(float angle, int col, t_all *all)
{
	t_cast	*tmp;
	float	hdist;
	float	vdist;

	tmp = &all->cst;
	check_view(tmp, angle);
	horizontal(tmp, angle, all);
	vertical(tmp, angle, all);
	hdist = dist_point(&all->player, &tmp->horz);
	vdist = dist_point(&all->player, &tmp->vert);
	all->rays[col].rayangle = angle;
	if (vdist < hdist)
	{
		all->rays[col].distance = vdist;
		all->rays[col].washitver = TRUE;
		buildray(all, &tmp->vert, col);
	}
	else
	{
		all->rays[col].distance = hdist;
		all->rays[col].washitver = FALSE;
		buildray(all, &tmp->horz, col);
	}
}

static float	normalizeangle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

void	castallrays(t_all *all)
{
	float	dis_proj_plan;
	float	view_angle;
	int		col;

	dis_proj_plan = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	col = 0;
	init_tmp(&all->cst);
	while (col < NUM_RAYS)
	{
		view_angle = all->player.rotationangle
			+ atan((col - NUM_RAYS / 2) / dis_proj_plan);
		view_angle = normalizeangle(view_angle);
		castray(view_angle, col, all);
		col++;
	}
}
