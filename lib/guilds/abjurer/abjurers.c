inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
  load_plaque();
  set_not_out(1);
  set_light(3);
  if(arg) return;
  add_exit("north","/guilds/abjurer/corridor2.c");
  add_exit("south","/guilds/abjurer/corridor1.c");
  short_desc = "The guild hall of Abjurers";
  long_desc =
"The guild hall of Abjurers is located in the centre of the tower,\n"+
"on the first floor. The walls and the floor are made from the finest marble.\n"+
"Unlike the walls and the floor, the roof, high above you on the top of the\n"+
"tower, is made from thick glass. Through the glass roof can be seen the sky.\n"+
"A huge lustre hanging down from the glass roof, brings light and warmth in\n"+
"here. The shining marble floor is cold. Bookshelves are leaning against\n"+
"the walls, two in both sides, in front eastern and western wall. Wooden\n"+
"chairs and tables are placed in the centre of the hall, forming a circle.\n"+
"The Abjurers can get their tuition from here.\n";

   items = allocate(6);
   items[0] = "lustre";
   items[1] = "The huge lustre, hanging down from the glass-roof, brings light to the hall";
   items[2] = "bookshelves";
   items[3] = "The bookshelves are full of different sized books";
   items[4] = "bookshelf";
   items[5] = "The bookshelf is full of different sized books";
}

init() {
  ::init();
  guild_init();
}

check_joining_rec() {
  int i;
  // fixxed by C, 10.5.04. updated 24.05.

  if (this_player()->query_guild_level("apprentice mages") >= 10)
	i++;
  if (this_player()->query_guild_level("apprentice clerics") >= 10)
	i++;
  if (this_player()->query_guild_level("psionicists") >= 10)
	i++;
  if( i < 2) {
    write("You must meet two of the following requirements:\n"+
		" 1) 10 levels in the apprentice mages guild\n"+
		" 2) 10 levels in the apprentice clerics guild\n"+
		" 3) 10 levels in the psionicists guild\n");
    return 0;
  }

  return 1;
}

check_advance_rec(lev) {
  mapping sk;
  sk = ([ ]);
  sk += ([2:"cast earth:20;cast abjuration:20;cast protection:20;"]);
  return sk;
}

guild_max_level() {
  return 5;
}

guild_name() {
    return "abjurer";
}


get_bonuses(level) {
  return "wis 1 , int 1 , ";
}

skill_list(int guild_level) {
  mapping skill;
  skill = ([ ]);
      if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }

  skill += (["abjuration": guild_level*10 ]);
  skill += (["cast abjuration": guild_level*20 ]);
  skill += (["cast alteration": guild_level*20 ]);
  skill += (["cast earth": guild_level*20 ]);
  skill += (["cast protection": guild_level*20 ]);

  if(guild_level == 5) {
    skill += (["shielding mastery": 15 ]);
  }


return skill;
}
