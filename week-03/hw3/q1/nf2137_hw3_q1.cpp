#include <iostream>

int main() {
    float priceItem1, priceItem2, taxRate, basePrice, discountedPrice;
    float discountRate = 0;
    char clubCard;

    std::cout << "Please enter price of first item:" << std::endl;
    std::cin >> priceItem1;
    std::cout << "Please enter price of second item:" << std::endl;
    std::cin >> priceItem2;

    std::cout << "Does customer have a club card? (Y/N):" << std::endl;
    std::cin >> clubCard;

    std::cout << "Enter tax rate, e.g. 5.5 or 5.5% tax:" << std::endl;
    std::cin >> taxRate;

    if (clubCard == 'y' || clubCard == 'Y'){
        discountRate = 0.10;
    }

    basePrice = priceItem1 + priceItem2;
    std::cout << "Base price: " << basePrice << std::endl;

    float regularItemPrice = priceItem1 < priceItem2 ? priceItem2 : priceItem1;
    float discountedItemPrice = priceItem1 < priceItem2 ? priceItem1 / 2 : priceItem2 / 2;

    discountedPrice = (regularItemPrice + discountedItemPrice) - ((regularItemPrice + discountedItemPrice) * discountRate);
    std::cout << "Price after discounts: " << discountedPrice << std::endl;

    std::cout << "Total price: " << discountedPrice + (taxRate / 100 * discountedPrice) << std::endl;
    return 0;
}
