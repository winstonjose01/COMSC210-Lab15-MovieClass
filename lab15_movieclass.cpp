// COMSC210 | Lab 15 | Winston Jose
//

# include <iostream>
# include <fstream>
# include <vector>
using namespace std;

int openFile(fstream &, string);

class Movie{
    private:
        string movie_title;
        string year_released;
        string screen_writer;
    public:
    //Constructor
    Movie(){};
    // Setter for movie_title variable
    void setMovieTitle(string title){
        movie_title = title;
    }
    // Setter for year_release
    void setYearReleased(string year){
        year_released = year;
    }
    void setScreenWriter(string screenw){
        screen_writer = screenw;
    }
    string getMovieTitle()  {return movie_title;}
    string getYearReleased()    {return year_released;}
    string getScreenWriter()    {return screen_writer;}

    void print(){};

};


main(){
    fstream filestream;
    string filename = "moviefile.txt";
    string line;
    vector <Movie> movie_vect;

    if (openFile(filestream , filename) != 1)
        exit (-1);
    

    while (getline(filestream, line)){
        Movie movietemp;
        string temptitle = line;
        string tempyear;
        string tempwriter;
    }

}

int openFile (fstream &filestream, string filename){
    filestream.open(filename.data(), ios::in);
    if (!filestream){
        cout << "Error opening file. Program aborting \n";
        return 0;
    }
    else{
        return 1;
    }

    filestream.close();

}

