/* STRONGHOLD - sh_yard7.c by astarel */

inherit "room/room";

void reset(status arg) {

string dir_temp;
int sh_number;
int i;
int temp_int;
	if(arg)

	set_short("YARD 7 short");
	set_long("YARD 7 long");
	set_light(3);
	
	dir_temp = file_name(this_object());
   	sscanf(dir_temp, "/data/stronghold/stronghold_%d/yard/sh_yard%d#%d", sh_number,i,temp_int);

	add_exit("north","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard6");
	add_exit("south","/data/stronghold/stronghold_"+sh_number+"/shops/sh_general_store");
	add_exit("east","/data/stronghold/stronghold_"+sh_number+"/shops/sh_weapon_shop");
	add_exit("southeast","/data/stronghold/stronghold_"+sh_number+"/shops/sh_armor_shop");
	add_exit("west","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard0");
	
}