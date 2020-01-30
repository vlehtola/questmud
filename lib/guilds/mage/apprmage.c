inherit "guilds/guilds/guild";
inherit "room/room";

reset(arg) {
     load_plaque();
     if (!present("talos")) {
        move_object(clone_object("/guilds/mage/monsters/appr_master"),this_object());
     }
     if (arg) { return; }
     if (!items) {
         items = allocate(6);
         items[0] = "shelves";
         items[1] = "These book shelves are full of books. You can get a new spellbook, if you\n"+
                    "have lost your previous one, by typing 'get_book_back'.\n";
         items[2] = "books";
         items[3] = "You pick the first book from the shelve and open it.\n" +
                    "You ruffle though the introduction and suddenly find something interesting:\n" +
                    "    Spell words for 'create food' are 'exs sol cre'";
         items[4] = "lamps";
         items[5] = "These lamps are somekind of crystal spheres that hold something\n" +
                    "emitting bright light inside them";
     }
     set_not_out(1);
     set_light(3);
  short_desc = "The apprentice Mage guild";
  long_desc =
         "The apprentice Mage guild hall.\n"+
         "This is the guild where all Essence casters start their search for\n"+
         "power. There are book shelves full of books on the sides of the hall.\n" +
         "Five long shelves labelled 'Spellbooks' seem to attract attention.\n"+
         "The place is well lit with some strange lamps that are hanging\n" +
         "from the ceiling and glowing bright magical light.\n" +
         "The streets of Duranghom lie to the east.\n";
  add_exit("east", "world/city/emerald6");
  add_exit("south", "/guilds/battlemage/baseguild");
}

init() {
  ::init();
  guild_init();
  add_action("get_book_back", "get_book_back");
}

guild_max_level() {
  return 20;

}

guild_name() {
    return "Apprentice Mages";
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
  /* yhteensa 5 stattia / levelli */
  return "int 2 , ";
}

skill_list(int guild_level) {
    mapping skill;
    skill = ([ ]);
         if (guild_level > guild_max_level()) { guild_level = guild_max_level(); }

    if (guild_level >= 1) {
      skill += (["chanting":(int) 10]);
      skill += (["mana control":(int) 10]);
      skill += (["cast essence":(int) 30]);
      skill += (["cast bolt":(int) 30]);
      skill += (["cast earth":(int) 30]);
      skill += (["power channeling":(int) 10]);
    }
    if (guild_level >= 2) {
      skill += (["mana control":(int) 15]);
      skill += (["cast bolt":(int) 35]);
    }
    if (guild_level >= 3) {
      skill += (["cast essence":(int) 35]);
      skill += (["cast earth":(int) 35]);
    }
    if (guild_level >= 4) {
      skill += (["mana control":(int) 20]);
      skill += (["cast bolt":(int) 40]);
    }
    if (guild_level >= 5) {
      skill += (["cast essence":(int) 40]);
      skill += (["power focusing":(int) 5]);
      skill += (["cast earth":(int) 40]);
    }
    if (guild_level >= 6) {
      skill += (["mana control":(int) 25]);
    }
    if (guild_level >= 7) {
      skill += (["chanting":(int) 15]);
      skill += (["cast bolt":(int) 45]);
    }
    if (guild_level >= 8) {
      skill += (["mana control":(int) 30]);
      skill += (["cast earth":(int) 50]);
      skill += (["power focusing":(int) 10]);
    }
    if (guild_level >= 9) {
      skill += (["cast essence":(int) 45]);
      skill += (["power concentration":(int) 5]);
    }
    if (guild_level >= 10) {
      skill += (["cast bolt":(int) 55]);
    }
    if (guild_level >= 11) {
      skill += (["mana control":(int) 35]);
      skill += (["cast ice":(int) 10]);
      skill += (["cast fire":(int) 10]);
      skill += (["power focusing":(int) 15]);
      skill += (["cast earth":(int) 60]);
    }
    if (guild_level >= 12) {
      skill += (["chanting":(int) 20]);
      skill += (["power channeling":(int) 15]);
    }
    if (guild_level >= 13) {
      skill += (["cast essence":(int) 50]);
      skill += (["cast bolt":(int) 60]);
    }
    if (guild_level >= 14) {
      skill += (["mana control":(int) 40]);
      skill += (["cast fire":(int) 15]);
      skill += (["cast ice":(int) 15]);
      skill += (["power focusing":(int) 20]);
    }
    if (guild_level >= 15) {
      skill += (["cast earth":(int) 70]);
      skill += (["cast create":(int) 25]);
    }
    if (guild_level >= 16) {
      skill += (["chanting":(int) 25]);
      skill += (["cast bolt":(int) 65]);
    }
    if (guild_level >= 17) {
      skill += (["cast essence":(int) 55]);
      skill += (["cast ice":(int) 20]);
      skill += (["cast fire":(int) 20]);
      skill += (["power focusing":(int) 25]);

    }
    if (guild_level >= 18) {
      skill += (["mana control":(int) 45]);
      skill += (["cast create":(int) 35]);
    }
    if (guild_level >= 19) {
    }
    if (guild_level >= 20) {
      skill += (["chanting":(int) 30]);
      skill += (["mana control":(int) 50]);
      skill += (["cast essence":(int) 60]);
      skill += (["cast bolt":(int) 70]);
      skill += (["cast earth":(int) 100]);
      skill += (["cast ice":(int) 25]);
      skill += (["cast fire":(int) 25]);
      skill += (["cast create":(int) 45]);

      skill += (["power concentration":(int) 10]);
      skill += (["power focusing":(int) 30]);
      skill += (["power channeling":(int) 20]);
    }
return skill;
}


special_advance_effect(lvl) {
    object book;

    if (lvl == 2 && !present("spellbook", this_player())) {
write("\nTalos says: 'You will surely need this in the future.'\n");
write("He hands you a spellbook with your name on it.\n\n");

        book = clone_object("/guilds/obj/spellbook.c");
        move_object(book, this_player());
        book->add_spell("earth bolt", "exs sol blt");
    }
    if (lvl == 21) {
write(
"Talos says: 'You already know everything I have to teach you. Seek tuition\n"+
"from the Tower of the Mages'.\n");
write(
"'The tower of the Mages is located southwest from Duranghom in a dense forest.'\n");
   }
}


long(str) {
    ::long(str);
    if (str == "books") {
         if (present("spellbook", this_player())) {
             present("spellbook", this_player())->add_spell("create food",
"exs sol cre");
         }
    }
}

get_book_back() {
    if(this_player()->query_guild_level("apprentice mages") < 2) {
        write("You are not worthy.\n");
        return 1;
    }

    if (!present("spellbook", this_player())) {
        write("You get your book back.\n");
        move_object(clone_object("/guilds/obj/spellbook.c"), this_player());
        return 1;
    }
    write("You all ready have your book.\n");
    return 1;
}

