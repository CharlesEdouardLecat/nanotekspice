#include "c4030.hpp"

namespace nts
{
    c4030::c4030(const std::string &)
    {
        this->name = "4030";
        this->type = nts::AComponent::Type::C;
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::VSS});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::O});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::I});
        this->pins.push_back(Pin{nts::Pin::VDD});
    }

    nts::Tristate c4030::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this == 0)
            return (this->reset_pins());
        if (pin_num_this < 1 || pin_num_this > 13 || pin_num_this == 7)
            throw Error ("Attempt to compute an invalid pin number", this->name + " " + std::to_string(pin_num_this));
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        else
        {
            Tristate t1 = this->pins[pin_num_this + ((pin_num_this == 2 || pin_num_this == 9) ? (-1) : (1))].compute();
            Tristate t2 = this->pins[pin_num_this + ((pin_num_this == 2 || pin_num_this == 9) ? (-2) : (2))].compute();
            if (t1 == UNDEFINED || t2 == UNDEFINED)
                return (UNDEFINED);
            return ((t1 || t2) && !(t1 && t2));
        }
    }

    void c4030::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 13 || pin_num_this == 7)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4030::Dump(void) const
    {
        std::cout << "Chipset " << this->name << std::endl;
    }

    const std::string &c4030::save() const
    {
        return (*(new std::string ("4030 " + this->name)));
    }

    c4030::~c4030(void)
    {
    }
}