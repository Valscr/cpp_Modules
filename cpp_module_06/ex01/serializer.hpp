/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:24:32 by valentin          #+#    #+#             */
/*   Updated: 2023/06/22 17:10:12 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    std::string name;
    int         number;
};

class Serializer 
{
    public:
        static uintptr_t    serialize(Data *data) {
            return (reinterpret_cast< uintptr_t >(data));
        }

        static Data*   deserialize(uintptr_t data) {
            return (reinterpret_cast<Data*>(data));
        }
};

#endif