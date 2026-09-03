#include "RecommendationEngine.h"

#include <algorithm>

int RecommendationEngine::calculateScore(
    const std::string& category,
    const std::string& level,
    const std::vector<std::string>& tags,
    const UserProfile& user
) const
{
    int score = 0;

    if (category == user.getPreferredCategory())
    {
        score += 40;
    }

    if (level == user.getPreferredLevel())
    {
        score += 25;
    }

    for (const std::string& interest : user.getInterests())
    {
        for (const std::string& tag : tags)
        {
            if (interest == tag)
            {
                score += 15;
            }
        }
    }

    return score;
}

std::vector<BookRecommendation> RecommendationEngine::recommendBooks(
    const std::vector<Book>& books,
    const UserProfile& user,
    int limit
) const
{
    std::vector<BookRecommendation> results;

    for (const Book& book : books)
    {
        int score = calculateScore(
            book.getCategory(),
            book.getLevel(),
            book.getTags(),
            user
        );

        results.push_back({ book, score });
    }

    std::sort(
        results.begin(),
        results.end(),
        [](const BookRecommendation& a, const BookRecommendation& b)
        {
            return a.score > b.score;
        }
    );

    if (static_cast<int>(results.size()) > limit)
    {
        results.erase(results.begin() + limit, results.end());
    }

    return results;
}

std::vector<ScholarRecommendation> RecommendationEngine::recommendScholars(
    const std::vector<Scholar>& scholars,
    const UserProfile& user,
    int limit
) const
{
    std::vector<ScholarRecommendation> results;

    for (const Scholar& scholar : scholars)
    {
        int score = calculateScore(
            scholar.getField(),
            scholar.getLevel(),
            scholar.getTags(),
            user
        );

        results.push_back({ scholar, score });
    }

    std::sort(
        results.begin(),
        results.end(),
        [](const ScholarRecommendation& a, const ScholarRecommendation& b)
        {
            return a.score > b.score;
        }
    );

    if (static_cast<int>(results.size()) > limit)
    {
        results.erase(results.begin() + limit, results.end());
    }

    return results;
}

std::vector<ReciterRecommendation> RecommendationEngine::recommendReciters(
    const std::vector<Reciter>& reciters,
    const UserProfile& user,
    int limit
) const
{
    std::vector<ReciterRecommendation> results;

    // Reciters are only relevant when the user is interested in Quran.
    if (user.getPreferredCategory() != "Quran")
    {
        return results;
    }

    for (const Reciter& reciter : reciters)
    {
        int score = 40; // Quran category match

        for (const std::string& interest : user.getInterests())
        {
            for (const std::string& tag : reciter.getTags())
            {
                if (interest == tag)
                {
                    score += 20;
                }
            }
        }

        results.push_back({ reciter, score });
    }

    std::sort(
        results.begin(),
        results.end(),
        [](const ReciterRecommendation& a, const ReciterRecommendation& b)
        {
            return a.score > b.score;
        }
    );

    if (static_cast<int>(results.size()) > limit)
    {
        results.erase(results.begin() + limit, results.end());
    }

    return results;
}