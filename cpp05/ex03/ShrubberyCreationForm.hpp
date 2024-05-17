#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{

private:
	std::string target;

	void do_execute(const Bureaucrat &bureaucrat) const;

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

};

#define TREE "\n\
                                                         .\n\
                                              .         ;  \n\
                 .              .              ;\%     ;;   \n\
                   ,           ,                :;\%  \%;   \n\
                    :         ;                   :;\%;'     .,   \n\
           ,.        \%;     \%;            ;        \%;'    ,;\n\
             ;       ;\%;  \%\%;        ,     \%;    ;\%;    ,\%'\n\
              \%;       \%;\%;      ,  ;       \%;  ;\%;   ,\%;' \n\
               ;\%;      \%;        ;\%;        \% ;\%;  ,\%;'\n\
                `\%;.     ;\%;     \%;'         `;\%\%;.\%;'\n\
                 `:;\%.    ;\%\%. \%@;        \%; ;@\%;\%'\n\
                    `:\%;.  :;bd\%;          \%;@\%;'\n\
                      `@\%:.  :;\%.         ;@@\%;'   \n\
                        `@\%.  `;@\%.      ;@@\%;         \n\
                          `@\%\%. `@\%\%    ;@@\%;        \n\
                            ;@\%. :@\%\%  \%@@\%;       \n\
                              \%@bd\%\%\%bd\%\%:;     \n\
                                #@\%\%\%\%\%:;;\n\
                                \%@@\%\%\%::;\n\
                                \%@@@\%(o);  . '         \n\
                                \%@@@o\%;:(.,'         \n\
                            `.. \%@@@o\%::;         \n\
                               `)@@@o\%::;         \n\
                                \%@@(o)::;        \n\
                               .\%@@@@\%::;         \n\
                               ;\%@@@@\%::;.          \n\
                              ;\%@@@@\%\%:;;;. \n\
                          ...;\%@@@@@\%\%:;;;;,..\n"

#endif
