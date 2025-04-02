#include <iostream>
#include "clsLoginScreen.h"

void Start()
{
	while (true && clsLoginScreen::ShowLoginScreen())
		;
}

int main()
{
	Start();

	return 0;
}
