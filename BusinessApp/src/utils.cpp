#include "include/utils.h"
#include <algorithm>
#include <iostream>

void listBusinesses(const BusinessList& businessList, bool sorted) {
    if (businessList.empty()) {
        std::cout << "No businesses to list." << std::endl;
        return;
    }

    if (sorted) {
        std::vector<std::shared_ptr<Business>> tempVec = businessList;
        std::sort(tempVec.begin(), tempVec.end(),
            [](const std::shared_ptr<Business>& a, const std::shared_ptr<Business>& b) {
                return a->getRating() > b->getRating();
            });

        for (const auto& business : tempVec) {
            std::cout << "Name: " << business->getName()
                      << ", Rating: " << business->getRating() << std::endl;
        }
    } else {
        for (const auto& business : businessList) {
            std::cout << "Name: " << business->getName()
                      << ", Rating: " << business->getRating() << std::endl;
        }
    }
}

std::shared_ptr<Business> findBusiness(BusinessList& businessList, const std::string& name) {
    auto it = std::find_if(businessList.begin(), businessList.end(),
        [&](const std::shared_ptr<Business>& b) { return b->getName() == name; });
    if (it != businessList.end()) {
        return *it;
    }
    return nullptr;
}

void removeBusiness(BusinessList& businessList, const std::string& name) {
    businessList.erase(
        std::remove_if(businessList.begin(), businessList.end(),
                       [&](const std::shared_ptr<Business>& b) { return b->getName() == name; }),
        businessList.end());
}
