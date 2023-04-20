/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:38:43 by valentin          #+#    #+#             */
/*   Updated: 2023/04/14 18:07:27 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::fields_name[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = first_name; i <= secret; i++)
		this->informations[i] = std::string();
}

Contact::~Contact()
{
}

bool Contact::set_informations(int index)
{
	this->index = index;
	int i = first_name;
	while (i <= secret)
	{
		if (std::cin.eof())
			return (false);
		std::cout << "# " << Contact::fields_name[i] << ": ";
		std::getline(std::cin, this->informations[i]);
		if (this->informations[i].empty())
    		std::cout << "Error: please enter a valid input" << std::endl;
		else
			i++;
	}
	size_t totalLength = 0;
	for (int i = first_name; i <= secret; i++)
		totalLength += this->informations[i].length();
	if (totalLength == 0)
	{
		std::cout << "# Empty contact not added !" << std::endl;
		return (false);
	}
	std::cout << "# Contact added !" << std::endl;
	return (true);
}

void Contact::display_header()
{
	std::cout << "|" << std::setw(10) << this->index;
	for (int i = first_name; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->informations[i].length() > 10)
			std::cout << this->informations[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->informations[i];
	}
	std::cout << "|" << std::endl;
}

void Contact::display(void)
{
	std::cout << "# Contact [" << this->index << "]" << std::endl;
	for (int i = first_name; i <= secret; i++)
	{
		std::cout << Contact::fields_name[i] << ": ";
		std::cout << this->informations[i] << std::endl;
	}
}