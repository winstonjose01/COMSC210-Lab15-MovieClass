// COMSC210 | Lab 15 | Winston Jose
// Github line: https://github.com/winstonjose01/COMSC210-Lab15-MovieClass

# include <iostream>
# include <fstream>
# include <vector>
# include <iomanip>
using namespace std;

// Function declaration
int openFile(fstream &, string);

// Movie object
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
    // Getter for movie title
    string getMovieTitle()  {return movie_title;}
    // Getter for year released
    string getYearReleased()    {return year_released;}
    // Getter for screen writer
    string getScreenWriter()    {return screen_writer;}
    // Prints the object from the vector
    void print() const {
        cout << "Movie : " << movie_title << endl; // Print the movie title
        cout << "\tYear released : "<< year_released << endl; // Print the year released
        cout << "\tScreenwriter: " << screen_writer << endl; // Print the screenwriter
    }
};


main(){
    fstream filestream;
    // File that contains the movie information
    string filename = "moviefile.txt";
    string line;
    // Create vector to store the movie objects
    vector <Movie> movie_vect;
    // Checks if file opened correctly
    if (openFile(filestream , filename) != 1)
        exit (-1);

    while (getline(filestream, line)){
        // Make temperary object for reading the file 
        Movie tempmovie;
        // Temporary movie title variable
        string temptitle = line;
        // Temporary year released
        string tempyear;
        // Temporary screenwrite
        string tempwriter;

        // Set the movie title for this object
        tempmovie.setMovieTitle(temptitle);
        // Add the new movie object into the vector
        getline(filestream, tempyear);
        // Set the year released for this object
        tempmovie.setYearReleased(tempyear);
        // Read the screen writer from the file
        getline(filestream, tempwriter);
        // Set the screen writer for this object
        tempmovie.setScreenWriter(tempwriter);

        // Add the new movie object into the vector
        movie_vect.push_back(tempmovie);
    }

    // Call print() method for to output the vector objects
    cout << endl;
    // Iterate through the vector elements for printing
    for (const Movie &m : movie_vect){
        //Call the print method
        m.print();
        cout << endl;
    }


}
// Function opens a file using fstream
// Arguments: fstream reference and string variables
// Return: 0 is error opening the file, 1 if file opened.
int openFile (fstream &filestream, string filename){
    // Opens the file for reading
    filestream.open(filename.data(), ios::in);
    // If cannot open the file return 0 and abort in main()
    if (!filestream){
        cout << "Error opening file. Program aborting \n";
        return 0;
    }
    else{
        // If file opened normal, return 1
        return 1;
    }
    // Close the filestream
    filestream.close();

}

