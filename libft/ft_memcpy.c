/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:22:35 by smonte-e          #+#    #+#             */
/*   Updated: 2022/12/07 22:37:25 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*coppy;
	unsigned char	*paste;

	if (dest == src)
		return (dest);
	coppy = (unsigned char *)src;
	paste = (unsigned char *)dest;
	while (n--)
	{
		*paste++ = *coppy++;
	}
	return (dest);
}

/*
struct {
  char name[40];
  int age;
} person, person_copy;

int main ()
{
  char myname[] = "Pierre de Fermat";

  ft_memcpy ( person.name, myname, strlen(myname)+1 );
  person.age = 46;

  ft_memcpy ( &person_copy, &person, sizeof(person) );

  printf ("person_copy: %s, %d \n", person_copy.name, person_copy.age );

  return 0;
}*/