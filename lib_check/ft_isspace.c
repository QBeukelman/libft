/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 22:02:47 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/11 22:05:24 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

bool	ft_isspace(char c)
{
    if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\r'
		|| c == '\f'
		|| c == '\v')
        return (true);
    return (false);
}
