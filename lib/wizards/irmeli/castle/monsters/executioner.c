inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    object armour,armour1,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(70);
    set_exp(10095470);
set_name("executioner");
set_alias("human");
set_short("A dark-hooded Executioner of the Castle Asgroth");
    set_long("He is the executioner of the Castle Asgroth. You can't see his face because he\n"+
             "has a dark hood covering his face. He looks extremely strong and dangerous.\n"+
             "His hands are massive and hairy to say nothing of his legs, which are enourmous.\n"+
             "Rumours tell that he is cruel and full of rage because his family was killed\n"+
             "in undetermined situations.\n");
    set_max_hp(250000);
    set_hp(250000);
    set_al(0); 
    set_aggressive(0);
    set_init_ob(this_object());
    set_race("human");
    set_gender(1);
    set_str(670);
    set_skill("tumble", 80);
    set_log(1);
    set_special(25);
set_move_at_random(0);
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Executioner says: 'You're the next one!'\n";
        chat_str[1] = "Executioner says: 'Place your head on the block.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Executioner asks: 'So you wan't to lose your head?'\n";

    }
    load_chat(1, chat_str);
    load_a_chat(1, a_chat_str); 

    armour = clone_object("/wizards/irmeli/castle/eq/hood.c");
    move_object(armour, this_object());
    init_command("wear hood");

    armour = clone_object("/wizards/irmeli/castle/object/exehead.c");
    move_object(armour, this_object());

    weapon = clone_object("/wizards/irmeli/castle/eq/exeaxe.c");
    move_object(weapon, this_object());
    init_command("wield axe");
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Executioner hits you HARD with his axe!\n");
  say("Executioner CUTS deep wounds in "+ob->query_name()+"'s body with his axe!\n", ob);
  ob->hit_with_spell(500, "physical");
}