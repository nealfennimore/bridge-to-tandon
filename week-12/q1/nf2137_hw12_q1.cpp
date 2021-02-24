#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int digit_to_int(char c);

class Money{
    public:
        friend Money operator +(const Money & amount1, const Money & amount2);
        friend Money operator -(const Money & amount1, const Money & amount2);
        friend Money operator -(const Money & amount);
        friend bool operator ==(const Money & amount1, const Money & amount2);
        friend bool operator <(const Money & amount1, const Money & amount2);
//        Money(long dollars, int cents);
//        Money(long dollars);
        Money();
        double get_value() const;
        friend istream & operator >>(istream & input, Money & amount);
        friend ostream & operator <<(ostream & output, const Money & amount);

    private:
        long all_cents;
};

Money operator -(const Money & amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

Money operator -(const Money & amount1, const Money & amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator +(const Money & amount1, const Money & amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money & amount1, const Money & amount2){
    return (amount1.all_cents == amount2.all_cents);
}

bool operator <(const Money & amount1, const Money & amount2){
    return (amount1.all_cents < amount2.all_cents);
}

int digit_to_int(char c){
    return static_cast<int>(c) - static_cast<int>('0');
}

istream & operator >>(istream & input, Money & amount){
    char one_char, decimal, d1, d2;
    long dollars;
    int cents;
    bool negative;
    input >> one_char;

    if(one_char == '-'){
        negative = true;
        input >> one_char;
    } else {
        negative = false;
    }

    input >> dollars >> decimal >> d1 >> d2;

    if(one_char != '$' || decimal != '.' || !isdigit(d1) || !isdigit(d2)){
        cout << "The input is not valid.";
        exit(1);
    }

    cents = digit_to_int(d1) * 10 + digit_to_int(d2);
    amount.all_cents = dollars * 100 + cents;

    if(negative){
        amount.all_cents = -amount.all_cents;
    }

    return input;
}


ostream & operator <<(ostream & output, const Money & amount){

    long positive_cents, dollars, cents;

    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if( amount.all_cents < 0 ){
        output << "-$" << dollars << '.';
    } else {
        output << "$" << dollars << ".";
    }

    if( cents < 10 ){
        output << '0';
    }

    output << cents;

    return output;
}

//Money::Money(long dollars, int cents){
//    if(dollars*cents < 0){
//        cout << "Invalid input for dollars and cents." << endl;
//        exit(1);
//    }
//    all_cents = dollars * 100 + cents;
//}

//Money::Money(long dollars) : all_cents(dollars * 100){}
Money::Money() : all_cents(0) {}

double Money::get_value() const{
    return (all_cents*0.01);
}

class Check{
    public:
        Check();
//        Check(string chkNo, Money amount, bool cashed);
        void setNumber(string number);
        void setAmount(Money amount);
        void setCashed(bool cashed);
        string getNumber();
        Money getAmount();
        bool getCashed();

        friend istream & operator >>(istream & input, Check & chk);
        friend ostream & operator <<(ostream & output, const Check & chkInfo);

    private:
        string number;
        Money amount;
        bool cashed;


};

Check::Check() : number(""), amount(), cashed(false) {}
//Check::Check(string number, Money amount, bool cashed){
//    this->number = number;
//    this->amount = amount;
//    this->cashed = cashed;
//}

void Check::setNumber(string number){
    this->number = number;
}

void Check::setAmount(Money amount){
    this->amount = amount;
}

void Check::setCashed(bool cashed){
    this->cashed = cashed;
}

string Check::getNumber(){
    return this->number;
}

Money Check::getAmount(){
    return this->amount;
}

bool Check::getCashed(){
    return this->cashed;
}


istream & operator >>(istream & input, Check & chk){
    int cashed;
    string number;
    Money amount;

    while( !(input >> amount) || !(input >> cashed) || !(input >> number) ){
        input.clear();
        cin.ignore(80,'\n');
        cout << "Invalid input for check." << endl;
    }

    cin.ignore(80,'\n');
    chk.setNumber(number);
    chk.setAmount(amount);
    chk.setCashed(cashed);

    return input;
}


ostream & operator <<(ostream & output, Check & check){
    output << "Check no: " << check.getNumber() << ", Amount: " << check.getAmount() << ", ";
    if ( check.getCashed() ){
        output << "Cashed";
    } else {
        output << "Not Cashed";
    }
    return output;
}

int main() {
    const int size = 10;
    Check checks[size];
    int count = 0;
    double initBal, deposit, checkAmounts = 0, depositAmounts = 0, checkCashedAmounts = 0;

    double deposits[size];
    char ans;
    vector<string> uncashedChecks, cashedChecks;

    cout << "Enter the initial account balance: ";
    cin >> initBal;

    cout << "Enter deposit amount (max 5, -1 to stop):" <<endl;
    cin >> deposit;

    while(deposit != -1  && count < size){
        deposits[count] = deposit;
        count++;
        cin >> deposit;
    }

    for(int i = 0; i < count; i++){
        initBal = initBal + deposits[i];
        depositAmounts = depositAmounts + deposits[i];
    }

    count = 0;

    do{
        cout << "Enter check details (number amount if cashed or not (using 1:cashed, 0: not cashed)): "<< endl;
        cin >> checks[count];
        cout << "Would you like to enter another checks details? (y/n): ";
        cin >> ans;
        count++;
    }while( ans == 'y' || ans == 'Y');

    for(int i = 0; i < size; i++){
        double value = (checks[i].getAmount()).get_value();
        if(checks[i].getCashed()){
            initBal = initBal - value;
            checkCashedAmounts += value;
            cashedChecks.push_back(checks[i].getNumber());
        }else{
            if(checks[i].getNumber() != ""){
                uncashedChecks.push_back(checks[i].getNumber());
            }
        }
        checkAmounts += value;
    }

    sort(uncashedChecks.begin(), uncashedChecks.end());
    sort(cashedChecks.begin(), cashedChecks.end());

    cout << "\nThe final balance is: $" << initBal << endl;
    cout << "The total amount of all deposits made: $" << depositAmounts << endl;
    cout << "The total amount of all checks: $" << checkAmounts << endl;
    cout << "The total amount of all checks cashed: $" << checkCashedAmounts << endl;

    if(cashedChecks.size() > 0){
        cout << "The sorted list of cashed checks is: " << endl;
        for(int i = 0; i < cashedChecks.size(); i++){
            cout << cashedChecks[i] << "\t";
        }
        cout << endl;
    }

    if(uncashedChecks.size() > 0){
        cout << "The sorted list of uncashed checks is: " << endl;
        for(int i = 0; i < uncashedChecks.size(); i++){
            cout << uncashedChecks[i] << "\t";
        }
        cout << endl;
    }

    return 0;
}