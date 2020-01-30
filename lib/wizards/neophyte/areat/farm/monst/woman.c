inherit "obj/monster";

reset(arg) {
        object ring, feet;
        int i;
        i = random(12);
        ::reset(arg);
        if(arg) {return; }
        set_name("woman");
        set_alias("old woman");
        set_level(random(5)+35);
        set_gender(2);
        set_log(1);
        set_int(query_int()*3);
        set_str(query_str()/5);
        set_max_hp(query_hp()+random(5000));
        set_hp(query_max_hp());
        set_al(50);
    set_resists("cold", 100);
        set_race("gnome");
        set_short("An old woman is cleaning the floor");
  set_long("This woman is rather old, and appears frail. Her clothes\n"+
     "hang loosely on her skeleton-like body. Her long white hair\n"+
     "is well combed and braided down to the middle of her back. She\n"+
     "seems to be upset about something. Maybe you can offer her some\n"+
     "help to solve her problems.\n");
   set_skill("tumble", 45);
   set_skill("counter spell", 40);
   set_skill("chanting", 70);
   set_skill("stunning blast", 100);
   set_skill("stunned maneuvers", 100);
   set_skill("mana control", 70);
   set_skill("quick chant", 70);
   set_skill("cast essence", 88);
   set_skill("cast fire", 80);
   set_skill("cast bolt", 80);
   set_skill("distract concentration", 30);
   set_spell_chance(60, "exs fla blt");
            if(i < 2) { ring = clone_object("/wizards/neophyte/areat/farm/obj/ring");
                                        move_object(ring, this_object());
                                        init_command("wear ring");
                        }
            if(i > 10) { feet = clone_object("/wizards/neophyte/areat/farm/obj/feet");
                                        move_object(feet, this_object());
                                        init_command("wear slippers");
                }
}


catch_tell(str) {
        string tmp1, tmp2, chat_str;
           object ob, ob1;
        ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("lampaan_villa", this_object());
    if (ob && this_player()->query_name() == tmp1) {
    destruct(ob);
    write("Woman starts refine the wool.\n");
    write("Woman says: 'Here you go.'\n");
    write("Woman gives you sheephide\n");
    ob1 = clone_object("/wizards/neophyte/areat/farm/obj/sheephide");
    move_object(ob1, this_player());

  }
 }
}
