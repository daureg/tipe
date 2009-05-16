#include "app.h"

int main(int argc, char *argv[])
{
	Conf c = Conf();
	App a = App(&c);
	a.Run();
	return EXIT_SUCCESS;
}
