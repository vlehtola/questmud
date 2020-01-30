inherit "obj/monster";
object torso,gloves,legs;
reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("ghost");
        set_level(100+random(6));
        set_gender(1);
        set_al(-100);
        set_short("A ghost of lighthouse");
        set_long("It doesn't look a normal ghost. The other end of lighthouse can be seen\n"+
                 "without the ghost standing in your way. You can only guess that you can't\n"+
                 "destroy it like a normal ghost, with spells and hard hits.\n");
     torso = clone_object("/wizards/neophyte/city/eq/torso.c");
        move_object(torso, this_object());
     init_command("wear mail");
     gloves = clone_object("/wizards/neophyte/city/eq/gloves.c");
        move_object(gloves, this_object());
     init_command("wear gloves");
     legs = clone_object("/wizards/neophyte/city/eq/legs.c");
        move_object(legs, this_object());
     init_command("wear leggings");
set_dead_ob(this_object());
}

monster_died() { return 1; }

final_dest() {
	say("The ghost yeals violently as it is finally destroyed.\n");
    filter_array(all_inventory(this_object()), #'move_object, environment(this_player()));
    destruct(this_object());
}