/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:49:21 by tbruha            #+#    #+#             */
/*   Updated: 2025/04/29 21:06:40 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// void	dead_check()

// Loops to check dead state and if they ate enough, then print the message.
void    *waiter_routine(void *arg)
{
	t_table 	*table = (t_table *)arg;
	size_t		i;
	size_t		current;
	i = 0;
	
	while (table->sim == true)
	{
		while (i < table->nbr_of_philos) // Here can be health check ft (dead)
		{
			current = get_time(&table->start);
			if ((current - table->philos[i].last_meal_ms) > table->philos[i].time_to_die)
			{
				print_state(&table->philos[i], DEAD);
				table->sim = false; // Nice, but what do I do with it?
				i = 0;
				while (i < table->nbr_of_philos)
				{
					table->philos[i].dead = true;
					i++;	
				}
				// exit(EXIT_FAILURE); // EXIT IS FORBIDDEN -> break twice??
				// if not dead check if ate enough
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}
