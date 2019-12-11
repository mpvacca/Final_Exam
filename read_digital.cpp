#include <iostream>         // for the input/output
#include <stdlib.h>         // for the getenv call
#include <sys/sysinfo.h>    // for the system uptime call
#include <fstream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <cgicc/Cgicc.h>    // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#define LED_GPIO "/sys/class/gpio/gpio60/"
using namespace std;
using namespace cgicc;

void writeGPIO(string filename, string value){
   fstream fs;
   string path(LED_GPIO);
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

int main(){
   Cgicc form;                      // the CGI form object
   string file = "value";
   string line;
   int value;
   writeGPIO("direction", "in");
   
   string path = LED_GPIO + file;
   // generate the form but use states that are set in the submitted form
   cout << HTTPHTMLHeader() << endl;       // Generate the HTML form
   cout << html() << head() << title("CPE 422 Final Exam: Reading Digital Input") << head() << endl;
   cout << body() << h1("Reading a GPIO Pin Via a Web browser") << endl;;
   cout << "<form action=\"/cgi-bin/read_digital.cgi\" method=\"POST\">\n";
   cout << "<div><input type=\"submit\" value=\"Read Switch\" />";
   cout << "</div></form>";
   cout << "<div> Switch State: </div>";

   std::fstream fs;
   fs.open(path, std::fstream::in);
   getline(fs,line);
   fs.close();
   value = stoi(line);
   if(value==1)
      cout << "<div> ON </div>";
   else
      cout << "<div> OFF </div>";
   cout << body() << html();
   return 0;
}
