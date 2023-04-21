/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:42:30 by vescaffr          #+#    #+#             */
/*   Updated: 2023/04/21 14:44:41 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
    private :

    public :
        Harl();
        ~Harl();
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        void complain(std::string level);
};

typedef void (Harl::*t_func) ( void );

#endif