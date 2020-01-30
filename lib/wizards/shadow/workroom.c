#include "room.h"

object jacket, worker;

#undef EXTRA_RESET
#define EXTRA_RESET fix_worker();

fix_worker()
{
    if (!worker || !living(worker)) {
        jacket = clone_object("obj/armour");
        call_other(jacket, "set_name", "leather jacket");
        call_other(jacket, "set_alias", "jacket");
        call_other(jacket, "set_short", "A jacket of 'Club Shadow'");
        call_other(jacket, "set_alt_name", "jacket");
        call_other(jacket, "set_long", "  \n"+
"                                             XXXX XX    XX   XX  XXXX         \n"+
"                                            XX    XX    XX   XX  X   X      \n"+
"      XXXXXXXXXXXXXXX                       XX    XX    XX   XX  XxxX        \n"+
"     X               X                      XX    XXX   XX   XX  X   X      \n"+
"   X     XXXXXXXXXXXXX                       XXXX XXXXX  XXXXX   XXXX      \n"+
"  X     X                                   Let's Get ready to RUMBLE!!    \n"+
"  X     X                                         MR. ARMAGEDDON           \n"+
"   X      X     XXX  XXX         XX        XXX       XXX    XX            XX \n"+
"     X      X   X X  X X        X  X      XX  XX   XX   XX  XX            XX\n"+
"        X    X  X XXXX X       X    X     XX  XX   XX   XX   XX          XX  \n"+
" XXXXXX X    X  X XXXX X      X  XX  X    XX  XX   XX   XX    XX   XX   XX    \n"+
"X           X   X X  X X     X  X  X  X   XX  XX   XX   XX     XXXX  XXXX    \n"+
"XXXXXXXXXXX     XXX  XXX    XXXX    XXXX  XXXX      XXXXX       XX   XX     \n");
                
        call_other(jacket, "set_class", 10);
        call_other(jacket, "set_weight", 2);
        call_other(jacket, "set_value", 5000);
        call_other(worker, "set_name", "worker");
        call_other(worker, "set_alias", "worker");
        call_other(worker, "set_race", "giant");
        call_other(worker, "set_level", 15);
        call_other(worker, "set_al", 0);
        call_other(worker, "set_short", "A worker of Shadow is trying to work something out");
        call_other(worker, "set_wc", 15);
        call_other(worker, "set_ac", 5);
        call_other(worker, "set_aggressive", 0);
        move_object(worker, this_object());
        move_object(jacket, worker);
    }
}

ONE_EXIT("players/shadow/shadow", "east",
"Shadows home room",
"This is the Home room of shadow. \n"+ 
"Here you see a massive drawing board with some \n"+ 
"blueprints on it. This must be the place where Shadow plans everything.\n"+
"To your east is the main-hall of the castle. \n"+ 
"Sometimes there is also workers here working for shadow.\n", 
1)

