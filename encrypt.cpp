/**
	C++ programme to encrypt or decrypt the file using the Xor Encryption method
	Developed and programmed by : yubaraj Poudel
	Date:- 3/3/2015
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
	        	cout << " from the keyboard (k) \n from the local (f) \n  quit (q) \n make a choice (k - l - q)";
	        	cin>>ch;
        	}
        		while(ch!='k' && ch!='K' && ch!='f' && ch!='F' && ch!='q' && ch!='Q');
        return ch;
	}

	bool saveinFile(string text, string path){
	  string paths = path;
	  if(paths == ""){
	  	paths = "example.txt";
	  }
	  ofstream myfile;
	  myfile.open(paths.c_str(), ios::app);
	  if (myfile.is_open()){
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

	void getTextFromPathOfFile(string path, char key){
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
		//return data;
	}

	int main () {
	  char choice, key;
	  char cont = 'n';

	  char mtext[100];
	  			cout<<"\n\t\t    *********** Encryption C++ ***********\n\n";
        		do{
        			choice = askChoice();
        			if(choice == 'q' || choice == 'Q'){
        				cout<< "\n Thanks for using this application \n";
        				exit(0);	
        			}

	        		if(choice == 'k' || choice == 'K'){
	        			cout<< "\n\n Please Type in the line";
	        			cin>>mtext;
	        			cout << "\n\n please Type in the encrypt key (should be one word and should not contain space)";
	        			cin>>key;
	        			string decrypted = encryptDecrypt(mtext, key);
	        			if(saveinFile(decrypted, "")){
	        				cout<< "\n\n would you like to continue ?? (y/n)";
	        				cin>>cont;
	        			}
	        			else{
	        				cout<< "problem in saving the file";
	        			}

	        		}

	        		if(choice == 'f' || choice == 'F'){
	        			char path[200];
	        			char mkey;
	        			cout << "\n please provide the full path (C:\\Demo.txt) : ";
	        			cin>> path;
	        			cout << "\n type in the key please";
	        			cin >> mkey;
	        			getTextFromPathOfFile(path, mkey);
	        			//string mytext = getTextFromPathOfFile(path, mkey);
	        			//for(int i= 0; i!=)
	        			/*string decrypted = encryptDecrypt(mtext, key);
	        			if(saveinFile(decrypted, path)){
	        				cout<< "\n\n would you like to continue ?? (y/n)";
	        				cin>>cont;
	        				
	        			}
	        			else{
	        				cout<< "problem in saving the file";
	        			}
	        			*/	//cout<< "in test read";
	        		}
	        	}
	        	while(cont=='y');
        		return 0;
        	}

	  	
	
		