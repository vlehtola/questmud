inherit "obj/monster";
 
reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
set_race("human");
    call_other(this_object(), "set_level", 69);
        call_other(this_object(), "set_name", "Leb");
        call_other(this_object(), "set_alias", "priest");
        call_other(this_object(), "set_short", "Leb-Kamar, the ruler of Jericho");
        call_other(this_object(), "set_long", "Leb-Kamar is here looking out from his room \n" +                     
       "window, and shouting orders to the slaves in the bazar downstairs. He \n" +
       " looks very terrifying and is very pissed that you have entered his privacy in \n" +
        "private chamber.\n");
        call_other(this_object(), "set_al", 10);
        call_other(this_object()," set_aggressive", 0);
        set_block_dir("out");
 
        armour = clone_object("/wizards/walla/area/armour/lebplate");
        move_object(armour, this_object());
        init_command("wear plate");
 
        armour = clone_object("/wizards/walla/area/armour/leblegging");
        move_object(armour, this_object());
        init_command("wear leggings");
 
        armour = clone_object("/wizards/walla/area/armour/lebring");
        move_object(armour, this_object());
        init_command("wear ring");
 
        weapon = clone_object("/wizards/walla/area/weapons/lebsword");
        move_object(weapon, this_object());
        init_command("wield sword");
 
}
