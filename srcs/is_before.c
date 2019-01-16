#include "ft_ls.h"

int		ft_before_alpha(char *s1, char *s2)
{
	int	i;
	int	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	j = 0;
	i = 0;
	if (s1[0] == '.')
		i++;
	if (s2[0] == '.')
		j++;
	while (s1[i] && s2[j])
	{
		if (ft_tolower(s1[i]) > ft_tolower(s2[j]))
			return (-1);
		if (ft_tolower(s1[i] < ft_tolower(s2[j])))
			return (1);
		i++;
		j++;
	}
	return (0);
}
