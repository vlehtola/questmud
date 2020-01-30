inherit "obj/monster";
reset(arg) {
        object plate;
                ::reset(arg);
                if(arg) {return; }
                    set_name("orc");
    set_level(35);
    set_race("orc");
        set_str(query_str()*2);
            set_con(query_con()*2);

    set_alias("orc");
    set_short("A small orc");
    set_long("This aggressive looking orc is one of the mighties .\n"+
             "rider that live in the pirate island. He has a grinning.\n"+
             "look on his face.\n");
    set_aggressive(1);
    set_gender(1);
    set_skill("mana control", 100);
    set_skill("cast poison", 100);
    set_skill("cast bolt", 100);
    set_skill("cast essence", 100);
    set_spell_chance(100, "exs poi blt");
    plate = clone_object("/wizards/neophyte/city/eq/plate.c");
        move_object(plate, this_object());
        init_command("wear plate");
 }
