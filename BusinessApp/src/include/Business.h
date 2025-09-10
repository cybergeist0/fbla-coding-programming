#ifndef BUSINESS_H
#define BUSINESS_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class Business {
public:
    Business(std::string name);

    std::string getName() const;
    double getRating() const;

    void addRating(double providedRating);
    void addReview(std::string review);
    void addReview(std::string review, int providedRating);

    void updateDeals(std::string newDeal);
    void removeDeal(std::string currDeal);

    void getReviews() const;
    void getDeals() const;

private:
    std::string name;
    double totalRating;
    int ratingsProvided;
    std::vector<std::string> reviews;
    std::vector<std::string> deals;
};

#endif
