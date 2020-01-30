inherit "obj/monster";

int number_of_beasts;
reset(arg) {
    string chat_str, a_chat_str;
    object armour,armour2;
    int i;
    ::reset(arg);
    number_of_beasts = 0;
    if (arg) { return; }
    set_level(38);
    set_log();
    set_extra(1);
    set_int(query_int()*2);
    set_name("hobbit");
    set_alias("king");
    set_short("King Arthur VII, the old ruler of hobbits");
    set_long("King Arthur VII is the last king in the royal hobbit family. The royal\n"+
             "hobbit dynasty is going to end, because King Arthur doesn't have son or\n"+
             "brother, who would continue ruling in the hobbit empire. He is old,\n"+
             "long-lived king in the royal hobbit family, but now he is near death,\n"+
             "it's only matter of days when he dies. His long, brown hair is turning\n"+
             "into silver-grey.\n");

    set_race("hobbit");
    i = random(2);
    set_gender(1);
    set_al(10);
    set_aggressive(1);
        if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
          "Arthur says: 'I'm too old to rule this empire.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Arthur says: 'I should retire soon.'\n";
    }
    load_chat(7, chat_str);
    load_a_chat(3, a_chat_str);

    if(i==0) { armour = clone_object("/wizards/irmeli/area2/equ/boots.c");
    move_object(armour, this_object());
    init_command("wear boots");
}
    if(i==1) { armour = clone_object("/wizards/irmeli/area2/equ/crown.c");
    move_object(armour,this_object());
    init_command("wear crown");
}     
}
  extra() {
    object beast;
    if (!attacker_ob) {
        return;
    }

    if(number_of_beasts<2) {
    if(random(number_of_beasts + 1) == number_of_beasts) {
        beast = clone_object("/wizards/irmeli/area2/bodyguard");
        move_object(beast, environment(this_object()));
        say("Arthur shouts: 'Bodyguards, I have been attacked!'\n"+
            "Suddenly, a royal bodyguard rushes in from north\n"+
            "and starts to defend the king!\n");
        number_of_beasts += 1;
    }
}
}

reduce_number() {
    number_of_beasts -= 1;
}
