/* STRONGHOLD - sh_yard1.c by astarel */

inherit "room/room";

void reset(status arg) {

string dir_temp;
int sh_number;
int i;
int temp_int;
	if(arg)

	set_short("YARD 1 short");
	set_long("YARD 1 long");
	set_light(3);
	
	dir_temp = file_name(this_object());
   	sscanf(dir_temp, "/data/stronghold/stronghold_%d/yard/sh_yard%d#%d", sh_number,i,temp_int);

	add_exit("north","/data/stronghold/stronghold_"+sh_number+"/rooms/room2");
	add_exit("south","/data/stronghold/stronghold_"+sh_number+"/offices/sh_mines_office");
	add_exit("west","/data/stronghold/stronghold_"+sh_number+"/offices/sh_farm_office");
	add_exit("east","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard0");
	add_exit("northwest","/data/stronghold/stronghold_"+sh_number+"/offices/sh_military_office");
	add_exit("southwest","/data/stronghold/stronghold_"+sh_number+"/offices/sh_caravan_office");
	
}
	