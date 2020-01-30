inherit "obj/monster";

reset(arg) {
    object weapon,armour,armour2;
    string chat_str, a_chat_str;
    int i;
::reset(arg);
if (arg) { return; }
    i = random(2);
    set_level(80);
    set_int(query_int()*2);
    set_name("lady");
    set_alias("elizabeth");
    set_short("Elizabeth III, Lady of the Castle Asgroth");
    set_long("Elizabeth III is the lady of the castle of Asgroth. She is very thin and elegant.\n"+
             "She has a long blond hair, beautiful brown eyes and a face like an angel. She loves\n"+
             "her husband very much.\n");
    set_max_hp(350000);
    set_hp(350000);         
    set_al(-50);
    set_gender(2);
    set_skill("tumble", 55);
    set_race("human");
    set_aggressive(0);
    set_log();
    set_init_ob(this_object());
    set_mage(1);
    set_special(9);

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "Lady says: 'I love my husband.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Lady says: 'My husband will kill you!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(3, a_chat_str);


    weapon = clone_object("/wizards/irmeli/castle/eq/staff");
    move_object(weapon, this_object());
    init_command("wield staff");

    if(i==0) { armour = clone_object("/wizards/irmeli/castle/eq/tiara");
    move_object(armour, this_object());
    init_command("wear tiara");

    }
    if(i==1) { armour2 = clone_object("/wizards/irmeli/castle/object/key");
    move_object(armour2, this_object());
}
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Lady shouts: 'Let there be a COLDSTORM!'\n");
  say("A raging COLDSTORM hits against "+ob->query_name()+"!\n", ob);
  ob->hit_with_spell(3000, "cold");
}

