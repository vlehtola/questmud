inherit "obj/monster";

int number_of_beasts;
reset(arg) {
    object armour,armour2,weapon;
    string chat_str, a_chat_str;
    int i;
::reset(arg);
    number_of_beasts = 0;
if (arg) { return; }
    i = random(2);
    set_level(70);
    set_str(700);
    set_extra(1);
    set_int(query_int()*2);

    set_name("scarecrow");
    set_short("The Scarecrow, raiser of Fear and Chaos");
    set_long("A man, who has dressed as a scarecrow, for scaring the crows\n"+
             "away from the corn. His sharp-chin is covered with thick, white\n"+
             "beard, like his cheeks and neck. His long, brown hair undulates,\n"+
             "as the wind blows. He has a muscular body, strong hands and\n"+
             "powerful legs.\n");
         
    set_al(-50);
    set_gender(1);
    set_race("human");
    set_aggressive(0);
    set_max_hp(50000);
    set_hp(50000);
    set_log();
    set_dead_ob(this_object());
    set_mage(1);
    set_special(25);

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] = "Scarecrow says: 'The Enchantress is protecting the northern forest, especially that big laurel tree.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Scarecrow says: 'The raven will land soon.'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(3, a_chat_str);


    armour = clone_object("/wizards/irmeli/valley/eq/hat");
    move_object(armour, this_object());
    init_command("wear hat");

    if(i==0) { weapon = clone_object("/wizards/irmeli/valley/eq/scythe");
    move_object(weapon, this_object());
    init_command("wield scythe");

    }
    if(i==1) { armour2 = clone_object("/wizards/irmeli/valley/eq/belt");
    move_object(armour2, this_object());
    init_command("wear belt");
}
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Scarecrow raises his hands HIGH above to the sky, conducting a LIGHTNING towards you!\n");
  say("Scarecrow conducts a LIGHTNING towards "+ob->query_name()+" by raising his hands HIGH above to the sky!\n", ob);
  ob->hit_with_spell(800, "electric");
}

monster_died() {
    object ob;
    tell_room(environment(this_object()), "As the Scarecrow dies, a raven appears among the clouds and starts\n"+
              "circling around you. A double-headed raven lands on to the ground.\n"+
              "The raven croaks: 'Finally the Scarecrow is DEAD, now it is your\n"+
              "turn to die.'\n"+
              "The double-headed raven attacks you!\n");
    ob = clone_object("/wizards/irmeli/valley/monsters/raven");
    move_object(ob,environment(this_object()));
}

  extra() {
    object beast;
    if (!attacker_ob) {
        return;
    }

    if(number_of_beasts<2) {
    if(random(number_of_beasts + 1) == number_of_beasts) {
        beast = clone_object("/wizards/irmeli/valley/monsters/a-angel.c");
        move_object(beast, environment(this_object()));
        say("The Scarecrow claps his hands and shouts: 'Start the retaliation!'\n"+
            "Suddenly an angel rises among the corn, screaming: 'ASSAULT!'\n");
        number_of_beasts += 1;
    }
}
}

reduce_number() {
    number_of_beasts -= 1;
}


