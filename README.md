# Kahút for the Sony PlayStation®

A homebrew Kahoot clone for the Sony PlayStation®. Made for my French homework.

[For more information (including gameplay instructions), please visit my blog post about this project.](https://blog.prochazka.ml/index.php/article/kahut-psx)

## How to add custom questions

Go into `Questions.h`. The first 15 questions are for the first round, while the rest (set `NUM_OF_QUESTIONS` to the total number of questions, including those for the first round) are for the second round (15 by default + 15 from the first round, which will repeat if necessary).

Each entry in the `questions` array contains the following fields:

- `.qtext` = first line of question text
- `.qtext2` = second line of question text
- `.ans` = array of 4 answers (the first one is correct, all answers are shuffled at runtime)

## Language selection

To change the game's language, go into `MAIN.C` and edit the following line:

```C
#include "l10n/French.h"
```

to whatever you like. See the [l10n](https://github.com/prochazkaml/KahutPSX/tree/master/l10n) directory to see which translation files are available.

## Build instructions

To build Kahút, you will need a Linux system with the PsyQ toolchain, as described [in my guide](https://blog.prochazka.ml/index.php/article/psyq-modern-linux). After you've done that, all you need to do is to run the following in the terminal:

```
./make.sh
```

This will bundle all of the required assets into a header file, compile the code, generate a CUE/BIN and run the game in Mednafen. If it was successful, you should see your game booting without any additional commands!

## I don't want to deal with building, I just want to play!

If you want to take part in a quiz on the topic of francophony (and don't mind that the whole game is in French), you can just [grab the pre-compiled release](https://github.com/prochazkaml/KahutPSX/releases).
