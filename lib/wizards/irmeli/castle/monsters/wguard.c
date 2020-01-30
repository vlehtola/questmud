inherit "obj/monster";
object weapon;
reset(arg) {
    ::reset(arg);
    if (arg) { return; }

    set_level(30);
    set_name("guard");
    set_alias("human");
    set_short("A guard of the castle is keeping an eye for the bridge");
    set_long("A strong looking guard who is keeping an eye for the bridge from here.\n"+
             "The guard's job is highly paid and respected, but extremely boring. He is\n"+ 
             "really angry because someone has shot a rock towards his head. But\n"+  
             "luckily that rock just scratched his forehead. There is a nasty wound\n"+
             "which is bleeding.\n");

    set_al(15);
    set_gender(1);
    set_race("human");
    set_aggressive(1);

    weapon = clone_object("/wizards/irmeli/castle/eq/sabre.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}









