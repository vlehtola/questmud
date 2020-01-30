inherit "obj/monster";

int number_of_beasts;
reset(arg) {
    string chat_str, a_chat_str;
    object weapon,armour;
    int i;
    ::reset(arg);
    number_of_beasts = 0;
    if(arg) { return; }
i = random(2);    
set_level(85);
set_extra(1);
set_int(query_int()*2);
set_name("knight");
set_alias("edwin");
set_short("Edwin McLeod, the Master Knight");
    set_long("Edwin McLeod is the last master knight in the realm. He is three hundred\n"+
             "years old. He has brown hair, eyebrows and beard. He is guarding the\n"+
             "dungeon of Castle Asgroth. He seems to be very calm and wise. His every\n"+
             "move is premeditated.\n");
    set_al(0); 
    set_aggressive(0);
    set_dead_ob(this_object());
    set_race("human");
    set_gender(1);
    set_str(700);
    set_skill("tumble", 90);
    set_log(1);
    set_special(25);
set_move_at_random(0);
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Knight says: 'You don't belong here!'\n";
        chat_str[1] = "Knight says: 'You must leave NOW!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Knight says: 'This is your end!'\n";

    }
    load_chat(1, chat_str);
    load_a_chat(1, a_chat_str); 


    armour = clone_object("/wizards/irmeli/castle/eq/gloves.c");
    move_object(armour, this_object());
    init_command("wear gloves");

    weapon = clone_object("/wizards/irmeli/castle/eq/longsword.c");
    move_object(weapon, this_object());
    init_command("wield sword");

}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Knight bashes you with his shield SPILLING blood everywhere!\n");
  say("Knight bashes "+ob->query_name()+" with his shield SPILLING blood everywhere!\n", ob);
  ob->hit_with_spell(500, "physical");


}
    
monster_died() {
    tell_room(environment(this_object()), "You give the last deathblow to the Master Knight. He falls down to the ground.\n"+
              "A prisoner breaks up his chains and walks to you.\n"+
              "Prisoner says: 'Thanks for rescuing me!'\n"+
              "Prisoner continues: 'Here is a cross for you.'\n"+
              "The prisoner vanishes through the door.\n");
               move_object(clone_object("/wizards/irmeli/castle/object/cross.c"), this_player());
}
  extra() {
    object beast;
    if (!attacker_ob) {
        return;
    }

    if(number_of_beasts<2) {
    if(random(number_of_beasts + 1) == number_of_beasts) {
        beast = clone_object("/wizards/irmeli/castle/monsters/assasinknight.c");
        move_object(beast, environment(this_object()));
        say("The Master Knight rises his sword.\n"+
            "He prays for backup!\n"+
            "An assassin knight answers to the pray and steps between you and the Master Knight.\n");
        number_of_beasts += 1;
    }
}
}

reduce_number() {
    number_of_beasts -= 1;
}
