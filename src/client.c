/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msys <msys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:28:51 by msys              #+#    #+#             */
/*   Updated: 2022/12/07 22:47:21 by msys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include<stdio.h>
#include<libc.h>


int main(int argc,char **argv)
{
    pid_t pid;
    unsigned char flag;
    size_t i;
    flag = 128;

    pid = 0;
    pid = (pid_t)atoi(argv[1]);
    printf("PIDis:%d,Send:%s",pid,argv[2]);
    
    while(*argv[2] != '\0')
    {
        i = 0;
        while(i < 8)
        {
            //send 1
            if(*argv[2] & (flag >> i))
            {
                kill(pid,SIGUSR1);
            }
            else//send 0
            {
                kill(pid,SIGUSR2);
            }
            usleep(2000);


            i++;
        }
        usleep(2000);
        argv[2]++;
    }
    
    if(pid != 0)
        
    return 0;

}
