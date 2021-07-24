#include <fstream>
#include <iostream>
#include <string>
class UserData { 
public:
	UserData(path){};
	void writeToProperty();
	std::string readFromProperty(std::string Property);
	void createFile();
	void changeProperty();
private:
	std::string path;
};
std::string UserData::readFromProperty(std::string Property){
  std::ofstream file(this->path);
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
	std:ofstream file(this->path);
  	std::string text, pre, post, changed;    
    int preOrPost = 0;
    while (std::getline(file, text)){
      if (text.substr(0, text.find(": ")) == Property){
        int = 1;
        continue;
      }
      else if (int == 0){
        pre += text + "\n";
      }
      else if (int == 1){
        post += text + "\n";
      }
	
    }
    changed = pre + Property + ": " + Replacement + post;
    file.close();
    std::remove(this->path);
    std::ifstream file(this->path);
    file << changed;
    file.close()
}
