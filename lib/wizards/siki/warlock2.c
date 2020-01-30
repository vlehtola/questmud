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
/*
This large area is cold. The walls are black and carved in an elaborate relief that gives the
impression of writhing tentacles. The floor is covered in a woven mat of dried, purple seaweed
that is occasionally stained with reddish blood. Dark chaos banners painted on sewn sheets of
scaly flesh adorn the walls. They are showing scenes of battles, bloodlust and inhuman depraviry.
Near the middle of the western wall lies a pile of small bones, many of them appear to be human
bones, but others belonged to larger beasts. This place smells particulary sour, and the pressure
of air feels quite depressing and chaotic.




*/
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
demonology 40% ->100%
knowledge of summoning -> 60% 100
knowledge of chaos -> 40% -> 80%
cast draw chaos 80% -> 100%
cast aura of menace 60% -> 100%
cast chaos demon 80% -> 100%
cast chaos blessing 40% -> 80%
cast cast cure evil 60% 100%
cast lesser chaos 80% -> 100%
cast minor chaos 0% -> 80%
cast chaos weapon 40% -> 100%
*/

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  if (guild_level >= 1) {
  skill += (["demonology":(int) 45]);
  skill += (["knowledge of summoning":(int) 65]);
  skill += (["cast draw chaos":(int) 85]);
  skill += (["cast aura of menace":(int) 65]);
  skill += (["cast chaos demon":(int) 85]);
  skill += (["cast cure evil":(int) 65]);
  skill += (["cast lesser chaos":(int) 85]);
  skill += (["cast chaos weapon":(int) 45]);
  }
  if (guild_level >= 2) {
  skill += (["demonology":(int) 50]);
  skill += (["knowledge of summoning":(int) 70]);
  skill += (["cast draw chaos":(int) 90]);
  skill += (["cast aura of menace":(int) 70]);
  skill += (["cast chaos demon":(int) 90]);
  skill += (["cast cure evil":(int) 70]);
  skill += (["cast lesser chaos":(int) 90]);
  skill += (["cast chaos weapon":(int) 50]);
  }
  if (guild_level >= 3) {
  skill += (["demonology":(int) 55]);
  skill += (["knowledge of summoning":(int) 75]);
  skill += (["cast draw chaos":(int) 95]);
  skill += (["cast aura of menace":(int) 75]);
  skill += (["cast chaos demon":(int) 95]);
  skill += (["cast cure evil":(int) 75]);
  skill += (["cast lesser chaos":(int) 95]);
  skill += (["cast chaos weapon":(int) 55]);
  }
  if (guild_level >= 4) {
  skill += (["demonology":(int) 60]);
  skill += (["knowledge of summoning":(int) 80]);
  skill += (["cast draw chaos":(int) 100]);
  skill += (["cast aura of menace":(int) 90]);
  skill += (["cast chaos demon":(int) 100]);
  skill += (["cast cure evil":(int) 80]);
  skill += (["cast lesser chaos":(int) 100]);
  skill += (["cast chaos weapon":(int) 60]);
  }
  if (guild_level >= 5) {
  skill += (["demonology":(int) 65]);
  skill += (["knowledge of summoning":(int) 85]);
  skill += (["cast aura of menace":(int) 95]);
  skill += (["cast cure evil":(int) 85]);
  skill += (["cast chaos weapon":(int) 65]);
  }
  if (guild_level >= 6) {
  skill += (["demonology":(int) 70]);
  skill += (["knowledge of summoning":(int) 90]);
  skill += (["cast aura of menace":(int) 100]);
  skill += (["cast cure evil":(int) 90]);
  skill += (["cast chaos weapon":(int) 70]);
  }
  if (guild_level >= 7) {
  skill += (["demonology":(int) 75]);
  skill += (["knowledge of summoning":(int) 95]);
  skill += (["cast cure evil":(int) 95]);
  skill += (["cast chaos weapon":(int) 75]);
  }
  if (guild_level >= 8) {
  skill += (["demonology":(int) 80]);
  skill += (["knowledge of summoning":(int) 100]);
  skill += (["cast cure evil":(int) 100]);
  skill += (["cast chaos weapon":(int) 80]);
  }
  if (guild_level >= 9) {
  skill += (["demonology":(int) 85]);
  skill += (["cast chaos weapon":(int) 85]);
  }
  if (guild_level >= 10) {
  skill += (["demonology":(int) 90]);
  skill += (["cast chaos weapon":(int) 90]);
  }
  if (guild_level >= 11) {
  skill += (["demonology":(int) 95]);
  skill += (["cast chaos weapon":(int) 95]);
  }
  if (guild_level >= 12) {
  skill += (["demonology":(int) 100]);
  skill += (["cast chaos weapon":(int) 100]);
  }
    skill += (["cast minor chaos":guild_level*4+20]);
    skill += (["cast chaos blessing":guild_level*4+20]);
    skill += (["chaos strike":guild_level*4+20]);
  return skill;
}