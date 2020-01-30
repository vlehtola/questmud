#include "/world/guilds/guild.h"
#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

guild_max_level() {
  return 10;
}

init() {
  ::init();
    add_action("join", "join");
    add_action("advance", "advance");
    add_action("info", "info");
    add_action("list", "list");
    add_action("train", "train");
}

extra_reset() {
     object plaque;
     if (!present("plaque")) {
         plaque = clone_object("world/guilds/plaque.c");
         move_object(plaque, this_object());
     }
}

guild_long_name() {
    return "the Wardancers.     ";
}
guild_name() {
    return "Wardancers";
}

check_advance_rec(lev) {
    int ii, i, req;
    string skill;
    req = allocate(10);
    skill = allocate(10);
    if (lev == 3 || !lev) {
      if (!lev) { write("Level 3:\n"); }        if (this_player()->query_skills(get_num("blades")) < 30 || !lev) {
            req[i] = 30; skill[i] = "blades";
            i += 1;
        }
    }
    if (lev == 5 || !lev) {
      if (!lev) { write("Level 5:\n"); }
        if (this_player()->query_skills(get_num("dodge")) < 30 || !lev) {
            req[i] = 30; skill[i] = "dodge";
            i += 1;
        }
    }
    while(ii < i) {
        write("Must have trained skill " + skill[ii] + " to atleast " + req[ii] + "% (" + this_player()->query_s
kills(get_num(skill[ii])) + "%).\n");
        ii += 1;
    }
    if (i) { return 0; }
    return 1;
}

/*
      15% Str, 25% Dex, 10% Con
*/

get_bonuses(level) {
    if (level == 0) {
        return "dex 2 , str 2 , ";
    }    if (level == 1) {
        return "dex 3 , str 1 , ";
    }
    if (level == 2) {
        return "dex 2 , str 1 ,";
    }
    if (level == 3) {
        return "dex 1 , str 1, con 2, ";
    }
    if (level == 4) {
        return "str 2 , dex 3 , ";
    }
    if (level == 5) {
        return "con 3 , str 1, ";
    }
    if (level == 6) {
        return "dex 2 , str 2, ";
    }
if (level == 7) {
        return "str 3 , dex 2 , ";
    }
    if (level == 8) {
        return "con 6 , dex 3 , ";
    }
    if (level == 9) {
        return "dex 5 , 4 str , con 4 , ";
    }
}
/*
    Skills:
    blades 100
    slash 100
*/

get_skill_max(num, how, lvl) {
    int skill_max, skill_num, i, guild_level;
    guild_level = this_player()->query_guild_level(call_other("/world/guilds/guildfun", "get_guild_number", guil
d_name()));
    if (lvl) {
         guild_level = lvl;
         if (guild_level > 10) { guild_level = 10; }
    }
    if (!guild_level) {
        write("Bugged.. not a member\n");
        return 0;
    }
    if (guild_level == 1) {
        skill_max = allocate(3);
        skill_num = allocate(3);
        skill_num[0] = get_num("attack");
        skill_max[0] = 30;
        skill_num[1] = get_num("blades");
        skill_max[1] = 30;
        skill_num[2] = get_num("parry");
        skill_max[2] = 30;
    }    if (guild_level == 2) {
        skill_max = allocate(4);
        skill_num = allocate(4);
        skill_num[0] = get_num("attack");
        skill_max[0] = 50;
        skill_num[1] = get_num("blades");
        skill_max[1] = 60;
        skill_num[2] = get_num("parry");
        skill_max[2] = 55;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 20;

    }
    if (guild_level == 3) {
        skill_max = allocate(5);
        skill_num = allocate(5);
        skill_num[0] = get_num("attack");
        skill_max[0] = 65;
        skill_num[1] = get_num("blades");
        skill_max[1] = 70;
        skill_num[2] = get_num("parry");
        skill_max[2] = 70;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 40;
        skill_num[4] = get_num("kick");
        skill_max[4] = 40;

    }    if (guild_level == 4) {
        skill_max = allocate(6);
        skill_num = allocate(6);
        skill_num[0] = get_num("attack");
        skill_max[0] = 75;
        skill_num[1] = get_num("blades");
        skill_max[1] = 75;
        skill_num[2] = get_num("parry");
        skill_max[2] = 70;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 60;
        skill_num[4] = get_num("kick");
        skill_max[4] = 50;
        skill_num[5] = get_num("doublehit");
        skill_max[5] = 10;

    }
    if (guild_level == 5) {
        skill_max = allocate(7);
        skill_num = allocate(7);
        skill_num[0] = get_num("attack");
        skill_max[0] = 85;
        skill_num[1] = get_num("blades");
        skill_max[1] = 85;
        skill_num[2] = get_num("parry");
        skill_max[2] = 85;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 70;
        skill_num[4] = get_num("kick");
        skill_max[4] = 60;
        skill_num[5] = get_num("doublehit");
        skill_max[5] = 30;        skill_num[6] = get_num("slash");
        skill_max[6] = 25;

    }
    if (guild_level == 6) {
        skill_max = allocate(7);
        skill_num = allocate(7);
        skill_num[0] = get_num("attack");
        skill_max[0] = 100;
        skill_num[1] = get_num("blades");
        skill_max[1] = 100;
        skill_num[2] = get_num("parry");
        skill_max[2] = 90;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 85;
        skill_num[4] = get_num("kick");
        skill_max[4] = 75;
        skill_num[5] = get_num("doublehit");
        skill_max[5] = 50;
        skill_num[6] = get_num("slash");
        skill_max[6] = 45;
    }
    if (guild_level == 7) {
        skill_max = allocate(8);
        skill_num = allocate(8);
        skill_num[0] = get_num("attack");
        skill_max[0] = 100;        skill_num[1] = get_num("blades");
        skill_max[1] = 100;
        skill_num[2] = get_num("parry");
        skill_max[2] = 100;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 95;
        skill_num[4] = get_num("kick");
        skill_max[4] = 85;
        skill_num[5] = get_num("doublehit");
        skill_max[5] = 70;
        skill_num[6] = get_num("slash");
        skill_max[6] = 55;
        skill_num[7] = get_num("strike");
        skill_max[7] = 20;

    }
    if (guild_level == 8) {
        skill_max = allocate(8);
        skill_num = allocate(8);
        skill_num[0] = get_num("attack");
        skill_max[0] = 100;
        skill_num[1] = get_num("blades");
        skill_max[1] = 100;
        skill_num[2] = get_num("parry");
        skill_max[2] = 100;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 100;
        skill_num[4] = get_num("kick");
        skill_max[4] = 100;
        skill_num[5] = get_num("doublehit");        skill_max[5] = 90;
        skill_num[6] = get_num("slash");
        skill_max[6] = 80;
        skill_num[7] = get_num("strike");
        skill_max[7] = 40;
    }
    if (guild_level == 9) {
        skill_max = allocate(8);
        skill_num = allocate(8);
        skill_num[0] = get_num("attack");
        skill_max[0] = 100;
        skill_num[1] = get_num("blades");
        skill_max[1] = 100;
        skill_num[2] = get_num("parry");
        skill_max[2] = 100;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 100;
        skill_num[4] = get_num("kick");
        skill_max[4] = 100;
        skill_num[5] = get_num("doublehit");
        skill_max[5] = 100;
        skill_num[6] = get_num("slash");
        skill_max[6] = 90;
        skill_num[7] = get_num("strike");
        skill_max[7] = 65;
    }
    if (guild_level == 10) {
        skill_max = allocate(9);        skill_num = allocate(9);
        skill_num[0] = get_num("attack");
        skill_max[0] = 100;
        skill_num[1] = get_num("blades");
        skill_max[1] = 100;
        skill_num[2] = get_num("parry");
        skill_max[2] = 100;
        skill_num[3] = get_num("dodge");
        skill_max[3] = 100;
        skill_num[4] = get_num("kick");
        skill_max[4] = 100;
        skill_num[5] = get_num("doublehit");
        skill_max[5] = 100;
        skill_num[6] = get_num("slash");
        skill_max[6] = 100;
        skill_num[7] = get_num("strike");
        skill_max[7] = 85;
        skill_num[8] = get_num("continous_strike");
        skill_max[8] = 85;

    }

    if (how == 0) {
        while (i < sizeof(skill_max)) {
            if (skill_num[i] == num) {
                return skill_max[i];
            }
            i += 1;
        }
    }    if (how == 1) {
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


ONE_EXIT("/wizards/shadow/workroom", "Home",
"The wardancer guild.",
  "You are inside a massive tree. This tree is absolutely HUGE and seemingly\n"+
  "very old. The huge room you are in is occupied with elves jumping about and\n"+
  "demolishing targets with their swords. The walls of this room are filled with\n"+
  "very fine looking swords and old-looking runes. The room doesn�t seem to have a\n"+
  "ceiling but there is no draft at all. There seems to be no light sources but the\n"+
  "room is clearly lit. This seems to be a very magical place.\n", 1) 

