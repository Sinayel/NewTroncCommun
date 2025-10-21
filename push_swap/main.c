/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanis <yanis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:09:52 by yanis             #+#    #+#             */
/*   Updated: 2025/10/14 17:16:14 by yanis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *get_data()
{
    static t_data data;

    return (&data);
}



int main(int argc, char *argv[])
{
    if(argc == 2) //! A Changer apres sa dois pouvoir prendre autant d'agument que l'on souhaite
    {
        int i;
        t_data *data;
        data = get_data();
        i = 0;
        
    }
}