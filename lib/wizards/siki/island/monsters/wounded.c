inherit "obj/monster";
int num;
reset(arg) {
    string chat_str, a_chat_str;
    object armour;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(30);
    set_name("giant");
    set_alias("male");
    set_short("A huge male giant with a broken leg");
 set_long("This poor giant's left leg is broken. His knee has a large cut\n"+
          "wound. There is some coagulated blood and a bone sticks out from\n"+
          "his knee. Despite this he is strong and in good shape.\n");
    set_al(0);
    set_gender(1);
    set_race("giant");
    set_aggressive(0);
    if (!chat_str) {
        chat_str = allocate(2);
 chat_str[0] = "The giant booms 'Damn I'm hungry!'\n";
 chat_str[1] = "The giant booms 'Since I broke my leg, I haven't been able to\n"+ 
               "hunt rabbits. I haven't had rabbitsoup in weeks!'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(2);
        a_chat_str[0] = "The giant whines about his broken leg.\n";
        a_chat_str[1] = "The giant begs for mercy as he stumbles.\n";

    }
    load_chat(5, chat_str);
    load_a_chat(2, a_chat_str);


    weapon = clone_object("/wizards/siki/island/eq/club");
    move_object(weapon,this_object());
    init_command("wield club");
    armour = clone_object("/wizards/siki/valley/eq/larmour");
    move_object(armour,this_object());
    init_command("wear armour");

}

catch_gives() {

 object ob;
 ob = present("corpse of rabbit", this_object());
 if (ob) {
   num += 1;
   if (num == 10) {
 say("The giant booms 'Thank you! Here is a little bowl of rabbitsoup for\n"+
     "you too. It is good for your health.'\n");
      move_object(clone_object("/wizards/siki/valley/obj/rabbitsoup"), this_player());
      if(!this_player()->query_quests("rabbit_soup")) {
      this_player()->set_quest("rabbit_soup", 10);
      }
      num = 0;
      destruct(ob);
      return 1;
   }
 say("The giant booms 'Thank you, but I still need "+(10-num)+" more corpse\n"+
     "to make a rabbitsoup' and puts the corpse in a kettle.\n");
   destruct(ob);
   return 1;
 }
}


