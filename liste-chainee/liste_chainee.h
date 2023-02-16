/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainee.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:55:54 by ccoste            #+#    #+#             */
/*   Updated: 2023/02/15 12:21:05 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTE_CHAINEE_H
# define LISTE_CHAINEE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_element
{
	void			*content;
	struct s_element	*next;
}					t_element;

void	insertion_debut(t_element **liste, int nvNombre);
void	insertion_element(t_element *liste, t_element *adresse, int nv_element);
void	insertion_fin(t_element *liste, int nvNombre);

void	suppression_debut(t_element **liste);
void	supprimer_element(t_element **liste, int valeur);

void	afficherliste(t_element **liste);

#endif
