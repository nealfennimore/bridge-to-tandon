#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <vector>
using std::vector;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);
bool isAmicable(int a, int b);

int main() {
    int n;
    std::cout << "Give an integer >= 2: " << std::endl;
    std::cin >> n;

    std::vector<int> range(n);
    std::iota (std::begin(range), std::end(range), 2);

    vector<int> perfectList;
    vector<int> amicableList;

    for (int i = 0; i < range.size(); ++i) {
        int num = range[i];
        if(isPerfect(num)){
            perfectList.push_back(num);
        }
        if (isAmicable(range[i], n)) {
            amicableList.push_back(range[i]);
            amicableList.push_back(n);
        }
    }
    
    std::cout << "Perfect numbers: ";
    for (int k = 0; k < perfectList.size(); ++k) {
        std::cout << perfectList[k] << " ";
    }
    std::cout << std::endl;

    std::cout << "Amicable numbers: ";
    for (int l = 0; l < amicableList.size(); ++l) {
        std::cout << amicableList[l] << " ";
    }
    std::cout << std::endl;

    return 0;
}


void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) {
            outSumDivs += i;
            outCountDivs++;

            if (num / i != i) {
                outSumDivs += num / i;
                outCountDivs++;
            }
        }
    }

    outSumDivs++;
    outCountDivs++;
}

bool isPerfect(int num) {
    int outCountDivs = 0;
    int outSumDivs = 0;

    analyzeDivisors(num, outCountDivs, outSumDivs);

    return outSumDivs == num;
}

bool isAmicable(int a, int b)
{
    int aCount = 0;
    int aSum = 0;

    analyzeDivisors(a, aCount, aSum);

    int bCount = 0;
    int bSum = 0;

    analyzeDivisors(b, bCount, bSum);

    return (aSum == b && bSum == a);
}