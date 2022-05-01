#include <iostream>
using namespace std;

void	print(const char *message)
{
	cout << message;
}

void	Uppercase(int argc, char *argv[])
{
	for (int i = 1; i < argc ; i++)
	{
			for (size_t j = 0; j < strlen(argv[i]); j++)
				argv[i][j] = toupper(argv[i][j]);
			print(argv[i]);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		print("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	else if (argc > 1)
	{
		Uppercase(argc, argv);
	}
	print("\n");
}
