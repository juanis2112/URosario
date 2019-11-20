#include<iostream>
#include<vector>
#include<random>
#include "bheap.hpp"

int main(){
    
    const short min = 65, max = 90, dim = 13;
    std::random_device rd;
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<int> distribution(min,max);
    
    std::vector<char> *vech = new std::vector<char>();
    for (unsigned i = 0; i < dim; i++){
        char ch = distribution(generator);
        vech -> push_back(ch);
        std::cout<< "Insertion of " << i+1 << " " << ch << std::endl;
    }
    BinaryHeap<char> hp(*vech);
    std::cout<< "Extreme " << hp.findMin() << " element\n";
    hp.display();
    
    for (unsigned i = 0; i <= dim; i++){
        if (hp.isEmpty()) continue;
        std::cout<< "Extreme " << hp.findMin() << " element\n";
        hp.deleteMin();
    }
    hp.display();

    std:: cout << "--------------------------------------\n";

    BinaryHeap<char> bin_ch;
    for (unsigned i = 0; i < 2*dim; i++)
        bin_ch.insert(distribution(generator));
    bin_ch.display();

    return 0;
}
