/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:08:33 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/05 13:48:21 by tbruha           ###   ########.fr       */
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
	int     number_of_philosophers;
	double  time_to_die;
	double  time_to_eat;
	double  time_to_sleep;
//	int     number_of_times_each_philosopher_must_eat;
	bool	fork; // maybe??
}			t_philo;

// FUNCTIONS

// philosophers.c

#endif