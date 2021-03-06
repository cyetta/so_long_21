/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:28:12 by cyetta            #+#    #+#             */
/*   Updated: 2022/03/26 21:19:43 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/libft.h"
#include "../mlx/mlx.h"
#include "so_long.h"

void	init_gwin(t_gwin *gwin)
{
	ft_memset(gwin, 0, sizeof(t_gwin));
}

void	init_hook(t_gwin *gwin)
{
	mlx_hook(gwin->mlx_win, 2, 1L << 0, keydown_h, gwin);
	mlx_hook(gwin->mlx_win, 17, 1L << 0, closewin_h, gwin);
	mlx_loop_hook(gwin->mlx, render_h, gwin);
}

int	create_win(t_gwin *gwin)
{
	gwin->x_wind = gwin->gmap.col * TILE_SZ;
	gwin->y_wind = gwin->gmap.row * TILE_SZ;
	gwin->mlx = mlx_init();
	if (!gwin->mlx)
	{
		ft_putstr_fd("Error\nmlx not initialized", 2);
		clean_map(&(gwin->gmap));
		return (0);
	}
	gwin->mlx_win = mlx_new_window(gwin->mlx, gwin->x_wind, gwin->y_wind, \
"so_long");
	if (!loadtile(gwin))
		return (0);
	init_hook(gwin);
	mlx_loop(gwin->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_gwin	gwin;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long [maps].ber\n", 2);
		return (1);
	}
	init_gwin(&gwin);
	if (!load_map(&gwin.gmap, argv[1]))
		return (2);
	if (!create_win(&gwin))
		return (2);
	return (0);
}
