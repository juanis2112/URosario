// clist.cpp
// Tarea2
// Por Juanita Gomez y David Santiago Lopez


#ifdef _clist_hpp_

template<typename dataType>
//-----------------------------------------------------Constructor--------------------------------------------------------//
Clist<dataType>::Clist(){
    // Constructs an empty object of Clist type
    cursor = nullptr;
    count = 0;
    checkrep();
}

//-----------------------------------------------------Destructor--------------------------------------------------------//
template<typename dataType>
 Clist<dataType>::~Clist(){
     // Clears contents of playlist and deletes cursor
     clear();
     delete cursor;
     checkrep();
}

//-----------------------------------------------------Back--------------------------------------------------------//
template<typename dataType>
dataType & Clist<dataType>::back() const  {
    // Returns element at cursor
    checkrep();
    return cursor -> data;
}

//-----------------------------------------------------Front--------------------------------------------------------//
template<typename dataType>
dataType & Clist<dataType>:: front() const {
    // Returns element next to cursor
    checkrep();
    return (cursor -> link) -> data;
}

//-----------------------------------------------------Insert--------------------------------------------------------//
template<typename dataType>
void  Clist<dataType>::insert(dataType item) {
    // Inserts Node with item as data after cursor
    checkrep();
    if (count == 0) {
        cursor = new Node(item);
        cursor -> link = cursor;
    }
    else{
        Node *tmp = new Node(item, cursor->link);
        cursor -> link = tmp;
        tmp = nullptr;
    }
    count ++;
    checkrep();
}

//-----------------------------------------------------Remove---------------------------------------------------------//
template<typename dataType>
void  Clist<dataType>::remove() {
    // Removes Node after cursor
    checkrep();
    if(count ==1){
        Node *tmp = cursor;
        cursor = nullptr;
        delete tmp;
    }
    else {
        Node *tmp;
        tmp = cursor -> link;
        cursor->link = tmp->link;
        delete tmp;
    }
     count--;
    checkrep();
}

//-----------------------------------------------------Advance--------------------------------------------------------//
template<typename dataType>
void  Clist<dataType>::advance(){
    // Moves cursor to next Node
    checkrep();
    cursor = cursor->link;
    checkrep();
}

//-----------------------------------------------------Size----------------------------------------------------------//
template<typename dataType>
unsigned  Clist<dataType>::size() const{
    // Returns number of elements
    checkrep();
    return count;
}

//-----------------------------------------------------Empty----------------------------------------------------------//
template<typename dataType>
bool  Clist<dataType>::empty() const{
    // Checks if playlist is empty
    checkrep();
    return (count==0);
}

//-----------------------------------------------------Clear----------------------------------------------------------//
template<typename dataType>
void  Clist<dataType>::clear(){
    // Clears contents of playlist
    checkrep();
    while (count!=0) remove();
    checkrep();
}

//-----------------------------------------------------CheckRep----------------------------------------------------------//
template<typename dataType>
void  Clist<dataType>::checkrep() const{
    // Checks representation invariant of the class
    if (count==0) assert (cursor == nullptr);
    else if (count==1) assert (cursor != nullptr && cursor -> link == cursor);
    else assert (cursor != nullptr && cursor->link != nullptr);
}

#endif //_clist_hpp_
