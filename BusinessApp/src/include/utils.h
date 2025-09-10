#ifndef UTILS_H
#define UTILS_H

#include "Business.h"
#include <vector>
#include <memory>

using BusinessList = std::vector<std::shared_ptr<Business>>;

void listBusinesses(const BusinessList& businessList, bool sorted = false);
std::shared_ptr<Business> findBusiness(BusinessList& businessList, const std::string& name);
void removeBusiness(BusinessList& businessList, const std::string& name);

#endif
