#include "/world/guilds/guild.h"
#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET\
        extra_reset();

object plaque, test_room;
string test_taker;

init() {
    ::init();
    add_action("join", "join");
    add_action("advance", "advance");
    add_action("info", "info");
    add_action("list", "list");
    add_action("check_advance_rec", "requirements");
    add_action("train", "train");
}

reset(arg) {
     if (arg) return;
     set_not_out(1);
     set_light(3);
     add_exit("north", "world/mage/mag/tower4");
     short_desc = "The Arcaners guild";
     long_desc = "You are in the Arcaners guild hall.\n" +
         "Some students are creating beautiful light effect by magic.\n";
     if (!plaque) {
         plaque = clone_object("world/guilds/plaque.c");
         move_object(plaque, this_object()); 
     }
}

guild_long_name() {
    return "the Arcaners guild.   ";
}

guild_name() {
    return "Arcaners";
}

guild_max_level() {
    return 10;
}

check_joining_rec() {
    if (this_player()->query_guild_level(call_other("/world/guilds/guildfun.c",
	  "get_guild_number", "Adept Mages")) != 10) {
        write("Must have completed the Adept Mages guild first.\n");
        return 0;
    }
    return 1;
}

check_advance_rec(lev) {
    int ii, i, req, req_level;
    string skill;
    req = allocate(10);
    req_level = allocate(10);
    skill = allocate(10);
    if (!lev) { check_joining_rec(); }
    while(ii < i) {
        write("Level " + req_level[ii] + ": Must have trained skill " + skill[ii] + " to at least " + req[ii] + "% (" + this_player()->query_skills(get_num(skill[ii])) + "%).\n");
        ii += 1;
    }
    if (i && lev) { return 0; }
    return 1;
}

/*
    15% Int, 10% Wis, 5 spregen
*/

get_bonuses(level) {
    if (level == 0) { return "int 1 , wis 1 , spregen 2 , "; }
    if (level == 1) { return "int 2 , "; }
    if (level == 2) { return "wis 1 , "; }
    if (level == 3) { return "int 2 , spregen 1 "; }
    if (level == 4) { return "int 4 , wis 2 , "; }
    if (level == 5) { return "int 4 , wis 1 , spregen 3 "; }
    if (level == 6) { return "int 4 , wis 3 , "; }
    if (level == 7) { return "int 4 , wis 3 , "; }
    if (level == 8) { return "int 4 , wis 3 , "; }
    if (level == 9) { return "int 5 , wis 4 , spregen 4 , "; }
}
/*    
   Cast create: 100
   Cast information: 100
   Cast item: 100
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
        skill_max = allocate(3);
        skill_num = allocate(3);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 10;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 10;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 10;
    }
    if (guild_level == 2) {
        skill_max = allocate(3);
        skill_num = allocate(3);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 20;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 20;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 30;
    }
    if (guild_level == 3) {
        skill_max = allocate(3);
        skill_num = allocate(3);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 30;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 40;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 50;
    }
    if (guild_level == 4) {
        skill_max = allocate(3);
        skill_num = allocate(3);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 35;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 60;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 70;
    }
    if (guild_level == 5) {
        skill_max = allocate(3);
        skill_num = allocate(3);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 40;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 80;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 100;
    }
    if (guild_level == 6) {
        skill_max = allocate(4);
        skill_num = allocate(4);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 50;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 100;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 100;
        skill_num[3] = get_num("offensive efficiency");
        skill_max[3] = 10;
    }
    if (guild_level == 7) {
        skill_max = allocate(4);
        skill_num = allocate(4);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 60;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 100;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 100;
        skill_num[3] = get_num("offensive efficiency");
        skill_max[3] = 30;
    }
    if (guild_level == 8) {
        skill_max = allocate(4);
        skill_num = allocate(4);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 70;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 100;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 100;
        skill_num[3] = get_num("offensive efficiency");
        skill_max[3] = 50;
    }
    if (guild_level == 9) {
        skill_max = allocate(4);
        skill_num = allocate(4);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 80;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 100;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 100;
        skill_num[3] = get_num("offensive efficiency");
        skill_max[3] = 70;
    }
    if (guild_level == 10) {
        skill_max = allocate(4);
        skill_num = allocate(4);
        skill_num[0] = get_num("awake stun");
        skill_max[0] = 100;
        skill_num[1] = get_num("distract concentration");
        skill_max[1] = 100;
        skill_num[2] = get_num("elusive spellcasting");
        skill_max[2] = 100;
        skill_num[3] = get_num("offensive efficiency");
        skill_max[3] = 100;
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


