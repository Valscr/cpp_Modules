/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vescaffr <vescaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 10:28:37 by valentin          #+#    #+#             */
/*   Updated: 2023/06/22 17:08:30 by vescaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int main( void )
{
    Data *data = new Data;

    data->name = "val";
    data->number = 30;

    uintptr_t serializedData = Serializer::serialize(data);

    Data* deserializedData = Serializer::deserialize(serializedData);

    std::cout << "Name: " << deserializedData->name << std::endl;
    std::cout << "Number: " << deserializedData->number << std::endl;

    delete deserializedData;

    return 0;
}