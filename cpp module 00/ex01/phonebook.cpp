/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:40:04 by vescaffr          #+#    #+#             */
/*   Updated: 2023/04/14 17:56:40 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook()
{
	this->amount = 0;
}

Phonebook::~Phonebook()
{
}

void Phonebook::add(void)
{
	if (this->amount == 8)
		std::cout << "# The directory is full !" << std::endl;
	else if (this->contacts[this->amount].set_informations(this->amount + 1))
		this->amount++;
}

void Phonebook::show_search_header(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->amount; i++)
		this->contacts[i].display_header();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void Phonebook::search(void)
{
	int	index;

	if (this->amount == 0)
		std::cout << "# Add a contact before searching !" << std::endl;
	else
	{
		this->show_search_header();
		std::cout << "# Enter Index to display Informations or 0 to Exit\n>";
		while (!(std::cin >> index) || (index < 0 || index > this->amount))
		{
			if (std::cin.eof())
			return;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "# Invalid Index\n~";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index > 0)
			this->contacts[index - 1].display();
	}
}