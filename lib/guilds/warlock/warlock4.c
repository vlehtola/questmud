inherit "guilds/guilds/guild";
inherit "room/room";
#define WARLOCK_D "/daemons/warlock_d"
reset(arg) {
  load_plaque();
  if(arg) return;
  short_desc = "The Chaos fighters guild";
  long_desc = "This chamber is dust-coated and filled with cob-webs, the table running down the center of this chamber "+
"is covered with weapons, as are the racks on the walls. All the weapons have strange runes carved on the blades, "+
"leering demons, skulls, and evil symbols embossed on the hilts and worked into the design of chaos fighters. "+
"The south wall of this chamber bears a painted relief showing the chaos fighters using an elaborate axes "+
"to sacrifice something to the dark gods. A lots of bones are littering on the floor, and long chains ending "+
"in hooks hang from the ceiling, making the illusion of chaotic tortures. This chamber is filled with "+
"sharp odor heavier then any other chamber, the odor smells likes a rottening flesh.\n";
  add_exit("north","/guilds/warlock/cathedral/room8");
  items = allocate(6);
  items[0] = "table";
  items[1] = "The table is made from somekind of dark wood. The table is filled with different kind of chaos weapons";
  items[2] = "weapons";
  items[3] = "They are chaos weapons which warlocks use when they are fighting some-one or something. All the weapons have different runes, pictures or relief painted on them";
  items[4] = "relief";
  items[5] = "The painted relief shows a scene of chaos fighters fighting with somekind of demonic creature propably somekind of greater demon";
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Chaos fighters";
}

init() {
  ::init();
  guild_init();
}

check_joining_rec() {
	if(this_player()->query_alignment() >=0) {
	write("We don't wan't you goodies here!\n");
	return 0;
    }
    if(this_player()->query_guild_level("Master warlocks") != 20) {
	write("You need to max out the 'Master warlocks' guild first.\n");
	return 0;
}
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;
}

get_bonuses(level) {
  return "str 2 , con 2 , ";
}

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  skill += (["chaos bludgeons":guild_level*10]); //100%
  skill += (["chaos blades":guild_level*10]); //100%
  skill += (["chaos axes":guild_level*10]); //100%
  skill += (["doublehit":guild_level*10]); //100%
  return skill;
}