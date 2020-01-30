/* STRONGHOLD - sh_yard0.c by astarel */

inherit "room/room";

void reset(status arg) {

string dir_temp;
int sh_number;
int i;
int temp_int;
	if(arg)

	set_short("YARD 0 short");
	set_long("YARD 0 long");
	set_light(3);
	
	dir_temp = file_name(this_object());
   	sscanf(dir_temp, "/data/stronghold/stronghold_%d/yard/sh_yard%d#%d", sh_number,i,temp_int);

	add_exit("north","/data/stronghold/stronghold_"+sh_number+"/rooms/room0");
	add_exit("south","/data/stronghold/stronghold_"+sh_number+"/yard/sh_entrance");
	add_exit("west","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard1");
	add_exit("east","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard7");
	
}

	
	