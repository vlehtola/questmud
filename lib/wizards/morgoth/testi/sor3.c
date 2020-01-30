inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 16);
    call_other(this_object(), "set_name", "sorcerer");
    call_other(this_object(), "set_alias", "man");
    call_other(this_object(), "set_short", "Old sorcerer is standing here");
    call_other(this_object(), "set_long",
    "This old sorcerer is testing his new frog curse here.\n");
    call_other(this_object(), "set_extra", 1);
    call_other(this_object(), "set_al", 15);
    set_spell_chance(70, "exs fla grs");
    call_other(this_object(), "set_aggressive", 0);
    set_skill("cast essence", 60);
    set_skill("cast fire", 60);
    set_skill("cast grasp", 60);
    set_skill("mana control", 30);
    set_skill("chanting", 50);
 
      if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Sorcerer asks: Wanna test my new frog curse?\n";
        chat_str[1] =
          "Sorcerer exclaims: It won't hurt you.\n";
        chat_str[2] =
          "Sorcerer says: I haven't ever failed my spells.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Sorcerer yells: Now you can taste some magic!\n";
    }
    load_chat(20, chat_str);
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(10)+10);
    move_object(money, this_object());
 
    armour = clone_object("/wizards/morgoth/forest/item/cloak");
    move_object(armour, this_object());
    init_command("wear cloak");
 
 extra() {
    object sor_guard;
    if (!attacker_ob) {
        return;
    }
    if(random(number_of_guards + 2) == number_of_guards) {
        leb_guard = 
clone_object("wizards/morgoth/forest/npc/bird.c");
        move_object(sor_guard, environment(this_object()));
        say("Sorcerer summons something!\n");
        number_of_guards += 2;
 }                   
}
 
reduce_number() {
    number_of_guards -= 2;
}
}
