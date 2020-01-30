inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
     load_plaque();
     if (arg) { return; }
     if (!items) {
         items = allocate(6);
         items[0] = "shelves";
         items[1] = "These book shelves are full of books";
         items[2] = "books";
         items[3] = "You pick the first book from the shelve and open it.\n" +
                    "You ruffle though the introduction and suddenly find something interesting:\n" +
                    "    Spell words for earth bolt are 'exs sol blt'";
         items[4] = "lamps";
         items[5] = "These lamps are somekind of crystal spheres that hold something\n" +
                    "emitting bright light inside them";
     }
     set_not_out(1);
     set_light(3);
  short_desc = "The advanced Mages guild";
  long_desc =
"The advanced mage guild hall.\n"+
"This is the guild where Essence casters get a more profound teaching about\n"+
"their powers. There are book shelves full of books on the sides of the\n"+
"hall. The place is well lit with some strange lamps that are hanging\n"+
"from the ceiling and glowing bright magical light.\n";
  add_exit("up", "/guilds/mage/tower3");
  add_exit("down", "/guilds/mage/tower2");
}

init() {
  ::init();
  guild_init();
}

guild_max_level() {
  return 20;
}

guild_name() {
    return "Advanced Mages";
}

check_joining_rec() {
    if (this_player()->query_guild_level("Apprentice mages") != 20) {
        write("Must have completed the Apprentice Mages first.\n");
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
      skill += (["mental unity": (int) 100]);
      skill += (["chanting":(int) 35]);
      skill += (["mana control":(int) 50]);
      skill += (["cast essence":(int) 60]);
      skill += (["cast bolt":(int) 70]);
      skill += (["cast earth":(int) 100]);
      skill += (["cast create":(int) 70]);
      skill += (["cast storm":(int) 10]);
      skill += (["power channeling":(int) 25]);
      skill += (["power focusing":(int) 30]);
      skill += (["power concentration":(int) 10]);
      skill += (["meditate":(int) 10]);
      skill += (["soul heal":(int) 10]);
    }
     if (guild_level >= 2) {
      skill += (["cast storm":(int) 15]);
      skill += (["power concentration":(int) 15]);
      skill += (["meditate":(int) 20]);
      skill += (["soul heal":(int) 20]);
    }
    if (guild_level >= 3) {
      skill += (["cast storm":(int) 20]);
      skill += (["power focusing":(int) 35]);
      skill += (["meditate":(int) 30]);
      skill += (["soul heal":(int) 30]);
    }
    if (guild_level >= 4) {
      skill += (["cast create":(int) 55]);
      skill += (["power concentration":(int) 20]);
      skill += (["meditate":(int) 40]);
      skill += (["soul heal":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["chanting":(int) 40]);
      skill += (["mana control":(int) 55]);
      skill += (["cast storm":(int) 25]);
      skill += (["power channeling":(int) 30]);
      skill += (["meditate":(int) 50]);
      skill += (["soul heal":(int) 50]);
    }
    if (guild_level >= 6) {
      skill += (["cast essence":(int) 65]);
      skill += (["power focusing":(int) 40]);
      skill += (["power concentration":(int) 25]);
      skill += (["soul heal":(int) 60]);
    }
    if (guild_level >= 7) {
      skill += (["cast create":(int) 60]);
      skill += (["soul heal":(int) 70]);
    }
    if (guild_level >= 8) {
      skill += (["cast bolt":(int) 75]);
      skill += (["cast storm":(int) 30]);
      skill += (["power concentration":(int) 30]);
      skill += (["soul heal":(int) 80]);
    }
    if (guild_level >= 9) {
      skill += (["mana control":(int) 60]);
      skill += (["power channeling":(int) 35]);
      skill += (["power focusing":(int) 45]);
      skill += (["soul heal":(int) 90]);
    }
    if (guild_level >= 10) {
      skill += (["chanting":(int) 45]);
      skill += (["cast essence":(int) 70]);
      skill += (["cast create":(int) 65]);
      skill += (["power concentration":(int) 35]);
      skill += (["soul heal":(int) 100]);
    }
    if (guild_level >= 11) {
      skill += (["cast storm":(int) 35]);
      skill += (["meditate":(int) 60]);
    }
    if (guild_level >= 12) {
      skill += (["cast create":(int) 70]);
      skill += (["power focusing":(int) 50]);
      skill += (["power concentration":(int) 40]);
    }
    if (guild_level >= 13) {
      skill += (["cast bolt":(int) 80]);
      skill += (["power channeling":(int) 40]);
      skill += (["meditate":(int) 70]);
    }
    if (guild_level >= 14) {
      skill += (["chanting":(int) 50]);
      skill += (["cast essence":(int) 75]);
      skill += (["cast storm":(int) 40]);
    }
    if (guild_level >= 15) {
      skill += (["mana control":(int) 65]);
      skill += (["cast create":(int) 75]);
      skill += (["power focusing":(int) 55]);
      skill += (["power concentration":(int) 45]);
    }
    if (guild_level >= 16) {
    }
    if (guild_level >= 17) {
      skill += (["cast create":(int) 80]);
      skill += (["cast storm":(int) 45]);
      skill += (["power channeling":(int) 45]);
      skill += (["meditate":(int) 80]);
    }
    if (guild_level >= 18) {
      skill += (["chanting":(int) 55]);
      skill += (["cast essence":(int) 80]);
      skill += (["power focusing":(int) 60]);
      skill += (["power concentration":(int) 50]);
    }
    if (guild_level >= 19) {
      skill += (["meditate":(int) 90]);
    }
    if (guild_level >= 20) {
      skill += (["chanting":(int) 60]);
      skill += (["mana control":(int) 70]);
      skill += (["cast bolt":(int) 100]);
      skill += (["cast create":(int) 100]);
      skill += (["cast storm":(int) 50]);
      skill += (["power channeling":(int) 50]);
      skill += (["power focusing":(int) 65]);
      skill += (["power concentration":(int) 55]);
      skill += (["meditate":(int) 100]);
    }
return skill;
}

