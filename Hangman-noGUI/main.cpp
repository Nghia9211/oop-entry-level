#include <iostream>
#include <fstream>
#include <ctime>
#include <set>
#include <string>
#include <vector>

using namespace std;


class _word
{
private:
    string w;
public:
    _word(){
        srand(static_cast<unsigned int>(time(0)));  // Initialize random seed
    }

void generateWord() {
    ifstream infile("dict.txt");
    string line;
    vector<string> words;

    if (infile.is_open()) {
        // Load all words into a vector
        while (getline(infile, line)) {
            words.push_back(line);
        }
        infile.close();

        // Check if we have any words in the vector
        if (!words.empty()) {
            // Generate a random index
            int randomIndex = rand() % words.size();

            // Select the word at the random index
            w = words[randomIndex];
        }
    } else {
        cout << "Failed to open file " << endl;
    }
}
    int length() const
    {
        return w.size();
    }
    string getWord() const
    {
        return w;
    }
    set<char> setOfWord()const {
        set<char> _char;
        for(int i = 0; i < w.size(); i++)
        {
            _char.insert(w[i]);
        }
        return _char;
    }
};

class Hangman{
private:
    string word;
    set<char> listChar;
    int w_length;
    bool endGame;
    vector<char> _guess;
public:

    void createWord(_word& a)
    {
        a.generateWord();
        w_length = a.length();
        word = a.getWord();
        listChar = a.setOfWord();
        endGame = false;
    }
    void startGame(){
        int guess = 0;
        cout << word << endl;
        while(guess < 10 && endGame == false)
        {
            char g;
            cout << "Enter your guess: ";
            cin >> g;
            while(!isalpha(g) || g < 'a' || g > 'z') {
                cout << "Just enter only 1 letter: " ;
                cin >> g;
            }

            if(listChar.find(g) != listChar.end())
            {
                _guess.push_back(g);
                listChar.erase(g);
                cout << "You guess the correct letter: " << g << endl;


            }else{
                cout << "Wrong letter" << endl;
                guess++;
            }
            displayWord();
            if(listChar.empty())
            {
                cout << "You win" << endl;
                break;
            }

        }
    }
public:
    void displayWord()
    {
        vector<char> tmp(w_length,'_');

        for(int i = 0; i < _guess.size() ; i++)
        {
            for(int j = 0; j < w_length ;j++)
            {
                if(_guess[i] == word[j] )
                {
                    tmp[j] = _guess[i];
                }

            }
        }
        for(int i = 0 ; i < tmp.size() ; i++)
        {
            cout << tmp[i];
        }
        cout << endl;


    }
};

int main(){
    Hangman a;
    _word w;
    a.createWord(w);
    a.startGame();
    return 0;
}
