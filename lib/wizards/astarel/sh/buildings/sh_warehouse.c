/* STRONGHOLD - sh_bar.c by astarel */

inherit "room/room";

void reset(status arg) {

string dir_temp;
int sh_number;
int i;
int temp_int;
	if(arg)

	set_short("WAREHOUSE short");
	set_long("WAREHOUSE long");
	set_light(3);
	
	dir_temp = file_name(this_object());
   	sscanf(dir_temp, "/data/stronghold/stronghold_%d/buildings/sh_warehouse%d#%d", sh_number,i,temp_int);

	add_exit("out","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard5");
	
	
	
}