inherit "guilds/guilds/guild";
inherit "room/room";
#define WARLOCK_D "/daemons/warlock_d"
reset(arg) {
  load_plaque();
  if(arg) return;
  short_desc = "The Grand warlocks guild";
  long_desc = "The stench in this chamber is incredible, mixing offal, corpses, and ash into a truly foul "+
"concoction. The floor is covered in waste and shattered bones. Several piles of ash burnt "+
"wood are also visible. A low, gutteral growling sound fills the air. It seems to echo off "+
"the walls decored from bones of demons and come from every direction at once, making the "+
"effect of that they are still alive. A huge somekind of torch holder is placed hanging on "+
"the ceiling with couple of torches burning.\n";

  add_exit("north","/guilds/warlock/cathedral/room4");
  items = allocate(14);
  items[0] = "corpses";
  items[1] = "On the floor is lots of corpses, some of them are demon corpses but some are died warlocks that tried to summon something much bigger that they can handle";
  items[2] = "ash";
  items[3] = "The ash is propaply came from the torches that are burning in that torch holder or from some unlucky warlock that failed to control the demon";
  items[4] = "walls";
  items[5] = "The walls are echoing a low gutteral growling sound. The walls are made from black marble which is decorated with bodys of demons and warlocks";
  items[6] = "holder";
  items[7] = "A large iron torch holder is placed hanging on the ceiling. At the holder is burning two bright torchers that makes shadows on the floor";
  items[8] = "torches";
  items[9] = "The torches are burning on the holder giving light to this dark and chaotic chamber";
  items[10] = "offal";
  items[11] = "The floor is full of them, and ashes, and corpses";
  items[12] = "floor";
  items[13] = "On the floor is lots of corpses, some of them are demon corpses but some are died warlocks that tried to summon something much bigger that they can handle";
  set_not_out(1);
  set_light(3);
}

guild_max_level() {
  return 10;
}

guild_name() {
    return "Grand warlocks";
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
  return "int 3 , con 2 , ";
}

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  skill += (["cast anvil of chaos":guild_level*10]); //100%
  skill += (["cast blessing of chaos":guild_level*10]); //100%
  skill += (["cast void travel":guild_level*10]); //100%
  return skill;
}