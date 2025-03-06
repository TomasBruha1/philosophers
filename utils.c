/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:43 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/06 15:29:24 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

void	error_args()
{
	printf("Wrong number of arguments. Input 4 or 5 values to proceed.\n");
	exit(EXIT_FAILURE);
}
