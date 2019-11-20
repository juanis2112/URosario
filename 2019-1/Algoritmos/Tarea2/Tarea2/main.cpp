// main.cpp
// Tarea2
// Por Juanita Gomez y David Santiago Lopez

#include "clist.hpp"
using namespace std;

int main(){
    Clist<string>playlist;
    playlist.insert("Song␣X");
    playlist.insert("Song␣G");
    playlist.insert("Song␣A");

    cout << "Now␣playing␣" << playlist.back() << endl;
    
    playlist.advance();
    playlist.advance();
    playlist.remove();
    playlist.insert("Song␣J");

    return 0;
}
