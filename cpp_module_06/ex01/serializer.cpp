/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:24:42 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 11:25:44 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

uintptr_t    serialize(Data *data)
{
    return (reinterpret_cast< uintptr_t >(data));
}

Data*   deserialize(uintptr_t data)
{
    return (reinterpret_cast<Data*>(data));
}