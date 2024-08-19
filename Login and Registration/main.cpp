#include <iostream>
#include <string>
#include <fstream>


using namespace std;

string db = "database.txt";

class user{
private:
    string username;
    string password;
public:
    user(){}

    void RegLog(){
        ofstream outfile;
        ifstream infile(db);
        string line;
        string _pass;
        bool f = false;
        int cnt = 0;
        outfile.open(db , ios::app);

    if (outfile.is_open())
    {
        cout << "Enter your username: ";
        getline(cin, username);

        if(!hasUser(username)){
            outfile << username << endl;
            cout << "Enter your password: " ;
            getline(cin, password);
            outfile << password << endl;
        }else{
            if(infile.is_open())
            {
                while(getline(infile, line))
                {
                    if(line ==  username)
                    {
                        getline(infile,_pass);
                        break;
                    }

                }
                infile.close();
            }
            cout << "Enter your password: " ;
            getline(cin, password);

            while(_pass != password && cnt < 3)
            {
                cout << "Enter your password again: ";
                getline(cin,password);
                cnt++;
            }

            if(_pass == password)
            {
                cout<< "Login Successfully" << endl;
            }
        }

        outfile.close();
    }
    else{
        cout << "Failed to open " << db << endl;
    }
    }



private:
    bool hasUser(const string &_user){
        ifstream infile(db);
        string line;
        int cnt = 1;
        if(infile.is_open()){
               while(getline(infile, line))
               {
                   if(line == _user && cnt % 2 == 1) return true;
                   cnt++;
               }
               infile.close();
        }
        else{
            cout << "failed hasUser" << endl;
        }

        return false;
    }

    void displayFileContent(const string &filename)
    {
        ifstream infile(filename);
        string line;
        if(infile.is_open())
        {
            while(getline(infile, line)){
                cout << line << endl;
            }
            infile.close();
        }else{
        cout << "Failed to open File "  << endl;
        }

    }
};

int main(){
    user a;
    a.RegLog();
    return 0;
}
