/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:50:13 by zphakath          #+#    #+#             */
/*   Updated: 2018/01/25 12:03:06 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct	s_l
{
	char		*line;
	struct s_l	*next;
}               t_line;

typedef struct	s_player
{
	int			number;
	char		piece_small;
	char		piece_large;
	struct s_l	*plateau;
	struct s_l	*piece_memory;
	int			p_countdown;
	int			piece_countdown;
	int			p_height;
	int			p_width;
	int			piece_height;
	int			piece_width;
	int			done_reading;
	char		**plateau_piece;
	char		**piece_piece;
}				t_player;

typedef struct	s_point
{
	int			y;
	int			x;
}				t_point;

char			get_player_info(char *line, t_player *player, int debug_fd);
char			get_plateau(char *line, t_player *player, int debug_fd);  
char			get_piece(char	*line, t_player *player, int debug_fd);
void			play_piece(t_player *player, int debug_fd);
#endif
