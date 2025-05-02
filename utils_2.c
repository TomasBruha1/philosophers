/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:49:21 by tbruha            #+#    #+#             */
/*   Updated: 2025/05/02 17:55:42 by tbruha           ###   ########.fr       */
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
		while (i < table->nbr_of_philos)
		{
			// Here can be health check ft (dead)
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
			}
			if (table->nbr_to_eat > 0) // eaten_enough separate ft here
			{
				
				if (table->philos[i].times_eaten >= table->nbr_to_eat)
				{
					
				}
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}
