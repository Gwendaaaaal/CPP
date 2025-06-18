#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain& operator=(const Brain& other);
		Brain(const Brain &other);
		~Brain();

		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;
};

#endif
