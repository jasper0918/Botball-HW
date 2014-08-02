// Created on Sun July 20 2014, Jasper Yang, Find Ball

#define CONFIG "color.config"
#define GREEN 1

const int LM = 3;
const int RM = 1;

int main(){
	camera_open(LOW_RES);
	camera_load_config(CONFIG);
	int objNum = get_object_count(GREEN);
	
	while(objNum == 0){
		motor(LM, 50);
		motor(RM, 50);
		camera_update();
		objNum = get_object_count(GREEN);
	}
	
	return 0;
}
