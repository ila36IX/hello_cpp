#include "ScavTrap.h"

int main()
{
        ScavTrap st("Jimmy");
        ScavTrap Now = st;

        st.attack("other");
        st.beRepaired(123);
        st.guardGate();
}
