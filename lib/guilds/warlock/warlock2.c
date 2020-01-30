inherit "guilds/guilds/guild";
inherit "room/room";
#define WARLOCK_D "/daemons/warlock_d"
reset(arg) {
  load_plaque();
  if(arg) return;
  short_desc = "The guild of Initiates of Chaos";
  long_desc = "This large area is cold. The walls are black and carved in an elaborate relief that gives the "+
"impression of writhing tentacles. The floor is covered in a woven mat of dried, purple seaweed "+
"that is occasionally stained with reddish blood. Dark chaos banners painted on sewn sheets of "+
"scaly flesh adorn the walls. They are showing scenes of battles, bloodlust and inhuman depraviry. "+
"Near the middle of the western wall lies a pile of small bones, many of them appear to be human "+
"bones, but others belonged to larger beasts. This place smells particulary sour, and the pressure "+
"of air feels quite depressing and chaotic.\n";

  add_exit("east","/guilds/warlock/cathedral/room3");
  items = allocate(4);
  items[0] = "item1";
  items[1] = "The altar seems to made from somekind of black marble.\nOn the altar reads: worship, sacrifice, invite";
  items[2] = "item2";
  items[3] = "The status is made from black marble with faint streaks of red running thourgh it. It feels quite cold";
}

guild_max_level() {
  return 20;
}

guild_name() {
    return "Initiate of chaos";
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
    if(this_player()->query_guild_level("Warlocks") != 20) {
	write("You need to max out the 'warlock' guild first.\n");
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
  return "str 3 , int 1 , ";
}
/*
essence of chaos 40% ->100%
knowledge of summoning -> 60% 100
knowledge of chaos -> 40% -> 80%
cast plane of chaos 80% -> 100%
cast chaos sheltering 60% -> 100%
cast beast control 80% -> 100%
cast chaos blessing 40% -> 80%
cast cast warmth of chaos 60% 100%
cast lesser chaos 80% -> 100%
cast minor chaos 0% -> 80%
cast anvil of chaos 40% -> 100%
*/

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  if (guild_level >= 1) {
  skill += (["essence of chaos":(int) 45]);
  skill += (["knowledge of summoning":(int) 65]);
  skill += (["cast plane of chaos":(int) 85]);
  skill += (["cast chaos sheltering":(int) 65]);
  skill += (["cast beast control":(int) 85]);
  skill += (["cast warmth of chaos":(int) 65]);
  skill += (["cast lesser chaos":(int) 85]);
  skill += (["cast anvil of chaos":(int) 45]);
  }
  if (guild_level >= 2) {
  skill += (["essence of chaos":(int) 50]);
  skill += (["knowledge of summoning":(int) 70]);
  skill += (["cast plane of chaos":(int) 90]);
  skill += (["cast chaos sheltering":(int) 70]);
  skill += (["cast beast control":(int) 90]);
  skill += (["cast warmth of chaos":(int) 70]);
  skill += (["cast lesser chaos":(int) 90]);
  skill += (["cast anvil of chaos":(int) 50]);
  }
  if (guild_level >= 3) {
  skill += (["essence of chaos":(int) 55]);
  skill += (["knowledge of summoning":(int) 75]);
  skill += (["cast plane of chaos":(int) 95]);
  skill += (["cast chaos sheltering":(int) 75]);
  skill += (["cast beast control":(int) 95]);
  skill += (["cast warmth of chaos":(int) 75]);
  skill += (["cast lesser chaos":(int) 95]);
  skill += (["cast anvil of chaos":(int) 55]);
  }
  if (guild_level >= 4) {
  skill += (["essence of chaos":(int) 60]);
  skill += (["knowledge of summoning":(int) 80]);
  skill += (["cast plane of chaos":(int) 100]);
  skill += (["cast chaos sheltering":(int) 90]);
  skill += (["cast beast control":(int) 100]);
  skill += (["cast warmth of chaos":(int) 80]);
  skill += (["cast lesser chaos":(int) 100]);
  skill += (["cast anvil of chaos":(int) 60]);
  }
  if (guild_level >= 5) {
  skill += (["essence of chaos":(int) 65]);
  skill += (["knowledge of summoning":(int) 85]);
  skill += (["cast chaos sheltering":(int) 95]);
  skill += (["cast warmth of chaos":(int) 85]);
  skill += (["cast anvil of chaos":(int) 65]);
  }
  if (guild_level >= 6) {
  skill += (["essence of chaos":(int) 70]);
  skill += (["knowledge of summoning":(int) 90]);
  skill += (["cast chaos sheltering":(int) 100]);
  skill += (["cast warmth of chaos":(int) 90]);
  skill += (["cast anvil of chaos":(int) 70]);
  }
  if (guild_level >= 7) {
  skill += (["essence of chaos":(int) 75]);
  skill += (["knowledge of summoning":(int) 95]);
  skill += (["cast warmth of chaos":(int) 95]);
  skill += (["cast anvil of chaos":(int) 75]);
  }
  if (guild_level >= 8) {
  skill += (["essence of chaos":(int) 80]);
  skill += (["knowledge of summoning":(int) 100]);
  skill += (["cast warmth of chaos":(int) 100]);
  skill += (["cast anvil of chaos":(int) 80]);
  }
  if (guild_level >= 9) {
  skill += (["essence of chaos":(int) 85]);
  skill += (["cast anvil of chaos":(int) 85]);
  }
  if (guild_level >= 10) {
  skill += (["essence of chaos":(int) 90]);
  skill += (["cast anvil of chaos":(int) 90]);
  }
  if (guild_level >= 11) {
  skill += (["essence of chaos":(int) 95]);
  skill += (["cast anvil of chaos":(int) 95]);
  }
  if (guild_level >= 12) {
  skill += (["essence of chaos":(int) 100]);
  skill += (["cast anvil of chaos":(int) 100]);
  }
    skill += (["cast minor chaos":guild_level*4+20]);
    skill += (["chaos strike":guild_level*4+20]);
    skill += (["soul channeling":guild_level*3]);
    skill += (["cast forge of chaos":guild_level*4+20]);
  return skill;
}