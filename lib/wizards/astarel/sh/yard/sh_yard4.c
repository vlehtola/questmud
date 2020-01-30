/* STRONGHOLD - sh_yard4.c by astarel */

inherit "room/room";

void reset(status arg) {

string dir_temp;
int sh_number;
int i;
int temp_int;
	if(arg)

	set_short("YARD 4 short");
	set_long("YARD 4 long");
	set_light(3);
	
	dir_temp = file_name(this_object());
   	sscanf(dir_temp, "/data/stronghold/stronghold_%d/yard/sh_yard%d#%d", sh_number,i,temp_int);

	add_exit("west","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard3");
	add_exit("east","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard5");
	
	
}