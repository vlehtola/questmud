inherit "obj/monster";
reset(arg) {
    object armour;    
    ::reset(arg);
    if(arg) { return; }
    set_level(25);
    set_name("guard");
    set_alias("guard");
    set_short("A young guard watching the view");
    set_long("This young guard is watching the beautiful birds flying.\n"+
             "He looks bit confused. Blue eyes of him shine strangely\n"+ 
             "as he looks at sky. He is wearing leather armours.\n");
    set_al(10);
    set_aggressive(0);
    set_gender(1);
    armour = clone_object("/wizards/luminarc/wizcastle/armours/armour1.c");
    move_object(armour, this_object());
    init_command("wear leggings");
    set_race("human");

}

