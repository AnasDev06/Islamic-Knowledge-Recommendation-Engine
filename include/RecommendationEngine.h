#pragma once

#include "Book.h"
#include "Scholar.h"
#include "Reciter.h"
#include "UserProfile.h"

#include <vector>

struct BookRecommendation
{
    Book book;
    int score;
};

struct ScholarRecommendation
{
    Scholar scholar;
    int score;
};

struct ReciterRecommendation
{
    Reciter reciter;
    int score;
};

class RecommendationEngine
{
private:
    int calculateScore(
        const std::string& category,
        const std::string& level,
        const std::vector<std::string>& tags,
        const UserProfile& user
    ) const;

public:
    std::vector<BookRecommendation> recommendBooks(
        const std::vector<Book>& books,
        const UserProfile& user,
        int limit = 5
    ) const;

    std::vector<ScholarRecommendation> recommendScholars(
        const std::vector<Scholar>& scholars,
        const UserProfile& user,
        int limit = 5
    ) const;

    std::vector<ReciterRecommendation> recommendReciters(
        const std::vector<Reciter>& reciters,
        const UserProfile& user,
        int limit = 5
    ) const;
};
