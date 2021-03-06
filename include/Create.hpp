#ifndef COMPONENT_HPP_
# define COMPONENT_HPP_

# include <functional>
# include <map>

# include "IComponent.hpp"

# include "Input.hpp"
# include "True.hpp"
# include "False.hpp"
# include "Clock.hpp"

# include "c4001.hpp"
# include "c4008.hpp"
# include "c4011.hpp"
# include "c4013.hpp"
# include "c4017.hpp"
# include "c4030.hpp"
# include "c4040.hpp"
# include "c4069.hpp"
# include "c4071.hpp"
# include "c4081.hpp"
# include "c4514.hpp"

# include "Output.hpp"

class Create
{
public:
    static nts::IComponent * createComponent(const std::string &type, const std::string &value = "");
};

#endif