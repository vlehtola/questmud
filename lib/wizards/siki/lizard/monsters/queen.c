inherit "obj/monster";

reset(arg) {






    string chat_str;
    object armour,armour2;
    int i;
    ::reset(arg);

    if(arg) { return; }
    i = random(3);
    
    set_level((i+1)*5+67);
    set_name("amerl'da");
    set_alias("amerl'da");
    set_str(query_str()*2);
    set_int(query_int()*3);
    set_alt_name("queen");
    set_alias("lizard");
    set_race("lizardman");
    set_short("The lizardqueen Amerl'da");
    set_long("A very important looking female lizardman standing proudly in the corner of the room.\n"+
             "As you look closer, you notice that she is actually miserable.\n");


    set_al(50);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(2);
    set_mage();
    set_log();
    set_special(100);
    if (!chat_str) {
        chat_str = allocate(2);
    chat_str[0] = "The lizardqueen looks sad.\n";
    chat_str[1] = "Amerl'da hisses 'Kar'hheni sayhs thhats he hash foundh anothers dimensshion.'\n";

       }
    load_chat(5, chat_str);



    if(i==0) { armour = clone_object("/wizards/siki/lizard/eq/queencoat");
    move_object(armour,this_object());
    init_command("wear coat");
              }
    if(i==1) { armour = clone_object("/wizards/siki/lizard/eq/queengloves");
    move_object(armour,this_object());
    init_command("wear gloves");
              }
    if(i==2) { armour = clone_object("/wizards/siki/lizard/eq/queencoat");
    move_object(armour,this_object());
    init_command("wear coat");
    armour2 = clone_object("/wizards/siki/lizard/eq/queengloves");
    move_object(armour2,this_object());
    init_command("wear gloves");
              }
}
special_move() {
  object ob;
  ob = present("king", environment(this_object()));
  if(attacker_ob && ob) {
    tell_room(environment(this_object()), "The lizardking screams in fury and protects the queen.\n");
    ob->attack_object(attacker_ob);
    return 1;
  

  }

}
