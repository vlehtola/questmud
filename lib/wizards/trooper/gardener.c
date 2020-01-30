inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(3);
    set_name("gardener");
    set_alias("hobbit");
    set_short("An angry gardener");
    set_long("Hobbit gardener is looking at you ANGRILY!\n");
    set_wc(3);
    set_ac(0);
    set_al(10);
    set_gender(1);
    set_race("halfling");
    set_aggressive(1);
    set_init_ob(this_object());
    set_move_at_random(0);
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
"Hobbit says: Thank you for returning the painting.\n";
        chat_str[1] =
"Hobbit says: If you ever need any herbs or something, just ask me.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(3);
        a_chat_str[0] = "Hobbit shouts: GET OUT OF HERE!\n";
        a_chat_str[1] = "Hobbit says: I am sure it was you who stole the painting!\n";
        a_chat_str[2] = "Hobbit shouts: Give the painting back!\n";
    }
    load_chat(40, chat_str);
    load_a_chat(100, a_chat_str);
    money = clone_object("obj/money");
    call_other(money, "set_money", random(4));
    move_object(money, this_object());

    weapon = clone_object("wizards/bulut/forl/equ/fork");
    move_object(weapon, this_object());
    init_command("wield dungfork"); 
}

monster_init() {
   if (this_player()->query_quests("hobbit gardener")) {
        return 1;
   }
}

catch_tell(str) {
   string tmp1,tmp2;
   ::catch_tell(str);
   if (sscanf(str, "%s gives painting %s.", tmp1, tmp2) == 2) { 
        if (present("painting", this_object()) && this_player()->query_name() == tmp1) {
           write("As you give the painting to the gardener, he looks confused and says:\n");
           write("'So it was not you who stole it? Thank you for returning it!'\n");
           write("'If you ever need herbs, just ask me.'\n");
           this_object()->stop_fight();
           this_player()->stop_fight();
           if (!this_player()->query_quests("hobbit gardener")) {
              this_player()->set_quest("hobbit gardener",10);
           }
        }
   }
}
