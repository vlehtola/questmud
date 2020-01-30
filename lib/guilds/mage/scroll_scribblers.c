inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
     load_plaque();
     if (arg) { return; }
     if (!items) {
         items = allocate(6);
     }
     set_not_out(1);
     set_light(3);
  short_desc = "The scroll scribblers guild";
  long_desc =
"The scroll scribblers guild is the place where all the most advanced mages come\n"+
"to study. The room is full of different sized shelves, with lots of intresting\n"+
"looking scrolls placed in the shelf. A large wooden table is center of the room\n"+
"and three candlers are placed on it, the flames of candles are moving slightly\n"+
"in the wind. The table is full of mysteries looking people reading a scrolls\n"+
"and mumbling together.\n";
  add_exit("south", "master_mage");
         items = allocate(6);
         items[0] = "shelves";
         items[1] = "The shelves are full of different looking scrolls";
         items[2] = "table";
         items[3] = "The table looks like made from old mahongy and on it is small piles of candle wax";
         items[4] = "people";
         items[5] = "The people consists a almost every race know'n in deleria and couple of unknown people";
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 6;
}

guild_name() {
    return "Scroll scribblers";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Master Mages") != 10) {
        write("Must have completed the Master Mages first.\n");
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
  /* yhteensa 5 stattia / levelli */
  return "int 2 , ";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }
    if (guild_level >= 1) {
      skill += (["create scroll":(int) 20]);
      skill += (["scribble":(int) 20]);
      skill += (["literacy":(int) 20]);
      skill += (["clear scroll":(int) 20]);
    }
    if (guild_level >= 2) {
      skill += (["create scroll":(int) 40]);
      skill += (["scribble":(int) 40]);
      skill += (["clear scroll":(int) 40]);
      skill += (["literacy":(int) 40]);
    }
    if (guild_level >= 3) {
      skill += (["create scroll":(int) 60]);
      skill += (["scribble":(int) 60]);
      skill += (["clear scroll":(int) 60]);
      skill += (["literacy":(int) 60]);
    }
    if (guild_level >= 4) {
      skill += (["create scroll":(int) 80]);
      skill += (["scribble":(int) 80]);
      skill += (["clear scroll":(int) 80]);
      skill += (["literacy":(int) 80]);
    }
    if (guild_level >= 5) {
      skill += (["create scroll":(int) 100]);
      skill += (["scribble":(int) 100]);
      skill += (["clear scroll":(int) 100]);
      skill += (["literacy":(int) 100]);
    }
return skill;
}

