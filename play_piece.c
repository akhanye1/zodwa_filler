/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:24:05 by zphakath          #+#    #+#             */
/*   Updated: 2018/01/25 16:50:29 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	fill_plateau(t_player *player, int debug_fd)
{
	char	**temp;
	int		i;
	t_line	*fr;
	t_line	*iter;

	i = 0;
	temp = (char**)malloc(sizeof(char*) * (player->p_height));
	temp[player->p_height - 1] = NULL;
	iter = player->plateau;
	ft_putendl_fd("Pleteau : ", debug_fd);
	while (iter)
	{
		temp[i] = ft_strdup(iter->line + 4);
		ft_putendl_fd(temp[i], debug_fd);
		i++;
		fr = iter;
		iter = iter->next;
		free(fr->line);
		free(fr);
	}
	player->plateau_piece = temp;
	ft_putendl_fd("finished Reading", debug_fd);
}

static void	fill_piece(t_player *player, int debug_fd)
{
	char	**temp;
	int		i;
	t_line	*fr;
	t_line	*iter;

	i = 0;
	temp = (char**)malloc(sizeof(char*) * (player->piece_height));
	temp[player->piece_height - 1] = NULL;
	iter = player->piece_memory;
	ft_putendl_fd("Piece: ", debug_fd);
	while (iter)
	{
		ft_putendl_fd(iter->line, debug_fd);
		temp[i++] = ft_strdup(iter->line);
		fr = iter;
		iter = iter->next;
		free(fr->line);
		free(fr);
	}
	player->piece_piece = temp;
}

static char	canFit(/*int y, int x, */t_player *player, t_point *point, int debug_fd)
{
	t_point	piecep;
	t_point	plateaup;
	int		conflictc;

	conflictc = 0;
	
	/*int		py;
	int		px;


	piecep.x = -1;
	piecep.y = -1;
	plateaup.y = y - (player->piece_height - 2);
	plateaup.x = x;
	conflictc = 0;
	y -= player->piece_height - 2;
	ft_putendl_fd("Reached fit function", debug_fd);
	while (++piecep.y < (player->piece_height - 1))
	{
		ft_putstr_fd("Y : ", plateaup.y);
		ft_putnbr_fd(piecep.y, debug_fd);
		ft_putchar_fd(' ', debug_fd);
		py = piecep.y;
		while (++piecep.x < player->piece_width)
		{
			px = piecep.x;
			ft_putnbr_fd(plateaup.x, debug_fd);
			ft_putchar_fd('\n', debug_fd);
			if (player->plateau_piece[plateaup.y + py][plateaup.x + px] == player->piece_small
					|| player->piece_piece[plateaup.y + py][plateaup.x + px] == player->piece_large)
				conflictc++;
			else if (player->plateau_piece[plateaup.y + py][plateaup.x + px]  != '.')
				return (0);
			if (conflictc > 1)
				return (0);
		}
	}
	point->y = plateaup.y;
	point->x = plateaup.x;
	if (conflictc == 1)
		return (1);
	return (0);*/
}

static void	scanForPlay(int debug_fd, t_player *player)
{
	int		platHeight;
	int		y;
	int		x;
	int		startX;
	t_point	point;

	platHeight = player->p_height - 1;
	y = 1;
	point.y = 0;
	point.x = 0;
	while (y < platHeight)
	{
		x = 0;
		while (x < player->p_width)
		{
			/*ft_putstr_fd("Comparing : ", debug_fd);
			ft_putchar_fd(player->plateau_piece[y][x], debug_fd);
			ft_putstr_fd(" and ", debug_fd);
			ft_putchar_fd(player->piece_large, debug_fd);
			ft_putchar_fd('\n', debug_fd);*/
			if (player->plateau_piece[y][x] == player->piece_small || player->plateau_piece[y][x] == player->piece_large)
			{
				ft_putstr_fd("Found at X Y :", debug_fd);
				ft_putnbr_fd(x, debug_fd);
				ft_putchar_fd(' ', debug_fd);
				ft_putnbr_fd(y, debug_fd);
				//ft_putstr_fd("Found char\n", debug_fd);
				point.y = y;
				point.x = x;
				if (canFit(y, x, player,  &point, debug_fd))
				{
					ft_putnbr(point.y);
					ft_putchar(' ');
					ft_putnbr(point.x);
					ft_putchar('\n');		
				}
			}
			x++;
		}
		y++;
	}
}

void	play_piece(t_player *player, int debug_fd)
{
	fill_plateau(player, debug_fd);
	fill_piece(player, debug_fd);

	scanForPlay(debug_fd, player);	
}
