#include <vector>

using namespace std;
namespace ariel{

class MagicalContainer {
    private:
        vector<int> conElements;
        vector<int*> primesPointer;
        
    public:

        //default from the internet and class
        MagicalContainer() = default;
        ~MagicalContainer() = default;

        void addElement(int element);
        void removeElement(int element);
        int size() const;

        /* i was not shure if we need to do a get elem at index
           because we have find funaction i will leave it at "note mode"
        */ 
        //int getElementAt(int index)const;
        
        
        class SideCrossIterator {
            private:
                MagicalContainer& cont;
                int index;
                int startI;
                int endI;

            public:
                //like default constractors ish. help from the internet
                SideCrossIterator(MagicalContainer& cont) : cont(cont), index(0), startI(0),endI(cont.size()-1){}
                SideCrossIterator(const SideCrossIterator& other) : cont(other.cont), index(0) ,startI(other.startI), endI(other.endI){}
                ~SideCrossIterator() = default;

                SideCrossIterator& operator=(const SideCrossIterator& other);
                SideCrossIterator& operator++();
                SideCrossIterator begin();
                SideCrossIterator end();

                bool operator==(const SideCrossIterator& other) const;
                bool operator!=(const SideCrossIterator& other) const;
                bool operator>(const SideCrossIterator& other) const;
                bool operator<(const SideCrossIterator& other) const;
                bool operator>=(const SideCrossIterator& other) const;
                bool operator<=(const SideCrossIterator& other) const;

                int operator*() const;
            
        };



        class AscendingIterator {
            private:
                MagicalContainer& contr;
                int index;

            public:
                //like default constractors ish. help from the internet
                AscendingIterator(MagicalContainer& cont) : contr(cont), index(0) {}
                AscendingIterator(const AscendingIterator& other) : contr(other.contr), index(other.index) {}
                ~AscendingIterator() = default;
                
                AscendingIterator& operator=(const AscendingIterator& other);
                AscendingIterator& operator++();
                AscendingIterator begin();
                AscendingIterator end();

                bool operator==(const AscendingIterator& other) const;
                bool operator!=(const AscendingIterator& other) const;
                bool operator>(const AscendingIterator& other) const;
                bool operator<(const AscendingIterator& other) const;
                bool operator>=(const AscendingIterator& other) const;
                bool operator<=(const AscendingIterator& other) const;

                int operator*() const;

        };
        


        class PrimeIterator {
            private:
                MagicalContainer& cont;
                int index;
                
            public:
                //like default constractors ish. help from the internet
                PrimeIterator(MagicalContainer& cont) : cont(cont), index(0){}
                PrimeIterator(const PrimeIterator& other) : cont(other.cont), index(other.index) {}
                ~PrimeIterator() = default;

                PrimeIterator& operator=(const PrimeIterator& other);
                PrimeIterator& operator++();
                PrimeIterator begin();
                PrimeIterator end();

                bool operator==(const PrimeIterator& other) const;
                bool operator!=(const PrimeIterator& other) const;
                bool operator>(const PrimeIterator& other) const;
                bool operator<(const PrimeIterator& other) const;
                bool operator>=(const PrimeIterator& other) const;
                bool operator<=(const PrimeIterator& other) const;

                int operator*() const;
        };
    };

}