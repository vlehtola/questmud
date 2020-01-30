inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_race("human");
    call_other(this_object(), "set_level", 35);
    call_other(this_object(), "set_name", "mayor");
    call_other(this_object(), "set_alias", "aloc");
    call_other(this_object(), "set_short", "Aloc Acoc, the mayor of Jericho");
    call_other(this_object(), "set_long", "The newly appropriated mayor of Jericho.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);


    armour = clone_object("/wizards/walla/area/armour/coat");
    move_object(armour, this_object());
    init_command("wear coat");

    weapon = clone_object("/wizards/walla/area/armour/leggings");
    move_object(weapon, this_object());
    init_command("wear leggings");
}


catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      item_ob = present("amu0700123123", this_object());
      if (!item_ob) { return; }
      if (ob && item_ob && item_ob->query_name() == "tail" ) {
 tell_object(ob, "Aloc shines like the sun, as he sees proof of Leb's slaying.\n");
 tell_object(ob, "You have completed the 'Slay Leb Kamar' quest.\n");
 tell_object(ob, "Aloc Acoc says: 'Here, you can have this necklace back. I tuned\n");
 tell_object(ob, "it a bit, to give you more powers. I hope you don't mind\n");
 call_other(ob, "set_quest", "Slay Leb-Kamar");
      destruct(item_ob);
 move_object(clone_object("/wizards/walla/jericho/stuph/lebneck_completed"),
 this_player());
    }
}
}


