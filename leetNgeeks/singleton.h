
#include<bits/stdc++.h>
using namespace std;



class printer{
public:
	static printer* instance();
	void print_paper();

private:
	static printer* pinstance;
	printer() {};
	printer(printer const&){}; // copy constructor

};


class GameSetting{

public:
	static GameSetting * getinstance();
	void get_width(){
		cout<<"width: "<<width<<endl;
	}
	void get_height();
	void set_width(int _w);
	void set_height(int _h);
private:
	int width;
	int height;
	static GameSetting *ginstance;
	GameSetting(){
		width = 1600; // default
		height = 480; // default
	}
	//GameSetting (const&){}; // copy constructors
};