/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcalon <jcalon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:22:36 by jcalon            #+#    #+#             */
/*   Updated: 2022/07/01 17:10:27 by jcalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_arg;

typedef struct s_philo {
	int				id;
	int				eat_done;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	fed;
	long			last;
	struct s_arg	*args;
}				t_philo;

typedef struct s_arg
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meal;
	long			start;
	int				philo_id;
	int				dead;
	t_philo			*philos;
	pthread_t		*tids;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	over;
}					t_arg;

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		create_threads(t_arg *args);
long	ft_time(void);
void	custom_printf(char *s, t_philo *philo);
int		check_status(t_arg *args);
long	ft_time_diff(long clock);
void	ft_end(t_arg *args);

#endif