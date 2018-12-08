#include "app.h"

int main() {

	App application;
	
	if(!application.init(1920,1080, "Fractals")) return -1;

	if(!application.run()) return -1;;
  
	return 0;
}

 
