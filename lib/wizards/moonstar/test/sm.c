inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  set_not_out(1);
  set_light(3);
  add_exit("south","/world/shops/weapon_shop");
  short_desc = "The smith training area";
  long_desc =
"Located next to the smithy, this place is not very\n"+
"different from the actual smithy. Sweaty men wearing leather\n"+
"produce different weapons and tools learning to get their\n"+
"craft better.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 2;
}

guild_name() {
    return "Smith";
}
check_joining_rec() {
    if(this_player()->query_guild_level("Warriors") < 5) {
        write("You must have completed the Warriors guild first.\n");
        return 0;
    }
if(this_player()->query_guild_level("martial arts") < 15 {
write("You must have completed the 15 levels from martial artist first.\n");
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
  return "str 1 , con 2 , ";
}

skill_list(int guild_level) {

  mapping skill;
    skill = ([ ]);

    if (guild_level >= 1) {
      skill += (["repair weapon":(int) 50]);
      skill += (["sharpen":(int) 40]);
      skill += (["polish":(int) 40]);
    }
    if (guild_level >= 2) {
      skill += (["repair weapon":(int) 100]);
      skill += (["sharpen":(int) 100]);
      skill += (["polish":(int) 100]);
    }
  return skill;
}

