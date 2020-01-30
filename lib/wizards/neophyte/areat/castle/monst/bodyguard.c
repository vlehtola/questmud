inherit "obj/monster";
object dagger;
reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("bodyguard");
        set_alias("guard");
        set_level(15+random(20));
        set_max_hp(query_hp()*3);
        set_hp(query_max_hp());
        set_al(-10);
        set_str(1);
        set_aggressive(1);
        set_race("human");
        set_short("A Personal bodyguard of Pidur");
        set_long("This guard is here to protect the King Pidur at any cost.\n"+
                 "He looks rather small to be bodyguard.\n");
        set_block_dir("down");
        set_skill("kick", 100);
        set_skill("strike", 100);
        set_skill_chance("strike", 100);
        set_skill_chance("kick", 100);
        set_dead_ob(this_object());
         dagger = clone_object("/wizards/neophyte/areat/castle/obj/dagger");
         move_object(dagger, this_object());
         init_command("wield dagger");

}

monster_died() {
    object ob;
    ob = present("pidur", environment(this_object()));
    if (!ob) { return; }
    ob->reduce_number();
}
