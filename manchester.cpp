#include <iostream>
#include <ctype.h>
using namespace std;
int main(){
    
    int n, bit;
    int bitstream[50];
    cout << "Assumption : 0 -> +ve and 1 -> -ve" << endl;
    cout << "Enter the number of Bits (as pairs) : ";
    
    cin >> n;
    cout << "Enter the Bitstream : ";
    
    for (int i = 0; i < n; i++) cin >> bitstream[i];

    cout << "Enter Previous Bit : ";
    cin >> bit;

    cout << "Manchester Encoding : ";
    for (int i = 0; i < n; i++){
        if (bitstream[i] == 0) cout << "01 ";
        if (bitstream[i] == 1) cout << "10 ";
    }

    cout << endl << "Differential Manchester Encoding : ";
    for (int i = 0; i < n; i++){
        if (bitstream[i] == 0){
            if (bit == 0){
                cout << "10 ";
                bit = 0;
            }

            else{
                cout << "01 ";
                bit = 1;
            }
        }

        else if (bit == 0){
            cout << "01 ";
            bit = 1;
        }

        else{
            cout << "10 ";
            bit = 0;
        }
    }

    return 0;
}
