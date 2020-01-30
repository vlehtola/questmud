
inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour,armour2;
    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(2);
    set_level(60);
    set_name("alchemist");
    set_alias("efraim");
    set_short("Efraim En-Dor the alchemist");
    set_long("Efraim stands here trying to find the way to make gold from cheap\n" +
             "and worthless metals, but he hasen't succeeded yet. There are rumours\n"+
             "that, Leb-Kamar is having a special formula, which should work.\n");
    set_race("human");
    set_gender(1);
    set_log();
    set_al(10);
    set_aggressive(0);
    set_mage(1);

    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
          "Efraim says: 'Bring me piece of metal, so I can make gold from it. I'll reward you, if you bring it to me.'\n";
        chat_str[1] =
          "Efraim says: 'It's rumoured, that Leb-Kamar has the right piece.'\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);

        a_chat_str[0] = "Efraim says: 'Noooooooooooooooo!.'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);

    if(i==0) { armour = clone_object("/wizards/walla/area/weapons/newaxe");
    move_object(armour, this_object());
    init_command("wield axe");
}
    if(i==1) { armour2 = clone_object("/wizards/walla/area/armour/newgoggles");
    move_object(armour2, this_object());
    init_command("wear goggles");
  }
}
catch_tell(str) {
  int i;
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);

   if (sscanf(str, "%s gives piece %s.", tmp1, tmp2) == 2) {
    ob = present("piece", this_object());
    if (ob && this_player()->query_name() == tmp1) {
    destruct(ob);
    write("Efraim says: 'Thanks! Now i got the right piece and the formula which should work.'\n");
    write("Efraim continues: 'Soon I'll be so rich, that I can hire new workers and widen\n");
    write("my trade.'\n");
    this_player()->set_quest("Help alchemist with his mission");
    tell_room(environment(this_object()), "Efraim tries to forge the piece, but fails.\n"+
    "Efraim shouts: 'NOOOOOOOOOOOOOOO! This is not the right piece, farewell!'\n"+
    "He throws the piece high on air, suddenly a lightning strikes to it. The\n"+
    "piece of metal explodes and melts, splashing hot, melted metal all\n"+
    "around the room.\n"+
    "Your face BURNS, as the metal hits you!\n");

     ob = all_inventory(environment(this_object()));
     for(i=0; i < sizeof(ob) ; i++) {
       if(living(ob[i]))
        ob[i]->hit_with_spell(400, "fire");
     }
     call_out("alchemist_death", 1);         
    }
  }
}                                     

alchemist_death() {
  tell_room(environment(this_object()), "The alchemist falls down and draws his last breath.\n");
  this_object()->death();
}
