// Game Of Life
// Jo Haugum,    Stevens Institute of Tecnology,      2017
#include <iostream>
#include <fstream>
using namespace std;

class life {
private:
    char board[12][12];
    char nextboard[12][12];
    int gens;
    int freq;
public:
    life(){ // Instantiate the board with all '-'.
        for (int r = 0; r < 12; r++){
            for (int c = 0; c < 12; c++){
                board[r][c] = '-';
                nextboard[r][c] = '-';
            }
        }
    }
    int getGens() const {
        return gens;
    }
    int getFreq() const {
        return freq;
    }
    // Method to load the board from a file, and make a copy board.
    void load(string filename){
        ifstream file;
        file.open(filename);
        if(file.is_open()){
            file >> gens;
            file >> freq;
            while (!file.eof()){
                for (int r = 1; r < 11; r++)
                    for (int c = 1; c < 11; c++){
                        file >> board[r][c];
                        nextboard[r][c] = board[r][c];
                    }
            }
        }
        file.close();
    }
    // Method to print the board
    void print(){
        for (int r = 0; r < 12; r++){
            for (int c = 0; c < 12; c++)
                cout << board[r][c] << ' ';
            cout << '\n';
        }
    }
    // Method to print the next board
    void printnext(){
        for (int r = 0; r < 12; r++){
            for (int c = 0; c < 12; c++)
                cout << nextboard[r][c] << ' ';
            cout << '\n';
        }
    }
    // Method to generate next board
    void next(){
        char curr;
        for (int r = 1; r < 11; r++){
            for (int c = 1; c < 11; c++){
                int alive = 0;
                for (int x = -1; x < 2; x++){
                    for (int y = -1; y < 2; y++){
                        curr = board[r+x][c+y];
                        if ((board[r+x][c+y] == 'o') && ((x!=0) || (y!=0))){
                            alive++;
                        }
                    }
                }
                // Rules for survival, death or creation of cells.
                if (alive < 2){
                    nextboard[r][c] = '.';
                }
                if (alive == 3)
                    nextboard[r][c] = 'o';
                if (alive > 3)
                    nextboard[r][c] = '.';
            }
        }
        for (int r = 0; r < 12; r++){
            for (int c = 0; c < 12; c++)
                board[r][c] = nextboard[r][c];
        }
    }
};
int main(){
    life a;
    a.load("hw3b.dat");
    // Loop to run the game for x simulations and print every y times.
    int gens = a.getGens();
    int freq = a.getFreq();
    cout << "gens: " << gens << " freq: " << freq << endl;
    for (int i = 0; i <= gens; i++){
            if (i % freq == 0){
                cout << "Generation " << i << ':' << endl;
                a.printnext();
                }
            a.next();
        }
}

