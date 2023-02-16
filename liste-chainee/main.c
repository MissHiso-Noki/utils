#include "liste_chainee.h"

int	main()
{
	t_element	*maliste;

	insertion_debut(&maliste, 0);
	insertion_debut(&maliste, 4);
	insertion_debut(&maliste, 8);
	insertion_debut(&maliste, 15);
	afficherliste(&maliste);
	insertion_fin(maliste, 41);
	afficherliste(&maliste);
	suppression_debut(&maliste);
	afficherliste(&maliste);
	insertion_element(maliste, maliste->next, 56);
	afficherliste(&maliste);
	supprimer_element(&maliste, 27);
	afficherliste(&maliste);

	return (0);
}
