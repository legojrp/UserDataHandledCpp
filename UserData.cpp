#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
class UserData {
UserData(std::string path){
      this->path = path;
    }
public:
	void writeToProperty(std::string Property, std::string Replacement){
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
  std::string readFromProperty(std::string Property){
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
	void createProperty(std::string Property, std::string Value){
  	std::ofstream file(this->path);
    file << Property + ": " + Value + "\n";
    file.close();
}
    void changePath(std::string path){
        this->path = path;
    }
    std::string returnPath(){
    return this->path;
    }
private:
	std::string path;
};
