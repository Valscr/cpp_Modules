/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:28:37 by valentin          #+#    #+#             */
/*   Updated: 2023/06/06 11:36:33 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int main( void )
{
    Data *data = new Data;

    data->name = "val";
    data->number = 30;

    uintptr_t serializedData = serialize(data);

    Data* deserializedData = deserialize(serializedData);

    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Number: " << deserializedData->number << std::endl;

    delete deserializedData;

    return 0;
}