/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:08:33 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/06 15:16:42 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// HEADERS

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
	double  		time_to_die;
	double  		time_to_eat;
	double  		time_to_sleep;
	int     		number_of_times_each_philosopher_must_eat;
	bool			fork; // maybe??
	pthread_mutex_t	mutex_fork;
}				t_philo;

typedef struct s_table
{
	int				number_of_philosophers;
	t_philo			*philo; // how to store multiple philos here?
	pthread_mutex_t	mutex;
	struct timeval	start;
	struct timeval	now;
	
}				t_table;
// FUNCTIONS

// utils.c
void	error_args();
// get_time(t_table main);

// philosophers.c

#endif