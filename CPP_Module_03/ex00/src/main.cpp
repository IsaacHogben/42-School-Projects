
#include "ClapTrap.hpp"

int main( void ) 
{
	ClapTrap a("Juncle");
	ClapTrap b("Soop");
	
	a.Attack("Soop");
	a.BeRepaired(4);
	a.TakeDamage(6);
	b.Attack("Juncle");
	b.BeRepaired(11);
	b.TakeDamage(20);

	a.Status();
	b.Status();
	return 0;
}