/**
	C++ programme to encrypt or decrypt the file using the Xor Encryption method
	Developed and programmed by : yubaraj Poudel
	Date:- 3/3/2015
	minor project of BCT-II/I c++ programming
*/

#include<iostream>
#include<fstream>
#include<string>
#include <stdlib.h> 
	
	using namespace std;

	string encryptDecrypt(string toEncrypt, char mkey) {
    
    string output = toEncrypt;
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ mkey;
    
    return output;
	}

	char askChoice(){
		char ch;
			cout << "\n\n Make a choice\n\n";
        	do{
	        	cout << " from the keyboard (k) \n from file path (f) \n quit (q) \n make a choice (k - f - q) \t";
	        	cin>>ch;
        	}
        		while(ch!='k' && ch!='K' && ch!='f' && ch!='F' && ch!='q' && ch!='Q');
        return ch;
	}

	bool saveinFile(string text, string path){
	  
	  if(path == ""){
	  	path = "example.txt";
	  }
	  ofstream myfile;
	  myfile.open(path.c_str(), ios::out);
	  if (myfile.is_open()){
	  	text = text + "/o";
		myfile << text;
		cout<< "\n saved in the file";		  		 
	   	myfile.close();
	   }

	  else {
	  	cout << "Unable to open file";
	  	return false;
	  }
	  	return true;
	}

	void encryptFromPathOfFile(string path, char key){
		//string paths = path;
		int array_size = 1024;
		//char* data[] = new char[array_size];
		char data[array_size];
		int position = 0;
		ifstream fin;
		fin.open(path.c_str(), ios::in);
		//fin.open("example.txt", ios::in);
		if(fin.good()){
			while (!fin.eof() && position <= array_size) {
				fin.get(data[position]);
				position++;
			}
			data[position-1] = '\0';
			fin.close();
		}
		else{
			cout << "problem in opening the file, check the path";
		}
		ofstream ofile;
		ofile.open(path.c_str(), ios::out);
		if(ofile.is_open()){
			for(int i = 0; data[i]!='\0'; i++){
				char decrypted = data[i]^key;
				ofile<<decrypted;
			}
		}
		else{
			cout<< "unable to open file for writting";
		}
		
	}

	bool checkToContinue(){
		char cont;
		cout<< "\n\n Would you like to continue (y/n) : ";
		cin>> cont;
		cout<<"\n";
		if(cont == 'n' || cont == 'N'){
			return true;
		}
		else{
		return false;
		}
	}

	int main () {
	  char choice, key;
	  bool terminate = false;
	  char mtext[100];
	  			cout<<"\n\t\t    *********** Encryption C++ ***********\n\n";
        		while(!terminate){

        			choice = askChoice();
        			if(choice == 'q' || choice == 'Q'){
        				cout<< "\n Thanks for using this application \n";
        				exit(0);	
        			}

	        		if(choice == 'k' || choice == 'K'){
	        			cout<< "\n Please Type in the line : \n";
	        			cin>>mtext;
	        			cout << "\n\n please Type in the encrypt key (should be one word and should not contain space):\n";
	        			cin>>key;
	        			string decrypted = encryptDecrypt(mtext, key);
	        			saveinFile(decrypted, "");
	        			
	        		}

	        		if(choice == 'f' || choice == 'F'){
	        			char path[200];
	        			char mkey;
	        			cout << "\n please provide the full path (C:\\Demo.txt):\t";
	        			cin>> path;
	        			cout << "\n type in the key please:\t";
	        			cin >> mkey;
	        			encryptFromPathOfFile(path, mkey);
	        			cout<< "File is successfully changed ";
	        		}
	        		
	        		terminate = checkToContinue(); 
	        	}
	        	
	        	
        		return 0;
        	}

	  	
	
		