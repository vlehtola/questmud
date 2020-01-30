#include "/world/guilds/guild.h"
#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

init() {
    ::init();
    add_action("join", "join");
    add_action("advance", "advance");
    add_action("info", "info");
    add_action("list", "list");
    add_action("check_advance_rec", "requirements");
    add_action("train", "train");
    add_action("get_book_back","get_book_back");
}    

extra_reset() {
     object plaque;
     if (!present("plaque")) {
	plaque = clone_object("world/guilds/plaque.c");
     	move_object(plaque, this_object()); 
     }
     if (!items) {
         items = allocate(6);
         items[0] = "shelves";
         items[1] = "These book shelves are full of books";
         items[2] = "books";
         items[3] = "You pick the first book from the shelve and open it.\n" +
                    "You ruffle though the introduction and suddenly find something interesting:\n" +
                    "    Spell words for earth grasp are 'exs sol grs'";
         items[4] = "lamps";
         items[5] = "These lamps are somekind of crystal spheres that hold something\n" + 
                    "emitting bright light inside them";
     }
     set_not_out(1);
}

long(str) {
    ::long(str);
    if (str == "books") {
         if (present("spellbook", this_player())) {
             present("spellbook", this_player())->add_spell("Earth Grasp", "exs sol grs");
         }
    }
}
guild_long_name() {
    return "the Apprentice Mage guild.   ";
}

guild_name() {
    return "Apprentice Mage";
}

check_joining_rec() {
    return 1;
}

guild_max_level() {
    return 10;
}

check_advance_rec(lev) {
    int ii, i, req, req_level;
    string skill;
    req = allocate(10);
    req_level = allocate(10);
    skill = allocate(10);
    if (lev == 2 || !lev) {
        if (this_player()->query_skills(get_num("cast earth")) < 20 || !lev) {
            req[i] = 20; skill[i] = "cast earth";
            req_level[i] = 2;
            i += 1;
        }
        if (this_player()->query_skills(get_num("cast grasp")) < 20 || !lev) {
            req[i] = 20; skill[i] = "cast grasp";
            req_level[i] = 2;
            i += 1;
        }
        if (this_player()->query_skills(get_num("cast essence")) < 10 || !lev) {
            req[i] = 10; skill[i] = "cast essence";
            req_level[i] = 2;
            i += 1;
        }
        if (this_player()->query_skills(get_num("mana control")) < 10 || !lev) {
            req[i] = 10; skill[i] = "mana control";
            req_level[i] = 2;
            i += 1;
        }
    
    }
    if (lev == 6 || !lev) {
        if (this_player()->query_skills(get_num("mana control")) < 30 || !lev) {
            req[i] = 30; skill[i] = "mana control";
            req_level[i] = 6;
            i += 1;
        }
    }
    if (lev == 10 || !lev) {
        if (this_player()->query_skills(get_num("cast essence")) < 40 || !lev) {
            req[i] = 40; skill[i] = "cast essence";
            req_level[i] = 10;
            i += 1;
        }
    }
    while(ii < i) {
        write("Level " + req_level[ii] + ": Must have trained '" + skill[ii] + "' to at least " + req[ii] + "% (" + this_player()->query_skills(get_num(skill[ii])) + "%).\n");
        ii += 1;
    }
    if (i && lev) { return 0; }
    return 1;
}

/*
    25% Int, 20% Wis, 5% Con
*/

get_bonuses(level) {
    if (level == 0) {
        return "int 1 , wis 1 , spregen 2 , ";
    }
    if (level == 1) {
        return "int 2 , con 1 , ";
    }
    if (level == 2) {
        return "con 4 , wis 2 , spregen 1 , ";
    }
    if (level == 3) {
        return "int 2 , wis 2 , ";
    }
    if (level == 4) {
        return "int 1 , wis 1 , spregen 2 , ";
    }
    if (level == 5) {
        return "int 1 , ";
    }
    if (level == 6) {
        return "int 1 , wis 2 , spregen 3 , ";
    }
    if (level == 7) {
        return "int 4 , wis 2";
    }
    if (level == 8) {
        return "int 3 , wis 3";
    }
    if (level == 9) {
        return "int 10 , wis 7 , spregen 10 , ";
    }
}
/*    
   Attack: 30
   Bare hands: 40
   Chanting: 60
   Cast damage: 60
   Cast earth: 60
   Cast grasp: 60
   Mana control: 40
*/

get_skill_max(num, how, lvl) {
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(call_other("/world/guilds/guildfun", "get_guild_number", guild_name()));
    if (lvl) {
         guild_level = lvl;
         if (guild_level > 10) { guild_level = 10; }
         if (guild_level < 1) { guild_level = 1; }
    }
    if (!guild_level) {
        write("Bugged.. not a member\n");
        return 0;
    }
    if (guild_level == 1) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 10;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 30;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 30;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 30;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 10;
    }
    if (guild_level == 2) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 10;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 40;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 40;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 40;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 20;
    }
    if (guild_level == 3) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 10;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 40;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 40;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 50;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 20;
    }
    if (guild_level == 4) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 20;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 40;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 40;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 50;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 30;
    }
    if (guild_level == 5) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 30;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 40;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 50;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 60;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 30;
    }
    if (guild_level == 6) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 40;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 50;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 50;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 60;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 30;
    }
    if (guild_level == 7) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 40;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 50;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 60;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 70;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 30;
    }
    if (guild_level == 8) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 50;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 60;
        skill_num[2] = get_num("cast earth");
        skill_max[2skill_num[4] = get_num("mana control");
        skill_max[4] = 40;
        skill_num[5] = get_num("quick spelling");
        skill_max[5] = 10;
    }
    if (guild_level == 10) {
        skill_max = allocate(6);
        skill_num = allocate(6);
        skill_num[0] = get_num("chanting");
        skill_max[0] = 60;
        skill_num[1] = get_num("cast essence");
        skill_max[1] = 70;
        skill_num[2] = get_num("cast earth");
        skill_max[2] = 60;
        skill_num[3] = get_num("cast grasp");
        skill_max[3] = 100;
        skill_num[4] = get_num("mana control");
        skill_max[4] = 50;
        skill_num[5] = get_num("quick spelling");
        skill_max[5] = 20;
    }                  
    if (how == 0) {
        while (i < sizeof(skill_max)) {
            if (skill_num[i] == num) {
                return skill_max[i];
            }
            i += 1;
        }  
    }
    if (how == 1) {
        return skill_max[num];
    }
    if (how == 2) {
        return skill_num[num];
    }
    if (how == 3) {
        return call_other("obj/skillfun", "skill_names", skill_num[num]);
    }
    if (how == 4) {
        return skill_max;
    }
}

special_advance_effect(lvl) {
    object book;
    if (lvl == 2 && !present("spellbook", this_player())) {
        write("The man speaking in middle of the room suddenly interrupts his\n" +
              "lesson and walks towards you. '" + capitalize(this_player()->query_name()) +
              ", it is time for you\n" +
              "the receive your spellbook' he says. Then he walk to the book\n" + 
              "shelves and picks a book from it and then hands it to you.\n" +
              "He says 'This will surely help you in your way, do not lose it.'\n" +
              "Then he returns to his place and resumes his lesson.\n");
        book = clone_object("obj/spellboo.c");
        move_object(book, this_player());
        book->add_spell("Earth Grasp", "exs sol grs");
    }    
}

get_book_back() {
    if(!this_player()->query_guild_level(call_other("/world/guilds/guildfun.c",
		"get_guild_number", "Apprentice Mage"))) {
	write("You are not a mage.\n");
	return 1;
    }
    if (!present("spellbook", this_player())) {
	write("You get your book back.\n");
	move_object(clone_object("obj/spellboo.c"), this_player());
 	return 1;
    }
    write("You all ready have your book.\n");
    return 1;
}	

SIX_EXIT("world/city/emerald6","east",
         "world/mage/advmage","up",
         "world/mage/elem_enr","north",
         "world/mage/natu_enr","south",
         "world/mage/appr_abj","down",
         "world/mage/magicians","west",
         "The Apprentice Mage guild hall",
         "The Apprentice Mage guild hall.\n"+
         "You are standing in a huge hall where busy looking hooded people\n" +
         "are dwelling around. In the center of the hall there is a man\n" +
         "speaking and demonstrating a magical effect to some students.\n" + 
         "There are book shelves full of books on the sides of the hall.\n" + 
         "The place is well lit with some strange lamps that are hanging\n" +
         "from the ceiling and glowing bright magical light.\n" +
         "There is a round staircase going up and down.\n"+
	 "The streets of Duranghom lie to the east.\n", 3)

