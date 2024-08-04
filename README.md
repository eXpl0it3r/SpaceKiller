# Space Killer

**Space Killer** will make sure that your space bar key is being properly destroyed. Can you beat your high-score before your keyboard falls apart?!

This is an entry to the first [Hopson](https://www.youtube.com/channel/UCeQhZOvNKSBRU0Mdg7V44wA) game jam with the theme 'Space'. The game idea itself originates from a silly Visual Basic application I wrote like 15+ years ago - good old times.

![Space Killer](https://i.imgur.com/kSp7lX7.png)

## Instructions

- Press `space` to begin
- Press `space` to increase the counter
- Get the highest score before the timer runs out
- Press `ESC` to reset the game

## Building

Use CMake to build Space Killer and it will automatically build SFML for you!

```
cmake -S . -B build
cmake --build build
```

- `main.cpp` holds all the game logic
- `TenStamps.hpp` holds the embedded data of the font [TenStamps](https://www.pentacom.jp/pentacom/bitfontmaker2/gallery/?id=329) by Geoff
- `Icon.hpp` hold the embedded data of the window icon

## Tools & Libraries

- [SFML](https://www.sfml-dev.org/) - Window and graphics rendering
- [PhotoFiltre 7](https://www.photofiltre-studio.com/pf7-en.htm) - Creating the window icon
- [Visual Studio 2022](https://visualstudio.microsoft.com/) - Code editing
- [xxd](https://manpages.debian.org/testing/xxd/xxd.1.en.html) - Converting the binary data to a C array
