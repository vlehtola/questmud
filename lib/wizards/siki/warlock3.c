inherit "guilds/guilds/guild";
inherit "room/room";
#define WARLOCK_D "/daemons/warlock_d"
reset(arg) {
  load_plaque();
  if(arg) return;
  short_desc = "The Master warlocks guild";
  long_desc = "The power of the Chaos itself flows through this chamber. A demonic skulls are placed hanging "+
"on the walls, and from their eye sockets is dark looking blood constantly dripping to the "+
"ground. The walls are carved from black obsidian and next to the every skull is a iron hook, "+
"with them bearing grisly stains and dried remnants of things that are better left unidentified. "+
"The floor's mazelike pattern is gouged with deep lines that lead the the eastern wall, where "+
"are the statue of grinning looking demonic woman. The statue is holding a grinning demon skull which "+
"is filled with somekind of dark matter, propably blood.\n";
  add_exit("west","/guilds/warlock/cathedral/room7");
  items = allocate(6);
  items[0] = "skulls";
  items[1] = "The skulls are placed hanging on the walls and they look quite fiendish with the blood flowing from them";
  items[2] = "walls";
  items[3] = "The walls are carved from black obsidian making this chamber even more chaotic. A demonic skulls and iron hooks with remnants of previous victims are placed on the walls to show glory or despair";
  items[4] = "statue";
  items[5] = "The statue is presenting a former warlock elder which died horribly when tried to summon the arch-demon but she failed misarbely. The statue is holding a demon skull on her right hand which is filled with darknish blood";
set_not_out(1);
set_light(3);
}

guild_max_level() {
  return 20;
}

guild_name() {
    return "Master warlocks";
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
    if(this_player()->query_guild_level("Initiate of chaos") != 20) {
	write("You need to max out the 'Initiate of chaos' guild first.\n");
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
  return "con 2 , int 2 , ";
}

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  skill += (["cast greater chaos":guild_level*5]); //100%
  skill += (["knowledge of chaos":guild_level*4+20]);
    if (guild_level >= 1) {
	skill += (["cast chaos blessing":(int) 80]);
	skill += (["cast minor chaos":(int) 85]);
    }
    if (guild_level >= 2) {
	skill += (["cast chaos blessing":(int) 85]);
	skill += (["cast minor chaos":(int) 90]);
    }
    if (guild_level >= 3) {
	skill += (["cast chaos blessing":(int) 90]);
	skill += (["cast minor chaos":(int) 95]);
    }
    if (guild_level >= 4) {
	skill += (["cast chaos blessing":(int) 95]);
	skill += (["cast minor chaos":(int) 100]);
    }
    if (guild_level >= 5) {
	skill += (["cast chaos blessing":(int) 100]);
    }

  return skill;
}