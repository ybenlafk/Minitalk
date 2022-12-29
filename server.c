/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:49:47 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/29 21:54:54 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handler(int sig)
{
    static int c;
    static int bits;

    if (sig == SIGUSR2)
        c |= 128 >> bits;
    bits++;
    if (bits == 8)
    {
        write(1, &c, 1);
        bits = 0;
        c = 0;
    }
}

int main()
{
    putstrr("Server PID : ");
    putnbr(getpid());
    putstrr("\n");
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
}