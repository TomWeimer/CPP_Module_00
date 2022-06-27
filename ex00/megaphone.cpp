// Copyright 2022 Tom Weimer

#include <iostream>
#include <cstring>

// print string
void    print(const char *message) {
    std::cout << message;
}

// change lowercase into uppercase
void    Uppercase(int argc, char *argv[]) {
    for (int i = 1; i < argc ; i++) {
        for (size_t j = 0; j < std::strlen(argv[i]); j++)
            argv[i][j] = std::toupper(argv[i][j]);
        print(argv[i]);
    }
}

// If there is more than one arguments put them in uppercase
int    main(int argc, char *argv[]) {
    if (argc == 1)
        print("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
    else if (argc > 1)
        Uppercase(argc, argv);
    print("\n");
}
