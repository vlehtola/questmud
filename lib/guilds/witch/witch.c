inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  if(arg) return;
  add_exit("west","/wizards/neophyte/swamp/swamp4");
  add_exit("east","/wizards/neophyte/swamp/swamp3");
  add_exit("north","/wizards/neophyte/swamp/shop");
  short_desc = "The Witch Guild";
  long_desc = "You have entered a guild hut of witches. The whole hut is full of\n"+
              "smoke. Center of the hall is large cauldron where seem to be boiling\n"+
              "something. On the floor is small pieces of herbs.\n";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 30;
}

guild_name() {
    return "witches";
}

check_joining_rec() {
    return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  return sk;
}

get_bonuses(level) {
  return "wis 3 , int 2 , ";
}

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
  skill += (["create vial":guild_level*3]);
  skill += (["summon cauldron":guild_level*3]);
  skill += (["search herbs":guild_level*3]);
  skill += (["extract blood":guild_level*3]);
  skill += (["prepare potion":guild_level*3]);
  skill += (["identify vial":guild_level*3]);
  skill += (["make potion":guild_level*3]);
  skill += (["throw vial":guild_level*3]);
  skill += (["lubricate vial":guild_level*3]);
  skill += (["identify herb":guild_level*3]);
  skill += (["herbs knowledge":guild_level*3]);
  skill += (["speedcrafting":guild_level*3]);

    if (guild_level >= 30) {
      skill += (["create vial":(int) 100]);
      skill += (["summon cauldron":(int) 100]);
      skill += (["search herbs":(int) 100]);
      skill += (["extract blood":(int) 100]);
      skill += (["prepare potion":(int) 100]);
      skill += (["identify vial":(int) 100]);
      skill += (["make potion":(int) 100]);
      skill += (["throw vial":(int) 100]);
      skill += (["lubricate vial":(int) 100]);
      skill += (["identify herb":(int) 100]);
      skill += (["herbs knowledge":(int) 100]);
      skill += (["speedcrafting":(int) 100]);
    }
  return skill;
}

