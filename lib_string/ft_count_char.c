/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 20:58:26 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/25 20:58:54 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_char(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
