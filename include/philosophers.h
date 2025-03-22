/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:08:33 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/22 14:30:57 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// HEADERS

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

// STRUCTS

typedef struct s_philo
{
	pthread_t		philo;
	int     		index;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	bool			fork_left; // own, 0 = on the table, 1 = in hand
	bool			fork_right; // borrowed, ditto
	pthread_mutex_t	mutex_fork_left;
	pthread_mutex_t	mutex_fork_right;
	int				times_eaten;
}					t_philo;

typedef struct s_table
{
	size_t			number_of_philosophers;
	t_philo			*philos; // array of philos [i]
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	mutex; // just coz for now...
	long int		start;
	int     		number_of_times_each_philosopher_must_eat; // array?
}				t_table;

// FUNCTIONS

// utils.c
void		error_args();
long int	get_time(t_table *table);
size_t	ft_atoi(char *str);

// philosophers.c

#endif
