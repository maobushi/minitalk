/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:28:53 by mobushi           #+#    #+#             */
/*   Updated: 2023/04/21 20:29:43 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>

void signal_handler(int signum)
{
    static int i = 0;
    static unsigned char output = UCHAR_MAX;
    unsigned char flag = 128;

    if(signum == SIGUSR1)
    {
        i++;
    }
    else if(signum == SIGUSR2)
    {
        output = output ^ (flag >> i);
        i++;
    }

    if(i == 8)
    {
        write(1,&output,1);
        output = UCHAR_MAX;
        i = 0;
    }

}

int main(void){
    printf("UNKO\n");
    //write(STDOUT_FILENO, getpid(), 6);
    printf("HIKAKINTV:%d\n",getpid());
    signal(SIGUSR1,&signal_handler);
    signal(SIGUSR2,&signal_handler);
    while(1)
        pause();
}

