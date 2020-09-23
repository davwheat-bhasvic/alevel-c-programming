#include <stdio.h>
#include <ctype.h>


int main() {
    int landAnimal = 1, carnivore = 0;

    printf("Does the animal almost always remain on land? (0 or 1)");
    scanf(" %d", &landAnimal);

    if (tolower(landAnimal) == 'y') {

    }

    return 0;
}
