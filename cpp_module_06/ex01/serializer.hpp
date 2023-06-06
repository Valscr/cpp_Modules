/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:24:32 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 11:28:56 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data
{
    std::string name;
    int         number;
};

uintptr_t    serialize(Data *data);
Data*   deserialize(uintptr_t data);

#endif