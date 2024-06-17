#include <cstdio>
#include <string>
#include <vector>
using namespace std;

//global variables for functions
bool decl_error_found=0;
char* decl_error_var;

char* findDeclarationError() {
	for (int i = 0; i < myVector.size(); i++) {
		for (int j = i + 1; j < myVector.size(); j++) {
			// cout<<"Comparing i="<<i<<", "<<myVector[i]<<" and j="<<j<<", "<<myVector[j]<<endl;
			if (strcmp(myVector[i], myVector[j]) == 0) {
				return myVector[i];
			}
		}
	}
	return NULL;
};

bool isDeclarationError(){
	return decl_error_found;
}

char* getWronglyDeclaredVariable(){
	return decl_error_var;
}

void Print_Block(int cnt) {
	cout << "\nSymbol table BLOCK " << cnt << endl;
};

void Print_ST(char* id) {
	myVector.clear();
	cout << "\nSymbol table " << id << endl;
};

void printPD(Param_Decl* pd) {
	cout << "name " << pd -> id << " type " << pd -> type << endl;
};

void print_VarEntry(VarEntry* VE) {
	while (VE -> id_list != NULL) {
		myVector.push_back(VE -> id_list -> id);
		cout << "name " << VE -> id_list -> id << " type " << VE -> var_type << endl;
		VE -> id_list = VE -> id_list -> id_tail;
	}

	char *decl_error_result=findDeclarationError();
	if(decl_error_result!=NULL && decl_error_found==0){
		decl_error_var=decl_error_result;
		decl_error_found=1;
		cout<<"<ERROR>"<<decl_error_var<<"\n";
	}

};

void print_StrEntry(StrEntry* SR) {
	cout << "name " << SR -> id << " type STRING value " << SR -> str << endl;
};
