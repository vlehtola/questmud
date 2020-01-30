inherit "obj/monster";
/*Str & Hp tune by Ahma*/

int number_of_beasts;
reset(arg) {
    int i;
    object weapon,armour,armour2;
    ::reset(arg);
    number_of_beasts = 0;
    if(arg) { return; }
    i = random(3);

    set_level((i+2)*5+40);
    set_name("Kar'hheni");
    set_alias("shaman");
    set_alt_name("kar'hheni");
    set_alt_name("lizard");
    set_alt_name("lizardman");
    set_race("lizardman");
    set_int(query_int()*2);
    set_str(query_str() + 200);
    set_max_hp(query_max_hp() + 20000 + random(2000));
    set_hp(query_max_hp());
    set_extra(1);
    set_short("The shaman of the village, Kar'hheni (surrounded by purple mist)");
    set_long("A strong looking lizardman with a strange purple mist around him.\n"+
             "The color of the scales is very strong, like the scales of a newborn\n"+
             "lizardman.\n");
    set_al(70);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);
    set_log();
    set_mage(1);


    weapon = clone_object("/wizards/siki/lizard/eq/staff");
    move_object(weapon,this_object());
    init_command("wield staff");



    if(i==0) { armour = clone_object("/wizards/siki/lizard/eq/shahead");
    move_object(armour,this_object());
    init_command("wear skull");

      }
    if(i==1) { armour = clone_object("/wizards/siki/lizard/eq/shaboots");
    move_object(armour,this_object());
    init_command("wear boots");

       }
    if(i==2) { armour = clone_object("/wizards/siki/lizard/eq/shahead");
    move_object(armour,this_object());
    init_command("wear skull");
    armour2 = clone_object("/wizards/siki/lizard/eq/shaboots");
    move_object(armour2,this_object());
    init_command("wear boots");

}
}
  extra() {
    object beast;
    if (!attacker_ob) {
        return;
    }

    if(number_of_beasts<5) {
    if(random(number_of_beasts + 1) == number_of_beasts) {
        beast = clone_object("/wizards/siki/lizard/monsters/beast");
        move_object(beast, environment(this_object()));
        say("Shaman waves his finger and a multicolored portal opens.\n"+
            "A strange beast jumps out from the portal and the portal\n"+
            "disappears.\n");
        number_of_beasts += 1;
    }
}
}

reduce_number() {
    number_of_beasts -= 1;
}


