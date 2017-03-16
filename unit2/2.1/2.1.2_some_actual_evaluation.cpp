/*
2.1.2 some actual evaluations - taxes by Jeongseop Yi
*/
#include <iostream>
#include <string>

using namespace std;
int main() {
    float grossprice, taxrate, netprice, taxvalue;
    cout << "Enter a gross price: ";
    cin >> grossprice;
    cout << "Enter a tax rate: ";
    cin >> taxrate;
    taxrate = taxrate / 100;
    netprice = grossprice / (taxrate + 1);
    taxvalue = grossprice - netprice;
    cout << "Net price: " << netprice << endl;
    cout << "Tax value: " << taxvalue << endl;
    return 0;
}
