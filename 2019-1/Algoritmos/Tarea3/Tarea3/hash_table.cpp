// Santiago Lopez
// Juanita Gomez

#ifdef _hash_table_hpp_

// ----------------------------CONSTRUCTOR AND DESTRUCTOR-----------------------------

// Hash Table Constructor
template <typename data_type>
hash_table<data_type>::hash_table(){
    n_buckets = 13;
    count = 0;
    data_type tmp;
    for (size_t i = 0; i < n_buckets; i++){
        array.push_back(bucket(tmp));
    }
    checkrep();
}

// Hash Table Destructor
template <typename data_type>
hash_table<data_type>::~hash_table(){
    checkrep();
    array.clear();
}

// -----------------------------------CLASS METHODS-----------------------------

template <typename data_type>
void hash_table<data_type>::empty(){
    // Clears content of table
    count = 0;
    checkrep();
    for (size_t i = 0; i < n_buckets; i++){
        array[i].info = Empty;
    }
    checkrep();
}

template <typename data_type>
int hash_table<data_type>::insert(const data_type &x){
    // Inserts element x in table and returns space where key was inserted
    checkrep();
    float load_factor = float(count) / float(n_buckets);
    if (load_factor >= 0.5) {
        rehash();
    }
    if (array[hashing(x)].info != Active){
        array[hashing(x)].elem = x;
        array[hashing(x)].info = Active;
        count ++;
        return hashing(x);
    }
    int idx = hashing(x) + 1; // no la cagues!!
    while(array[idx % n_buckets].info == Active) idx++;
    array[idx % n_buckets].elem = x;
    array[idx % n_buckets].info = Active;
    count++;
    checkrep();
    return idx % n_buckets;
}

template <typename data_type>
int hash_table<data_type>::search(const data_type &x) const{
    // Searches element x in table and returns space where key was inserted
    checkrep();
    if (array[hashing(x)].info == Active && array[hashing(x)].elem == x) return hashing(x);
    int idx = (hashing(x) + 1) % n_buckets;
    while (array[idx].elem != x || array[idx].info != Active ) {
        if (idx == int(hashing(x))) return -1;
        idx ++;
        idx = idx % n_buckets;
    }
    checkrep();
    return idx;
}

template <typename data_type>
int hash_table<data_type>::remove(const data_type &x){
    // Removes element x in table and returns space where key was before removed
    checkrep();
    int idx = search(x);
    if (idx != -1){
        array[idx].info = Deleted;
        count--;
        return idx;
    }
    checkrep();
    return -1;
}

//-------------------------------------PRIVATE METHODS-------------------------------

template <typename data_type>
void hash_table<data_type>::rehash(){
    // Constructs new table with double size and inserts elements using new hash code
    checkrep();
    n_buckets *= 2;
    data_type tmp;
    vector<data_type> temp;
    for (unsigned i = n_buckets/2; i < n_buckets; i++){
        array.push_back(bucket(tmp));
    }
    for (size_t i = 0; i < n_buckets/2; i++){
        if (array[i].info == Active) temp.push_back(array[i].elem);
        array[i].info = Empty;
    }
    count = 0;
    for (size_t i = 0; i < temp.size(); i++) {
        insert(temp[i]);
    }
    checkrep();
}


template <typename data_type>
unsigned int hash_table<data_type>::hashing(const data_type &x) const {
    // Create a hash code for the specific data type
    hashFunction <data_type > hashFunctor;
    int n = int(n_buckets);
    return hashFunctor(x) % n;
}

template <typename data_type>
void hash_table<data_type>::display(){
    string info;
    cout << endl;
    cout << "--------------- HASH TABLE ------------- " << endl;
    cout << endl;
    for (size_t i = 0; i < n_buckets; i++) {
        if (array[i].info == Active) info = "Active";
        else if(array[i].info == Empty) info = "Empty";
        else if(array[i].info == Deleted)  info = "Deleted";
        cout << "Element: " <<  array[i].elem << "             Info: " << info << endl;
    }
    cout << "---------------------------------------" << endl;
}

template <typename data_type>
void hash_table<data_type>::checkrep() const{
    assert (n_buckets>=0);
    for (size_t i=0; i<n_buckets; i++){
        assert(array[i].info == Empty || array[i].info == Active|| array[i].info == Deleted);
    }
}

#endif
