#include "room.h"

object smasher, guard;

#undef EXTRA_RESET
#define EXTRA_RESET fix_guard();

fix_guard()
{
    if (!guard || !living(guard)) {
        smasher = clone_object("obj/weapon");
        call_other(smasher, "set_name", "smasher");
        call_other(smasher, "set_alias", "smasher");
        call_other(smasher, "set_short", "Smasher");
        call_other(smasher, "set_alt_name", "Smasher");
        call_other(smasher, "set_long", "This is a very fine hammer.\n"+
                "It's done to the guards of Shadow.\n");
        call_other(smasher, "set_read", 
                "The only thing you can read is the word 'POUD'.\n");
        call_other(smasher, "set_class", 30);
        call_other(smasher, "set_weight", 2);
        call_other(smasher, "set_value", 200000);
        call_other(smasher, "set_hit_func", this_object());
        call_other(guard, "set_name", "guard");
        call_other(guard, "set_alias", "giant guard");
        call_other(guard, "set_race", "giant");
        call_other(guard, "set_level", 20);
        call_other(guard, "set_al", 0);
        call_other(guard, "set_short", "A guardien of Shadow is sleeping here");
        call_other(guard, "set_wc", 15);
        call_other(guard, "set_ac", 5);
        call_other(guard, "set_aggressive", 0);
        call_other(guard, "set_chance", 20);
        call_other(guard, "set_spell_mess1",
            "You are hit by a magic missile");
        call_other(guard, "set_spell_mess2",
            "The guard casts an magic missile");
        call_other(guard, "set_spell_dam", 10);
        move_object(guard, this_object());
        move_object(smasher, guard);
    }
}

TWO_EXIT("players/shadow/wc", "east",
         "players/shadow/guard_ro", "north",
"Guards room",
"This is the guard room of the mansion of shadow. \n"+ 
"Here the giant guards of Shadow mind their business.\n"+ 
"You notice a small room east of here. It must be the\n"+
"bathroom where the guards do their needs you cant see in and\n"+ 
"you are not sertain is there someone or something in there.\n", 
1)

weapon_hit(attacker)
{
    string alig;

    
    if(call_other(attacker,"id","orc")){
        write("SMASH\n");
        return 10;
    }
    return 0;
}
