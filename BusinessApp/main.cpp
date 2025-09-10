#include "src/include/Business.h"
#include "src/include/utils.h"
#include <iostream>

using namespace std;

int main() {
    BusinessList businesses;
    BusinessList bookmarks;

    while (true) {
        string operation;
        cin >> operation;

        if (operation == "add") {
            string businessName;
            cin >> businessName;
            businesses.push_back(make_shared<Business>(businessName));
        } else if (operation == "remove") {
            string type, businessName;
            cin >> type >> businessName;
            if (type == "business") {
                removeBusiness(businesses, businessName);
            } else if (type == "bookmark") {
                removeBusiness(bookmarks, businessName);
            }
        } else if (operation == "bookmark") {
            string businessName;
            cin >> businessName;
            auto b = findBusiness(businesses, businessName);
            if (b) bookmarks.push_back(b);
        } else if (operation == "rate") {
            string businessName;
            double rating;
            cin >> businessName >> rating;
            auto b = findBusiness(businesses, businessName);
            if (b) b->addRating(rating);
        } else if (operation == "review") {
            string businessName;
            cin >> businessName;
            string review;
            cin.ignore();
            getline(cin, review);
            auto b = findBusiness(businesses, businessName);
            if (b) b->addReview(review);
        } else if (operation == "list") {
            string type;
            cin >> type;
            if (type == "all") {
                cout << "--- All Businesses ---" << endl;
                listBusinesses(businesses);
            } else if (type == "bookmarks") {
                cout << "--- Bookmarked Businesses ---" << endl;
                listBusinesses(bookmarks);
            } else if (type == "all_sorted") {
                cout << "--- All Businesses (Sorted by Rating) ---" << endl;
                listBusinesses(businesses, true);
            } else if (type == "bookmarks_sorted") {
                cout << "--- Bookmarked Businesses (Sorted by Rating) ---" << endl;
                listBusinesses(bookmarks, true);
            }
        } else if (operation == "reviews") {
            string businessName;
            cin >> businessName;
            auto b = findBusiness(businesses, businessName);
            if (b) {
                b->getReviews();
            } else {
                cout << "Business not found." << endl;
            }
        } else if (operation == "exit") {
            break;
        } else {
            cout << "Invalid operation." << endl;
        }
    }

    return 0;
}
