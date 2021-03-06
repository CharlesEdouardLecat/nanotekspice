#ifndef OUTPUT_HPP_
# define OUTPUT_HPP_

# include "AComponent.hpp"

namespace nts
{
    class Output : public AComponent
    {
    public:
        Output(const std::string & = "");
        virtual nts::Tristate Compute(std::size_t pin_num_this = 1);
        virtual void SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
        virtual void Dump(void) const;
        virtual ~Output(void);
        virtual const std::string &save() const;
    };
}

#endif