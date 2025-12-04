
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) 
{
	ClapTrap a("Junch");
	ScavTrap b("Sunch");
	FragTrap c("Lunch");
	
	a.Attack("Sunch");
	b.TakeDamage(20);
	
	b.Attack("Junch");
	a.TakeDamage(20);
	
	c.Attack("Lunch");
	c.TakeDamage(20);
	
	a.BeRepaired(4);
	b.BeRepaired(11);
	c.BeRepaired(1);

	b.GuardGate();
	c.HighFiveGuys();

	a.Status();
	b.Status();
	c.Status();
	return 0;
}