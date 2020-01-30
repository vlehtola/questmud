/* STRONGHOLD - sh_yard5.c by astarel */

inherit "room/room";

void reset(status arg) {

string dir_temp;
int sh_number;
int i;
int temp_int;
	if(arg)

	set_short("YARD 5 short");
	set_long("YARD 5 long");
	set_light(3);
	
	dir_temp = file_name(this_object());
   	sscanf(dir_temp, "/data/stronghold/stronghold_%d/yard/sh_yard%d#%d", sh_number,i,temp_int);

	
	add_exit("south","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard6");
	add_exit("west","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard4");
	add_exit("northeast","/data/stronghold/stronghold_"+sh_number+"/buildings/sh_warehouse");
	
}