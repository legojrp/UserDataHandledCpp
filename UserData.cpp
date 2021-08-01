#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
class UserData { 
public:
	UserData(std::string path){
      this->path = path;
    }
	void writeToProperty(std::string Property, std::string Replacement);
	std::string readFromProperty(std::string Property);
	void createSubset(); 
	void createProperty(std::string Property, std::string Replacement);
private:
	std::string path;
};
std::string UserData::readFromProperty(std::string Property){
  std::ifstream file(this->path);
  std::string text;
  std::string returnstring = "";
   while (std::getline(file, text)){
	if (text.substr(0, text.find(": "))== Property){
		returnstring = text.erase(0, Property.length() + 1);
    }

     
   }
  if (returnstring == ""){
  	returnstring = "Error";
  }
  return returnstring;
}
void UserData::writeToProperty(std::string Property, std::string Replacement){
	std::ifstream file(this->path);
  	std::string text, pre, post, changed;    
    int preOrPost = 0;
    while (std::getline(file, text)){
      if (text.substr(0, text.find(": ")) == Property){
         preOrPost= 1;
        continue;
      }
      else if ( preOrPost == 0){
        pre += text + "\n";
      }
      else if (preOrPost == 1){
        post += text + "\n";
      }
	
    }
    changed = pre + Property + ": " + Replacement + "\n" + post;
    file.close();
    std::remove(this->path.c_str());
    std::ofstream file2(this->path);
    file2 << changed;
    file2.close();
}
void createProperty(std::string Property, std::string Replacement){
  	std::ofstream file(this->path);
    file << Property + ": " + Value + "\n";
    file.close();
}
