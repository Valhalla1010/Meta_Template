#include <iostream>





// Templaterad struktur för att beräkna exponentier vid compile time
template<int N , bool E = N < 0>
struct Exp;

// Specialisering för fall där exponenten är negativ
template<int N>
struct Exp<N, true>{
    static double pow(double base){// medlemsfunktion
        return 1.0 / Exp<-N>::pow(base); //för beräkna negative exponent
    }
};

// Specialisering för fall där exponenten är positiv eller noll
template<int N>
struct  Exp<N, false>{
    static double pow (double base){
        return base * Exp<N - 1>::pow(base);
    }
};



template<>
struct Exp<0>{
    static double pow(double base){
        return 1.0; // x^0 = 1
    }
};



int main(){
    double result = Exp<2>::pow(5);
    std::cout << result << std::endl;

    result = Exp<0>::pow(5);
    std::cout << result << std::endl;
}





