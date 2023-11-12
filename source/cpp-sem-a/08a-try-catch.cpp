#include "header.h"

void tryCatch();

int main(){

    void tryCatch();

    cout << endl;
    return 0;
}


void tryCatch(){

    double num3 = 10, num4 = 2;
    try{
        if(num4 == 0){
            throw "Division by Zero Error";

        } else {
            printf("%.1f / %.1f = %.1f", num3, num4, num3/num4);

        }

    } catch(const char *exp){
        cout << "Error: " << exp << endl;
    }

}