inherit "obj/monster";
object dagger;
reset(arg) {
        ::reset(arg);
        if(arg) {return; }
        set_name("guard");
        set_level(35+random(6));
        set_al(-10);
        set_gender(1);
        set_race("human");
        set_short("Guard of the castle");
        set_long("He is sitting on the floor and looking through window for the\n"+
                 "intruders. He looks strong and well-trained, ready for\n"+
                 "big fights, even a war.\n");
        dagger = clone_object("/wizards/neophyte/areat/castle/obj/dagger");
        move_object(dagger, this_object());
        init_command("wield dagger");
        set_skill("strike", 100);
        set_skill_chance("strike", 40);
}
