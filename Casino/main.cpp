#include <bits/stdc++.h>

using namespace std;


class Player{
private:
    long money;
    bool endGame;
public:
    player(long m): money(m), endGame(false){}

    void addmoney(long m)
    {
        money += m;
    }
    int guess() const {
        int x ;
        cout <<" Your guess: " ;
        cin >> x;
        return x;
    }
    int generateCompGuess() const
{
    int g = rand() % 34 + 1;
    return g;
}

    void makeDecision(){
        int userGuess = guess();
        int compGuess = generateCompGuess()
        if(userGuess == compGuess)
        {
            cout << "You Win!" << endl;
            addMoney(100);
            cout << "+100" < endl;
        }else{
            cout << "You Lose!" << endl;
            addMoney(-100);
        }
        cout << "You balance: " << money << endl;
        endGame = true;

        }
    }
    void restart(){
        if(endGame)
        {
            char choice ;
            cout << "Do you want to continue ? (y/n): ";
            cin >> choice;

            if(choice == 'y') endGame = false;
        }
    }
    bool isEndGame()const{
        return endGame;
        }

};

void menu(){
    cout << " Type 1 to play " << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        Player player(1000);

        while(!player.isEndGame())
        {
            player.makeDecision();
            player.restart();

        }

    }
}

int main(){
    srand(static_cast<unsigned int>(time(0)));
    menu();
    return 0;

}
