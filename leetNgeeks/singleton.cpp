
#include<bits/stdc++.h>
#include "singleton.h"

using namespace std;





printer * printer :: pinstance ;

printer* printer :: instance() {
	if(pinstance==NULL){

		pinstance = new printer();
	}
	return pinstance;
}

void printer::print_paper(){
	cout<<"printing...";
}








// Game setting Example

GameSetting * GameSetting::ginstance;

GameSetting* GameSetting:: getinstance(){
	if(ginstance==NULL){
		ginstance = new GameSetting();
		return ginstance;
	}
}

int main() {
	printer::instance()->print_paper();
	cout<<endl;	

	GameSetting::getinstance()->get_width();


}