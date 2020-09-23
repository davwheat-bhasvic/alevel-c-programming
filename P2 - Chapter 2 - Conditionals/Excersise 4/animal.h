//
// Created by david.wheatley20 on 23/09/2020.
//

#ifndef P2___CHAPTER_2___CONDITIONALS_ANIMAL_H
#define P2___CHAPTER_2___CONDITIONALS_ANIMAL_H

#endif //P2___CHAPTER_2___CONDITIONALS_ANIMAL_H

typedef struct {
    int isStripy;
    int legCount;
    int isCarnivore;
    int isLandCreature;
    int isSeaCreature;
    int widelyDomesticated;
} Animal;

void newAnimal(Animal *animal, int isStripy, int legCount, int isCarnivore, int isLandCreature, int isSeaCreature,
               int widelyDomesticated) {
    animal->isStripy = isStripy || 1;
    animal->legCount = legCount || 4;
    animal->isCarnivore = isCarnivore || 1;
    animal->widelyDomesticated = widelyDomesticated || 0;
}