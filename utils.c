/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:43 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/07 11:52:05 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// Prints error message and exit upon wrong number of inputs.
void	error_args()
{
	printf("Wrong number of arguments. Input 4 or 5 values to proceed.\n");
	exit(EXIT_FAILURE);
}

// This function will return time in miliseconds from the start.
long int	get_time(t_table *table)
{
	long int 		time;
	struct timeval	current;
	
	gettimeofday(&current, NULL);
	time = (current.tv_sec * 1000 + current.tv_usec / 1000) - table->start;
	return (time);
}