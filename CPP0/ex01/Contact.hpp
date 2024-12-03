#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string number;
	std::string secret;

public:
	Contact(void);
	~Contact(void);


};

#endif
