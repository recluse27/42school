/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 14:59:20 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/23 15:00:37 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "b_printf/printf.h"

int		main(void)
{
	// int c = 3;
	// int b = -3;
	// b_printf("Hello %d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	// b_printf("Hello %d terter\n", -11);
	// printf("Hello %d terter\n", -11);

	// b_printf("Hello %i terter\n", 10);
	// printf("Hello %i terter\n", 10);
	// b_printf("Hello %i terter\n", -5);
	// printf("Hello %i terter\n", -5);

	// b_printf("Hello %s terter\n", "");
	// printf("Hello %s terter\n", "");
	// b_printf("Hello %s terter\n", "world");
	// printf("Hello %s terter\n", "world");

	// b_printf("Hello %c terter\n", 'a');
	// printf("Hello %c terter\n", 'a');
	// b_printf("Hello %c terter\n", 33);
	// printf("Hello %c terter\n", 33);

	// b_printf("Hello %o terter\n", 1);
	// printf("Hello %o terter\n", 1);
	// b_printf("Hello %o terter\n", 100);
	// printf("Hello %o terter\n", 100);

	// b_printf("Hello %u terter\n", 1);
	// printf("Hello %u terter\n", 1);
	// b_printf("Hello %u terter\n", -1);
	// printf("Hello %u terter\n", -1);

	// b_printf("Hello %p terter\n", &c);
	// printf("Hello %p terter\n", &c);
	// b_printf("Hello %p terter\n", &b);
	// printf("Hello %p terter\n", &b);

	// b_printf("Hello %x terter\n", 13);
	// printf("Hello %x terter\n", 13);
	// b_printf("Hello %x terter\n", -3);
	// printf("Hello %x terter\n", -3);

	// b_printf("Hello % % terter\n");
	// printf("Hello % % terter\n");

	// printf("HALLO");
	// printf("%d", "%d");
	// printf("\n----\n");
	// printf("%d", "%d\n");
	// b_printf("%u", -356);
	// printf("\n - \n");
	// printf("%u", -356);
	// printf("\n ------------- \n");
	// b_printf("HALO %d", "%d", "%c");
	// printf("\n ---- \n");
	// printf("HALO %d", "%d", "%c");

	// printf("%d\n", b_printf("Hello %x terter", 120));
	// printf("%d\n", printf("Hello %x terter", 120));
	// printf("%d\n", b_printf("Hello %x terter", 12));
	// printf("%d\n", printf("Hello %x terter", 12));
	// printf("%d\n", b_printf("Hello %p terter", &b));
	// printf("%d\n", printf("Hello %p terter", &b));

	// printf("%d\n", b_printf("Hello %x terter", 74));
	// printf("%d\n", printf("Hello %x terter", 74));

	// b_printf("Hello %x terter\n", NULL);
	// printf("Hello %p terter\n", NULL);
	// b_printf("%s%s%s\n", "test", "test", "test");

	// b_printf("%s", "HASFASFASD");
	// printf(" == %s \n", "HASFASFASD");
	// b_printf("%d", 42);
	// printf(" == %d\n", 42);
	// b_printf("%d%d", 42, 41);
	// printf(" == %d%d\n", 42, 41);
	// b_printf("%d%d%d", 42, 43, 44);
	// printf(" == %d%d%d\n", 42, 43, 44);
	// b_printf("%x", 505);
	// printf(" == %x\n", 505);
	// b_printf("%p", &b_printf);
	// printf(" == %p\n", &b_printf);
	// b_printf("%");
	// printf(" == %\n");
	// b_printf("%u", 4294967295);
	// printf(" == %u\n", 4294967295);
	// b_printf("%o", 40);
	// printf(" == %o\n", 40);
	// b_printf("%x", 1000);
	// printf(" == %x\n", 1000);
	// b_printf("%s", NULL);
	// printf(" == %s\n", NULL);
	// b_printf("%s%s", "test", "test");
	// printf(" == %s%s\n", "test", "test");
	// b_printf("%s%s%s", "test", "test", "test");
	// printf(" == %s%s%s\n", "test", "test", "test");
	b_printf("%s HALO %s", NULL, "KEK");
	printf(" == %s HALO %s", NULL, "KEK");

	return (0);	
}
