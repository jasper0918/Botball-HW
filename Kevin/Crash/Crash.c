int main ()
{
	camera_open();
	depth_open();
	while(!(a_button_clicked())){
		camera_update();
		depth_update();
		display_clear();
		printf("prepare succeeds");
	}
	return 0;
}
