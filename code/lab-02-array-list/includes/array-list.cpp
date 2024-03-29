#include "array-list.h"
#include <stdexcept>

ArrayList::ArrayList()
{
    // Initialize the contents of your list.
    count = 0;
}
void ArrayList::prepend(int value)
{
    insertAt(value, 0);
}

void ArrayList::insertAt(int value, int index){
    if (count >= CAPACITY) {
        throw std::length_error("Out of room");
    }
    for ( int i = count; i > index; i-- ) {
        data[i] = data[i-1];
    }
    data[index] = value;
    count++;
    
}
void ArrayList::append(int value)
{
    if (count >= CAPACITY) {
        throw std::length_error("Out of room");
    }
    data[count] = value;
    count++;
}

void ArrayList::remove(int index) {
    if ( index < 0 || index >= count) {
        throw std::out_of_range("Index out of bounds");
    }
    for ( int i = index; i < count-1; i++ ) {
        data[i] = data[i+1];
    }
    count--;
    
}
int ArrayList::get(int index) const
{
    if ( index < 0 || index >= count) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}
int ArrayList::find(int value) const
{
    for ( int i = 0; i < count; i++ ) {
        if ( data[i] == value) {
            return i;
        }
    }
    return -1;
}

int ArrayList::length() const
{
    return count;
}
