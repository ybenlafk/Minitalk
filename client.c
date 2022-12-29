/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:49:43 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/29 16:23:48 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    send_msg(char c, pid_t pid)
{
    int        bt;
    int        i;

    i = 8;
    while (i--)
    {
        bt = (c >> i & 1);
        if (bt == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
                exit(0); 
        }
        else
        {
            if (kill(pid, SIGUSR2) == -1)
                exit(0);
        }
        usleep(600);
    }
    return ;
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        pid_t pid;
        int i;
        
        pid = ft_atoi(av[1]);
        i = 0;
        while (av[2][i])
            send_msg(av[2][i++], pid);
    }
}