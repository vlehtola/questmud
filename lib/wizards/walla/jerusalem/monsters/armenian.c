inherit "obj/monster";
 
reset(arg) {
    object money;
     object armour,weapon;     
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 15);
    call_other(this_object(), "set_name", "citizen");
    call_other(this_object(), "set_alias", "zephaniah");
    call_other(this_object(), "set_short", "Zephaniah, an armenian citizen of Jerusalem");
    call_other(this_object(), "set_long", "Zephaniah is a man that has seen many things. He has a big beard\n" +
                                          "and he twirls his finger around it like he was unpatient of something. His clothing\n" +
                                          "is of the cheapest sort, and it looks like it jus some skin, put on the mans body.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);
 
   armour  = clone_object("/wizards/nalle/eq/rags");
    move_object(armour, this_object());
    init_command("wear robes");
 
   
}

