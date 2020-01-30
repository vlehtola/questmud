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
        call_other(smasher, "set_short", "smasher");
        call_other(smasher, "set_long", "You are looking at the legendary 'SMASHER'"); 
        call_other(smasher, "set_class", 30);
        call_other(smasher, "set_weight", 1);
        call_other(smasher, "set_value", 200000);
        call_other(guard, "set_name", "giant guard");
        call_other(guard, "set_alias", "guard");
        call_other(guard, "set_race", "giant");
        call_other(guard, "set_level", 20);
        call_other(guard, "set_al", 0);
        call_other(guard, "set_short", "A guardien of shadow");
        call_other(guard, "set_long", "You are looking at at guard of Shadow, trying to guard his master");
        call_other(guard, "set_wc", 15);
        call_other(guard, "set_ac", 5);
        call_other(guard, "set_aggressive", 1);
        move_object(guard, this_object());
        move_object(smasher, guard);
    }
}

THREE_EXIT("players/shadow/shadow", "up",
           "players/shadow/guards", "south",
           "room/elevator", "west",
"Guard post",
"You are in the guard post of the castle of Shadow.\n"+
"Here guards guard the entrance to the castle.\n"+
"To your north you see the guards room, where they sleep\n"+
"and live. Up from here is the main hall of the castle.\n"+
"West from here is the elevator.\n",
1)
