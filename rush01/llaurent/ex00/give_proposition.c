
/*Will return a table of all the possible combinations
for a given first number*/
/*argument is the number of column you expect to see*/
/*returns a two dimensional array containing diferent possibilities*/

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src);

char *give_proposition(int first_nb) // 8 + 4 * 9 + 3 * 9
{

	char *table;
	char *tmp;

	table = (char *)malloc(sizeof(*table) * 76);
	if (table == NULL)
		return (NULL);
	if (first_nb == 4)
		table = "1,2,3,4\0";
	else if (first_nb == 1)
		table = "4,1,2,3;4,1,3,2;4,2,1,3;4,2,3,1;4,3,1,2;4,3,2,1\0";
	else if (first_nb == 2)
	{
		table = "3,4,1,2;2,4,1,3;2,4,3,1;3,1,2,4;3,1,4,2;3,2,1,4;3,2,4,1;3,4,1,2;3,4,2,1;4,1,2,3;2,1,4,3;1,4,2,3;1,4,3,2\0";
	}
	else if (first_nb == 3)
		table = "2,3,4,1;1,3,2,4;1,3,4,2;2,1,3,4;2,3,1,4;2,3,4,1\0";
	return (table);
}

