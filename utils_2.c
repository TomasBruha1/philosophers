/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:49:21 by tbruha            #+#    #+#             */
/*   Updated: 2025/05/05 13:45:24 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	dead_check(t_table *table)
{
	size_t	i;
	size_t	current;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		current = get_time(&table->start);
		if ((current - table->philos[i].last_meal_ms)
			> table->philos[i].time_to_die)
		{
			print_state(&table->philos[i], DEAD);
			table->sim = false;
			i = 0;
			while (i < table->nbr_of_philos)
			{
				table->philos[i].dead = true;
				i++;
			}
		}
		i++;
	}
}

void	eaten_enough(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		if (table->philos[i].times_eaten < table->nbr_to_eat)
			return ;
		i++;
	}
	table->sim = false;
	i = 0;
	while (i < table->nbr_of_philos)
	{
		table->philos[i].dead = true;
		i++;
	}
	print_state(&table->philos[0], FULL);
	return ;
}

// Loops to check dead state and if they ate enough, then print the message.
void	*waiter_routine(void *arg)
{
	t_table		*table;

	table = (t_table *)arg;
	while (table->sim == true)
	{
		dead_check(table);
		if (table->nbr_to_eat > 0 && table->sim == true)
			eaten_enough(table);
	}
	return (NULL);
}
