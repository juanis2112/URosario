#ifdef _bheap_hpp_

// ------------------------------------------------------Constructors
//Empty
template <typename dataType>
BinaryHeap<dataType>::BinaryHeap(int capacity){
    count = 0;
    dataType tmp = dataType{};
    for (int i = 0; i < capacity; i++) array.push_back(tmp);
    checkrep();
}

//Copy
template <typename dataType>
BinaryHeap<dataType>::BinaryHeap(const vector<dataType> & vec){
    BinaryHeap<dataType> tmp;
    for (unsigned i = 0; i < vec.size(); i++){
        tmp.insert(vec[i]);
    }
    array = tmp.array;
    count = tmp.count;
    checkrep();
}

// ------------------------------------------------------Class Methods
//Find Min
template <typename dataType>
const dataType & BinaryHeap<dataType>::findMin () const{
    checkrep();
    if (count > 0) return array[1];
    else throw underflow_error("Tried to find element in empty heap");
    checkrep();
}

//Insert
template <typename dataType>
void BinaryHeap<dataType>::insert (const dataType &elem){
    checkrep();
    if  (count == 0) array[count+1] = elem;
    else{
        array[0] = elem;
        percolateUp(count+1);
    }
    count ++;
    checkrep();
}

//Delete Min
template <typename dataType>
void BinaryHeap<dataType>::deleteMin(){
    checkrep();
    if (count > 0){
        percolateDown(1);
        count --;
    }
    else throw underflow_error("Tried to delete a element in empty heap");
    checkrep();
}

//Is Empty
template <typename dataType>
bool BinaryHeap<dataType>::isEmpty() const{
    checkrep();
    return (count == 0);
}

//Clear
template <typename dataType>
void BinaryHeap<dataType>::clear(){
    checkrep();
    count = 0;
    checkrep();
}

//Display
template <typename dataType>
void BinaryHeap<dataType>::display() const{
    checkrep();
    cout << "[";
    for (unsigned i = 1; i <= count; i++) cout << array[i] << " " ;
    cout << "]" << endl;
    checkrep();
}

// ----------------------------------------------------- Private
// Percolate Up
template <typename dataType>
void BinaryHeap<dataType>::percolateUp (int Hole){
    if (array[Hole/2] < array[0] || Hole == 1){
        array[Hole] = array[0];
    }
    else{
        array[Hole] = array[Hole/2];
        percolateUp(Hole/2);
    }
}

// Precolate Down
template <typename dataType>
void BinaryHeap<dataType>::percolateDown (int Hole){
    if (size_t(2*Hole) > count || size_t(2*Hole) + 1 > count){
        if (size_t(Hole) != count){
            array[Hole] = array[count];
            if (array[Hole] < array[Hole/2]){
                array[0] = array[Hole];
                percolateUp(Hole);
            }
        }
    }
    else {
        int min;
        if (array[2*Hole] < array[2*Hole + 1]) min = 2*Hole;
        else min = 2*Hole + 1;
        array[Hole] = array[min];
        percolateDown(min);
    }
}

// Checkrep()
template <typename dataType>
void BinaryHeap<dataType>::checkrep() const{
    for (unsigned i = count; i > 1; i--){
        assert(array[i/unsigned(2)] <= array[i]);
    }
}

#endif // _bheap_hpp_
