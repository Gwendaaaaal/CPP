#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class ShrubberryCreationForm : public AForm {
private:
  std::string _target;

  virtual void doExecute() const;
public:
  ShrubberryCreationForm(const std::string &target);
  ShrubberryCreationForm(const ShrubberryCreationForm &other);
  ShrubberryCreationForm &operator=(const ShrubberryCreationForm &other);
  ~ShrubberryCreationForm();

};

#endif
