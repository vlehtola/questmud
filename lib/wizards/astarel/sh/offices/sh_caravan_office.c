/* STRONGHOLD - sh_caravan_office.c by astarel */

inherit "room/room";

void reset(status arg) {

string dir_temp;
int sh_number;
int i;
int temp_int;
	if(arg)

	set_short("MINES short");
	set_long("MINES long");
	set_light(3);
	
	dir_temp = file_name(this_object());
   	sscanf(dir_temp, "/data/stronghold/stronghold_%d/shops/sh_caravan_office%d#%d", sh_number,i,temp_int);

	add_exit("out","/data/stronghold/stronghold_"+sh_number+"/yard/sh_yard1");
	
	
	
}