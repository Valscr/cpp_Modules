/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:41:33 by valentin          #+#    #+#             */
/*   Updated: 2023/04/14 18:01:56 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip> 
#include "contact.hpp"

class Phonebook
{
 private:
 	Contact contacts[8];
 	int		amount;
 public:
	Phonebook();
	virtual ~Phonebook();
	void	add(void);
	void	search(void);
	void	show_search_header(void);
};

#endif