#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string number;
	std::string secret;

public:
	Contact(void);
	void		setFirstName(std::string str);
	void		setLastName(std::string str);
	void		setNickname(std::string str);
	int			setNumber(std::string str);
	void		setSecret(std::string str);
	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getNickname(void);
	void		printContact(void);
	~Contact(void);


};

#endif
