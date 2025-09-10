#include "include/Business.h"
#include <stdexcept>
#include <algorithm>

Business::Business(std::string name) 
    : name(std::move(name)), totalRating(0), ratingsProvided(0) {}

std::string Business::getName() const { return name; }

double Business::getRating() const {
    if (ratingsProvided == 0) {
        return 0.0;
    }
    return totalRating / ratingsProvided;
}

void Business::addRating(double providedRating) {
    if (providedRating >= 0 && providedRating <= 5) {
        totalRating += providedRating;
        ratingsProvided++;
    } else {
        throw std::runtime_error("Rating must be between 0 to 5");
    }
}

void Business::addReview(std::string review) {
    reviews.push_back(std::move(review));
}

void Business::addReview(std::string review, int providedRating) {
    addRating(providedRating);
    addReview(std::move(review));
}

void Business::updateDeals(std::string newDeal) {
    if (std::find(deals.begin(), deals.end(), newDeal) == deals.end()) {
        deals.push_back(std::move(newDeal));
    }
}

void Business::removeDeal(std::string currDeal) {
    deals.erase(std::remove(deals.begin(), deals.end(), currDeal), deals.end());
}

void Business::getReviews() const {
    if (reviews.empty()) {
        std::cout << "No reviews available for " << name << "." << std::endl;
        return;
    }
    std::cout << "Reviews for " << name << ":" << std::endl;
    for (const auto& review : reviews) {
        std::cout << "- " << review << std::endl;
    }
}

void Business::getDeals() const {
    if (deals.empty()) {
        std::cout << "No deals available for " << name << "." << std::endl;
        return;
    }
    std::cout << "Deals for " << name << ":" << std::endl;
    for (const auto& deal : deals) {
        std::cout << "- " << deal << std::endl;
    }
}
