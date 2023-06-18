#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

bool isPrime(int num)  {
    if (num < 2)
        return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void MagicalContainer::addElement(int element) {
    //from the internet
    std::vector<int>::iterator isFound = find(conElements.begin(), conElements.end(), element);
    if (isFound == conElements.end()) {
        this->conElements.push_back(element);
        sort(this->conElements.begin(),this->conElements.end());
        this->primePointer.clear();

        for(int i=0;i<this->conElements.size();++i)
            if(isPrime(this->conElements[(vector<int>::size_type)i]))
                this->primePointer.push_back(&this->conElements[(vector<int>::size_type)i]);
    }
}


void MagicalContainer::removeElement(int element) {
        //from the internet
        std::vector<int>::iterator isFound = find(conElements.begin(), conElements.end(), element);
        if (isFound != conElements.end()) {
            conElements.erase(isFound);
            this->primePointer.clear();

            for(int i=0;i<this->conElements.size();++i)
                if(isPrime(this->conElements[(vector<int>::size_type)i]))
                    this->primePointer.push_back(&this->conElements[(vector<int>::size_type)i]);
        }
        else
            throw runtime_error("ElEMENT IS NOT EXITS");
    }

int MagicalContainer::size() const {return conElements.size();}



int MagicalContainer::AscendingIterator::operator*() const {return contr.conElements[(vector<int>::size_type)index];}
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {return &contr == &other.contr && index == other.index;}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {return !(*this == other);}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {return index > other.index;}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {return index < other.index;}
bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator& other) const {return (*this > other) || (*this == other);}
bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator& other) const {return (*this < other) || (*this == other);}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {return AscendingIterator(contr);}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator iterator(contr);
    iterator.index = contr.conElements.size();
    return iterator;
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator const &other) {
    if(&this->contr != &other.contr){throw runtime_error("WORNG");}
    if (this != &other) {
        contr = other.contr;
        index = other.index;
    }
    return *this;
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(index==this->contr.size()){throw runtime_error("INDEX ALREADY AT SIZE");}
    ++index; return *this;
}




int MagicalContainer::SideCrossIterator::operator*() const {return cont.conElements[(vector<int>::size_type)index];}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {return &cont == &other.cont && index == other.index;}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {return !(*this == other);}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {return index > other.index;}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {return index < other.index;}
bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const {return (*this > other) || (*this == other);}
bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const {return (*this < other) || (*this == other);}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {return SideCrossIterator(cont);}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iterator(cont);
    iterator.index = cont.conElements.size();
    return iterator;
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(SideCrossIterator const &other) {
    if(&this->cont != &other.cont){throw runtime_error("WORNG");}
    if (this != &other) {
        cont = other.cont;
        index = other.index;
    }
    return *this;
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if(*this == this->end()){throw runtime_error("ALREADY AT SIZE");}
    if (startI == endI){index = this->cont.size();}
    else if (this->index < this->cont.size()/2) {
        index = endI;
        endI--;
    } else {
        startI++;
        index = startI;
    }
    return *this;
}







int MagicalContainer::PrimeIterator::operator*() const {return *(this->cont.primePointer[(vector<int>::size_type)index]);}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {return &cont == &other.cont && index == other.index;}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {return !(*this == other);}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {return index > other.index;}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {return index < other.index;}
bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const {return (*this > other) || (*this == other);}
bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const {return (*this < other) || (*this == other);}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {return PrimeIterator(cont);}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iterator(cont);
    iterator.index = cont.primePointer.size();
    return iterator;
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(PrimeIterator const &other) {
    if(&this->cont != &other.cont){throw runtime_error("WORNG");}
    if (this != &other) {
        cont = other.cont;
        index = other.index;
    }
    return *this;
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(*this == this->end()){throw runtime_error("ALREADY AT SIZE");}
    this->index++;
    return  *this;
}


