inherit "guilds/guilds/guild";
inherit "room/room";
#define WARLOCK_D "/daemons/warlock_d"
reset(arg) {
  load_plaque();
  if(arg) return;
  short_desc = "The secret guild of warlocks";
  long_desc = "This is the secret guild of warlocks. DO NOT JOIN YET!.\n";

  add_exit("out","/guilds/warlock/cathedral/room8");
  set_not_out(1);
  set_light(3);
}

guild_max_level() {
  return 20;
}

guild_name() {
    return "Chaos masters";
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
    return 0;
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
  return skill;
}