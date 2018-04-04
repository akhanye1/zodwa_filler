/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zphakath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:58:20 by zphakath          #+#    #+#             */
/*   Updated: 2018/01/10 17:35:50 by zphakath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

nclude <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int  main(int ac, char *av[])
{
		int fd;
		char *buff;
		int buffsize;
		buffsize = 19;
		fd = open(av[1], O_RDONLY);
		if ( fd == -1)
		{
			printf("failed to open the file.\n");
			exit(1);
		}
		get_next_line(0, av[1]);20 
		close(fd);
		printf("%s\n", buff);
		return (0);
}
