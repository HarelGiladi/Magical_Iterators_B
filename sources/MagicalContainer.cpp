#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

//helper funaction for checking if a number is prime
bool isPrime(int num)  {
    if (num < 2){return false;}
    for (int i = 2; i <= sqrt(num); ++i) {if (num % i == 0){return false;}}
    return true;
}

//container get elem at index funaction
// int MagicalContainer::getElementAt(int index)const{
//     if(index < 0 || size() <=index){
//         throw out_of_range("INVALID INDEX");
//     }
//  return conElements.at(static_cast<std::vector<int>::size_type>(index)); 
// }



//container get the size funaction
int MagicalContainer::size() const {return conElements.size();}


//container delete elem funaction
void MagicalContainer::removeElement(int element) {
        //from the internet
        //first finding if there is a elem like this already
        std::vector<int>::iterator isFound = find(conElements.begin(), conElements.end(), element);
        
        //if there is a elem then del it else exception
        if (isFound != conElements.end()) {
            conElements.erase(isFound);
            
            //there is no need to sort because the order will not change
            //now we need to declare from the begining for prime on th container
            this->primesPointer.clear();
            for(int i=0;i<this->conElements.size();++i)
                if(isPrime(this->conElements[(vector<int>::size_type)i]))
                    this->primesPointer.push_back(&this->conElements[(vector<int>::size_type)i]);
        }
        else{throw runtime_error("ElEMENT IS NOT EXITS");}
    }


//container add elem funaction
void MagicalContainer::addElement(int element) {
    //from the internet
    //first finding if there is a elem like this already
    std::vector<int>::iterator isFound = find(conElements.begin(), conElements.end(), element);

    //if there is not, then add in the end
    if (isFound == conElements.end()) {
        this->conElements.push_back(element);
        //now we need to sort 
        sort(this->conElements.begin(),this->conElements.end());

        //now we need to declare from the begining for prime on th container
        this->primesPointer.clear();
        for(int i=0;i<this->conElements.size();++i)
            if(isPrime(this->conElements[(vector<int>::size_type)i]))
                this->primesPointer.push_back(&this->conElements[(vector<int>::size_type)i]);
    }
}




//sideCrossIterator oprators using each other
int MagicalContainer::SideCrossIterator::operator*() const {return cont.conElements[(vector<int>::size_type)index];}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {return &cont == &other.cont && index == other.index;}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {return !(*this == other);}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {return index > other.index;}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {return index < other.index;}
bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const {return (*this > other) || (*this == other);}
bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const {return (*this < other) || (*this == other);}

//sideCrossIterator begin and end funactions.
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {return SideCrossIterator(cont);}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    //first we need the iterator himself
    SideCrossIterator iterator(cont);

    //now we need to change the index to the end
    iterator.index = cont.conElements.size();
    return iterator;
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(SideCrossIterator const &other) {
    //first we need to make shure we place a diffrent iterator
    if(&this->cont != &other.cont){throw runtime_error("WORNG");}

    //now we just need place each atribute
    if (this != &other) {
        cont = other.cont;
        index = other.index;
    }
    return *this;
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    //first we need to check if we can increase
    if(*this == this->end()){throw runtime_error("ALREADY AT SIZE");}
    
    //if we wre "in the middle" end equals to start we can just put size beacuse we at the end of the iterator since its cross side
    if (startI == endI){index = this->cont.size();}

    //else we are still in the crossing and we have more to go
    else if (this->index < this->cont.size()/2) {
        index = endI;
        endI--;
    } 

    //else it is even iterator
    else {
        startI++;
        index = startI;
    }
    return *this;
}






//AscendingIterator oprators using each other
int MagicalContainer::AscendingIterator::operator*() const {return contr.conElements[(vector<int>::size_type)index];}
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {return &contr == &other.contr && index == other.index;}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {return !(*this == other);}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {return index > other.index;}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {return index < other.index;}
bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator& other) const {return (*this > other) || (*this == other);}
bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator& other) const {return (*this < other) || (*this == other);}

//AscendingIterator begin and end funactions, placement, plusplus
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {return AscendingIterator(contr);}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    //first we need the iterator himself
    AscendingIterator iterator(contr);

    //now we need to change the index to the end
    iterator.index = contr.conElements.size();
    return iterator;
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator const &other) {
    //first we need to make shure we place a diffrent iterator
    if(&this->contr != &other.contr){throw runtime_error("WORNG");}

    //now we just need place each atribute
    if (this != &other) {contr = other.contr; index = other.index;}
    return *this;
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    //first we need to check if we can increase
    if(index==this->contr.size()){throw runtime_error("INDEX ALREADY AT SIZE");}
    ++index; return *this;
}






//PrimeIterator oprators using each other
int MagicalContainer::PrimeIterator::operator*() const {return *(this->cont.primesPointer[(vector<int>::size_type)index]);}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {return &cont == &other.cont && index == other.index;}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {return !(*this == other);}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {return index > other.index;}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {return index < other.index;}
bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const {return (*this > other) || (*this == other);}
bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const {return (*this < other) || (*this == other);}

//PrimeIterator begin and end funactions.
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {return PrimeIterator(cont);}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    //first we need the iterator himself
    PrimeIterator iterator(cont);

    //now we need to change the index to the end
    iterator.index = cont.primesPointer.size(); return iterator;
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(PrimeIterator const &other) {
    //first we need to make shure we place a diffrent iterator
    if(&this->cont != &other.cont){throw runtime_error("WORNG");}

    //now we just need place each atribute
    if (this != &other) {cont = other.cont; index = other.index;}
    return *this;
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    //first we need to check if we can increase
    if(*this == this->end()){throw runtime_error("ALREADY AT SIZE");}
    this->index++; return  *this;
}


