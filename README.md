# Islamic Knowledge Recommendation Engine

A C++ console application that recommends Islamic books, scholars, and Quran reciters based on a user's interests and study level.

## Features

- Personalized recommendations
- Weighted recommendation scoring
- Ranking and sorting
- Books, scholars, and Quran reciters
- Object-Oriented C++ design
- Encapsulation with private class data
- Modular `.h` / `.cpp` architecture

## Recommendation Model

The engine currently uses a simple weighted scoring system:

- Category match: `+40`
- Level match: `+25`
- Interest/tag match: `+15`
- Quran reciter interest match: `+20`

The system sorts candidates by score and returns the top recommendations.

## Project Structure

```text
include/
    Book.h
    Scholar.h
    Reciter.h
    UserProfile.h
    RecommendationEngine.h

src/
    Book.cpp
    Scholar.cpp
    Reciter.cpp
    UserProfile.cpp
    RecommendationEngine.cpp
    main.cpp

data/
tests/
docs/
screenshots/
```

## Technologies

- C++
- Object-Oriented Programming
- STL
- `std::vector`
- `std::sort`
- Console UI

## Build

Open the Visual Studio solution and build the project with:

`Ctrl + Shift + B`

Then run with:

`Ctrl + F5`

## Portfolio Notes

This project is intentionally built without external recommendation or AI libraries. The ranking logic is implemented manually so the code demonstrates data structures, algorithms, and software design fundamentals.

## Disclaimer

The content dataset is a small educational sample. Recommendations are generated from metadata and user-selected preferences; the application does not make scholarly judgments about the correctness or authority of any work.
