/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainee.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:55:09 by ccoste            #+#    #+#             */
/*   Updated: 2023/02/15 12:20:42 by ccoste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liste_chainee.h"


// insertion d'un nouvel element debut de liste
void	insertion_debut(t_element **liste, int nvNombre)
{
	t_element	*nouveau;
	int			*elem;

	nouveau = *liste;

	// creation du nouvel element
	nouveau = malloc(sizeof(*nouveau));
	if (nouveau == NULL)
	{
		return ;
	}
	// recuperation de l'int elem qui prend la valeur du nouveau nbr et stock dans la liste
	elem = malloc(sizeof(int));
	if (elem == NULL)
	{
		return ;
	}
	*elem = nvNombre;
	nouveau->content = elem;

	// insertion de l'element au debut de la liste
	// 1 : faire pointer notre nouvel element vers sont futur succeseur,
	// qui es l'actuel premiere element de la liste
	// 2 : faire pointer le pointeur "premier" vers notre nouvel element
	nouveau->next = *liste;
	*liste = nouveau;
}

//insertion precise millieu de liste
void	insertion_element(t_element *liste, t_element *adresse, int nv_element)
{
	t_element	*nouveau;
	t_element	*tmp;
	int			*elem;

	nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
	{
		return ;
	}

	//recuperation de l'int elem qui prend la valeur du nouveau nbr et stock dans la liste
	elem = malloc(sizeof(int));
	if (elem == NULL)
	{
		return ;
	}
	*elem = nv_element;
	nouveau->content = elem;

	while (liste != NULL)
	{
		if (liste == adresse)
		{
			tmp = liste->next;
			nouveau->next = tmp;
			liste->next = nouveau;
		}
		liste = liste->next;
	}
}

//insertion precise millieu de liste
// void	insertion_element(t_element *liste, int valeur, int nv_element)
// {
// 	t_element	*nouveau;
// 	t_element	*previous;
// 	t_element	*tmp;
// 	int			*elem;
// 	int			*elem_valeur;

// 	nouveau = malloc(sizeof(*nouveau));
// 	if (liste == NULL || nouveau == NULL)
// 	{
// 		return ;
// 	}

// 	recuperation de l'int elem qui prend la valeur du nouveau nbr et stock dans la liste
// 	elem = malloc(sizeof(int));
// 	if (elem == NULL)
// 	{
// 		return ;
// 	}
// 	*elem = nv_element;
// 	nouveau->content = elem;

// 	elem_valeur = malloc(sizeof(int));
// 	if (elem_valeur == NULL)
// 	{
// 		return ;
// 	}
// 	*elem_valeur = valeur;
// 	previous->content = elem_valeur;

// 	while (liste != NULL)
// 	{
// 		if (liste == elem_valeur)
// 		{
// 			tmp = liste->next;
// 			nouveau->next = tmp;
// 			liste->next = nouveau;
// 		}
// 		liste = liste->next;
// 	}
// }

// insertion d'un nouvel element en fin de liste
void	insertion_fin(t_element *liste, int nvNombre)
{
	t_element	*tmp;
	t_element	*nouveau;
	int	*elem;

	tmp = liste;
	nouveau = malloc(sizeof(*nouveau));
	if (nouveau == NULL)
	{
		return ;
	}

	// recuperation de l'int elem qui prend la valeur du nouveau nbr et stock dans la liste
	elem = malloc(sizeof(int));
	if (elem == NULL)
	{
		return ;
	}
	*elem = nvNombre;
	nouveau->content = elem;

	nouveau->next = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = nouveau;
}

// suppression du premier element de la liste
void	suppression_debut(t_element **liste)
{
	if (liste == NULL)
	{
		return ;
	}

	if ((*liste)->next != NULL)
	{
		t_element	*aSupprimer;

		// sauvegarder l'adresse de l'element a supprimer dans
		// un pointeur "aSupprimer"
		aSupprimer = *liste;
		// 1 : faire pointer "premier" vers le second element
		// (le nouveau premier element apres suppression du premier)
		// 2 : supprimer le premier element avec free et sont content
		(*liste) = (*liste)->next;
		free(aSupprimer->content);
		free(aSupprimer);
	}
}

//supprimer element precis dans une liste
void	supprimer_element(t_element **liste, int valeur)
{
	t_element	*tmp_first;
	t_element	*tmp_list;
	t_element	*previous;

	// si probleme return
	if (liste == NULL)
	{
		return ;
	}
	// si la valeur est en debut de liste (cas special)
	else if (*((int *)(*liste)->content) == valeur)
	{
		tmp_first = *liste;
		(*liste) = (*liste)->next;
		free(tmp_first->content);
		free(tmp_first);
	}
	else
	{
		tmp_list = *liste;
		previous = NULL;

		// avance dans la liste jusqu'a avoir la valeur ou jusqu'a fin de liste
		// garde en memoire la case d'avant avec previous
		while (tmp_list != NULL && *((int *)tmp_list->content) != valeur)
		{
			previous = tmp_list;
			tmp_list = tmp_list->next;
		}
		// si la valeur n'es pas dans la liste return
		if (tmp_list == NULL)
		{
			return ;
		}
		// si la valeur es dans la liste relis case d'avant a celle d'apres
		// la valeur et supprimer la case de notre valeur
		else
		{
			previous->next = tmp_list->next;
			free(tmp_list->content);
			free(tmp_list);
		}
	}
}

// afficher la liste chainee
void	afficherliste(t_element **liste)
{
	t_element	*actuel;

	// part du premier element
	actuel = *liste;
	if (liste == NULL)
	{
		return ;
	}

	while(actuel != NULL)
	{
		// affiche contenu chaque elements
		printf("[%d] -> ", *((int *)actuel->content));
		// passe au suivant a chaque fois
		actuel = actuel->next;
	}
	printf("NULL\n");
}
