inherit "obj/monster";

reset(arg) {
    object armour,armour2,armour3;
    string chat_str, a_chat_str;
    int i;
::reset(arg);
if (arg) { return; }
    i = random(2);
    set_level(80);
    set_int(query_int()*2);
   set_str(query_str()*2);
   set_con(query_con()*2);
   set_name("lord");
    set_alias("henrik");
    set_short("Henrik IV, Lord of the Castle Asgroth");
    set_long("Henrik IV is the lord of the castle of Asgroth. He is very fat but elegant.\n"+
             "He has short silver-grey hair, blond bread, and chubby cheeks. He is\n"+
             "rumoured to be very kind but exact to his people.\n");
    set_max_hp(350000);
    set_hp(350000);     
    set_al(-50);
    set_gender(1);
    set_skill("tumble", 60);
    set_race("human");
    set_aggressive(0);
    set_log();
    set_init_ob(this_object());
    set_mage(1);
    set_special(9);

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "Lord says: 'One of the McArthur boys is in the dungeon.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Lord says: 'You will end to the dungeon like him!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(3, a_chat_str);


    armour = clone_object("/wizards/irmeli/castle/eq/ring");
    move_object(armour, this_object());
    init_command("wear ring");

    if(i==0) { armour2 = clone_object("/wizards/irmeli/castle/eq/collar");
    move_object(armour2, this_object());
    init_command("wear collar");

    }
    if(i==1) { armour3 = clone_object("/wizards/irmeli/castle/object/key");
    move_object(armour3, this_object());
}
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Lord shouts: 'Let there be a FIRESTORM!'\n");
  say("A raging FIRESTORM hits against "+ob->query_name()+"!\n", ob);
  ob->hit_with_spell(3000, "fire");
}

