#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 512
#define MAX_WORD_COUNT 512

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int isVowel(char c) {
  if (isalpha(c) && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
    return 1;
  }

  return 0;
}

int isConsonant(char c) {
  if (isalpha(c) && !isVowel(c)) {
    return 1;
  }

  return 0;
}

// Only used in debugging
int printArray(char* arr, int length) {
  for (int i = 0; i < length; i++) {
    // stop reading at null byte
    if (arr[i] == '\0')
      break;
    printf("%c ", arr[i]);
  }

  printf("\n");

  return 0;
}

int splitSentenceIntoWords(char sentence[],
                           int sentenceLength,
                           char words[MAX_STRING_LENGTH][MAX_WORD_COUNT]) {
  int wordCount = 0;
  int wordIndex = 0;

  for (int charIndex = 0; charIndex < sentenceLength; charIndex++) {
    if (sentence[charIndex] == '\0') {
      // end of sentence -- we can stop now
      // i apologise in advance for this break, but i like it :)
      break;
    }

    if (isalpha(sentence[charIndex])) {
      // adds char onto end of word array
      words[wordCount][wordIndex] = sentence[charIndex];
      wordIndex++;
    } else {
      // end of word
      wordCount++;
      // adds null byte to end of word (so it's a proper C string)
      words[wordCount][wordIndex] = '\0';
      wordIndex = 0;
    }
  }

  return wordCount;
}

int shiftAllCharsLeft(char* array, int length, int shiftBy) {
  // shift all chars by 'shiftBy'
  for (int i = shiftBy; i < length; i++) {
    array[i - shiftBy] = array[i];
  }

  // add null terminator
  array[length] = '\0';

  return 0;
}

int main() {
  char input[MAX_STRING_LENGTH] = {'\0'};

  printf("Enter some text to convert to pig latin:\n");
  fgets(input, MAX_STRING_LENGTH, stdin);

  char inputWords[MAX_STRING_LENGTH][MAX_WORD_COUNT];

  int wordCount = splitSentenceIntoWords(input, ARRAY_SIZE(input), inputWords);

  for (int wordNum = 0; wordNum < wordCount; wordNum++) {
    char* thisWord = inputWords[wordNum];
    int wordLength = 0;

    for (int i = 0; i < MAX_STRING_LENGTH; i++) {
      if (thisWord[i] == '\0') {
        wordLength = i + 1;
        break;
      }
    }

    if (isConsonant(thisWord[0])) {
      // multiple consonants at start of word.
      // move all consonants until first vowel to back
      int firstVowelAt = -1;

      for (int i = 0; i < wordLength; i++) {
        if (isVowel(thisWord[i])) {
          firstVowelAt = i;
          break;
        }
      }

      if (firstVowelAt != -1) {
        // move all chars up to first vowel to back
        for (int i = 0; i < firstVowelAt; i++) {
          thisWord[wordLength - 1 + i] = thisWord[i];
        }

        thisWord[wordLength + firstVowelAt - 1] = 'a';
        thisWord[wordLength + firstVowelAt] = 'y';
        thisWord[wordLength + firstVowelAt + 1] = '\0';

        shiftAllCharsLeft(thisWord, wordLength + firstVowelAt + 2, firstVowelAt);

        //                printf("%s\n", thisWord);
      } else {
        // if no vowel, we assume that we should just add 'ay'
        // putting entire string to back and shifting it is just
        // a waste of resources as it ends up exactly how it started
        thisWord[wordLength - 1] = 'a';
        thisWord[wordLength] = 'y';
        thisWord[wordLength + 1] = '\0';

        //                printf("%s\n", thisWord);
      }
    } else {
      // first letter is vowel: leave and add 'ay'
      thisWord[wordLength - 1] = 'a';
      thisWord[wordLength] = 'y';
      thisWord[wordLength + 1] = '\0';

      //            printf("%s\n", thisWord);
    }
  }

  for (int word = 0; word < wordCount; word++) {
    printf("%s ", inputWords[word]);
  }

  return 0;
}
