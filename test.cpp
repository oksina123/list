#include <iostream>
#include <exception>
#include "lista.hpp"
using namespace std;


int main(int argc, char* argv[]) {
    Lista<int> lista;

    lista.push(123518);
    lista.push(37109);
    lista.push(209421);
    try {
        cout << lista.get(0) << " " << lista.get(1) << " "<< lista.get(2)<<std::endl;
    } catch (std::exception e) {
        cout << "zly indeks";
    }
    lista.remove(209421);

    std::cout<<"lista.contains(209421)->"<<(lista.contains(209421)? "true" : "false")<< std::endl;
    std::cout<< "lista.contains(123518) -> " << (lista.contains(123518) ? "true" : "false") << std::endl;
    std::cout<< "lista.contains(4) ->" << (lista.contains(4) ?  "true":"false")<<std::endl;
    std::cout<<lista.size();



 // a ? b : c
 // a=true -> b
 // a=fale -> c
}