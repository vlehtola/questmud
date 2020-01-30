inherit "obj/monster";
object belt;
reset(arg) {
        object money;
        ::reset(arg);
        if(arg) {return; }
        set_level(45+random(5));
        set_al(-10);
        set_gender(1);
        set_race("human");
        set_name("captain");
        set_short("Captain of the guards");
        set_long("He is giving orders to guards which he is to busy to do himself.\n"
                 "He is wearing the belt which is granted him by Pidur for helping him\n"+
                 "to arhieve king status.\n");
        set_block_dir("north");
        set_log();
        set_skill("rage", 100);
        set_skill("berserk", 100);
        set_skill_chance("berserk", 40);
        set_skill("tumble", 20);
        set_skill("stun", 80);
        set_skill("kick", 100);
        set_skill_chance("kick", 75);
        belt = clone_object("/wizards/neophyte/areat/castle/obj/belt");
        move_object(belt, this_object());
        init_command("wear belt");
}
