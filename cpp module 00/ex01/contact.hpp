/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:39:28 by valentin          #+#    #+#             */
/*   Updated: 2023/04/14 18:07:37 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string> 

class Contact
{
 private:
	int index;
	static std::string	fields_name[5];
	std::string			informations[5];

	enum Field {
		first_name = 0,
		LastName,
		Nickname,
		Phone,
		secret
	};
 public:
            Contact();
            virtual ~Contact();
	bool	set_informations(int index);
	void	display_header();
	void	display(void);
};

#endif