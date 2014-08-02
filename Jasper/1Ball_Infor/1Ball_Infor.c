// Created on Sun July 20 2014, Jasper Yang, ball coordinate

// color channel:
const int GREEN = 1;
const int PINK = 0;

int main(){
	camera_open(LOW_RES);
	camera_load_config("color.config");
	while(digital(15) == 0){
		display_clear();
		camera_update();
		int objNum = get_object_count(GREEN);
		if(objNum == 0)
			printf("NO SUCH OBJECT!!!!!!!!");
		else if(objNum > 0){
			point2 objCen2 = get_object_centroid(GREEN, 0);
			int objArea = get_object_area(GREEN, 0);
			printf("centroid X:\t%d\nY:\t%d\n", objCen2.x, objCen2.y);
			printf("Area:\t%d\n", objArea);
		}
		msleep(100);
	}
	return 0;
}
