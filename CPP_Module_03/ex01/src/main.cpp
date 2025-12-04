
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) 
{
	ClapTrap a("Junch");
	ScavTrap b("Sunch");
	
	a.Attack("Sunch");
	b.TakeDamage(20);
	a.BeRepaired(4);
	
	b.Attack("Junch");
	a.TakeDamage(20);
	b.BeRepaired(11);
	
	b.GuardGate();

	a.Status();
	b.Status();
	return 0;
}