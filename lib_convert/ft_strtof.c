/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtof.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: quentinbeukelman <quentinbeukelman@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/25 23:48:26 by quentinbeuk   #+#    #+#                 */
/*   Updated: 2024/12/26 00:38:08 by quentinbeuk   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Skip leading whitespace
static void	ft_skipspace(const char **ptr)
{
	while (**ptr == ' ' || **ptr == '\t')
		(*ptr)++;
}

// Handle optional sign
static int	ft_handle_sign(const char **ptr)
{
	int		sign;

	sign = 1;
	if (**ptr == '-')
	{
		sign = -1;
		(*ptr)++;
	}
	else if (**ptr == '+')
		(*ptr)++;
	return (sign);
}

// Convert the integer part
static float	ft_convert_integer(const char **ptr)
{
	float	result;

	result = 0.0;
	while (ft_isdigit(**ptr))
	{
		result = result * 10.0 + (**ptr - '0');
		(*ptr)++;
	}
	return (result);
}

/*
	ft_strtof - Converts a string to a floating-point number (float).

	This function parses a string representation of a floating-point number,
	handling optional whitespace, sign, integer part, and fractional part. 
	It emulates the behavior of the standard `strtof` function.

	Parameters:
	- str: The input string containing the number to convert.
	- endptr: If non-NULL, this is set to point to the first character 
		after the number in the input string.

	Returns:
	- The converted floating-point number as a `float`.
*/
float	ft_strtof(const char *str, char **endptr)
{
	const char		*ptr;
	int				sign;
	float			result;
	float			decimal_factor;

	ptr = str;
	decimal_factor = 0.1;
	ft_skipspace(&ptr);
	sign = ft_handle_sign(&ptr);
	result = ft_convert_integer(&ptr);
	if (*ptr == '.')
	{
		ptr++;
		while (isdigit(*ptr))
		{
			result += (*ptr - '0') * decimal_factor;
			decimal_factor /= 10.0;
			ptr++;
		}
	}
	result *= sign;
	if (endptr)
		*endptr = (char *)ptr;
	return (result);
}
