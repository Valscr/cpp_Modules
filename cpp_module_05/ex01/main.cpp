/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:23:12 by valentin          #+#    #+#             */
/*   Updated: 2023/06/04 21:19:25 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
    Bureaucrat bureau1("bureau1", 1);
    Form form("formulaire",15, 15);
    std::cout << form;
    std::cout << bureau1;
    form.beSigned(bureau1);
    bureau1.signform(form);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}