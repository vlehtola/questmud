#include "room.h"

object cooking_knife, cook;

#undef EXTRA_RESET
#define EXTRA_RESET fix_cook();

fix_cook()
{
    if (!cook || !living(cook)) {
        cooking_knife = clone_object("obj/weapon");
        call_other(cooking_knife, "set_name", "cooking knife");
        call_other(cooking_knife, "set_alias", "knife");
        call_other(cooking_knife, "set_short", "cooking knife");
        call_other(cooking_knife, "set_alt_name", "cooking knife");
        call_other(cooking_knife, "set_long", "This is a Big knife made to cut.\n"+
                "Meat in pieces. It is done for the cook of shadow\n");
        call_other(cooking_knife, "set_read", 
                "The only thing you can read is the word 'COOK'.\n");
        call_other(cooking_knife, "set_class", 10);
        call_other(cooking_knife, "set_weight", 2);
        call_other(cooking_knife, "set_value", 5000);
        call_other(cooking_knife, "set_hit_func", this_object());
        cook = clone_object("obj/mon_talk");
        call_other(cook, "set_alias", "cook");
        call_other(cook, "set_race", "giant");
        call_other(cook, "set_level", 15);
        call_other(cook, "set_al", 0);
        call_other(cook, "set_short", "A cook of Shadow is here whacking meat to pieces");
        call_other(cook, "set_wc", 15);
        call_other(cook, "set_ac", 5);
        call_other(cook, "set_aggressive", 0);
        move_object(cook, this_object());
        move_object(cooking_knife, cook);
    }
}

ONE_EXIT("players/shadow/eat_room", "south",
"Shadows kitchen",
"This is the kitchen in the mansion of shadow. \n"+ 
"Here the delisious foods of Shadow are made .\n"+ 
"You notice a massive room south of here. It is the eating room\n"+
"where shadow eats and enjoys food, alone or with company. \n"+ 
"There are kitchen tools all over this place.\n", 
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
