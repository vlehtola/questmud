#include <ansi.h>

inherit "obj/food";

reset(arg) {
::reset(arg);
if (arg) { return; }
set_name("fixer");
set_alias("hsum_fixer");
set_short("A horde summon fixer");
set_long("A hsum fixer, for wizs only. 'hsfix <player>'.\n");
set_weight(10);
set_value(1);
set_strength(2100);
}

set_id(arg) {
    return name == arg;
}

init()
{
 add_action("hsfix", "hsfix");
}

hsfix(str)
{
 object player, horde, locate_ob;
 
 player = find_player(str);

 if(!player)
	{
	 write("Error. No such player.\n");
	 return 1;
	}

 horde = present("horde", environment(player) );

 if(!horde)
	{
	 write("Error. No horde in players env.\n");
	 return 1;
	}

 locate_ob = clone_object("/guilds/necro/obj/locate_ob");

 if(!locate_ob)
	{
	 write("Error. Unable to clone locate_ob.\n");
	 return 1;
	}

 move_object(locate_ob, player);

 locate_ob->start(horde);
 write("Ok.\n");
}
