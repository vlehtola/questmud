inherit "obj/monster";

int q;

reset(arg) {
    int i;
    string chat_str;
    object armour,armour2,weapon,weapon2;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    q = 0;
    
    set_level((i+2)*3+58);
    set_name("seb'stunus");
    set_alias("king");
    set_alt_name("seb'stunus");
    set_alt_alias("lizard");
    set_race("lizardman");
    set_al_aggr(400);

    set_str(query_str()*2);

    set_special(100);  /* Enable special_move() */

    set_short("The lizardking Seb'stunus");
    if (!q) {
      set_long("An old but strong lizardman standing proudly in the middle\n"+
             "of the room. He is wondering something and doesn't look happy\n"+
             "at all.\n");
    }
    set_al(90);
    set_aggressive(0);
    set_gender(1);
    
    set_log();

    set_skill("tremendous blow", 60);
   set_skill_chance("tremendous blow", 12);

    if (q==0) {
     if (!chat_str) {
      chat_str = allocate(2);
      chat_str[0] = "The lizardking hisses 'Ehvil ssshea monsshter wrechks\n"+
                  "our villaghe!'\n";
      chat_str[1] = "The lizardking hisses 'If onhly sshomeone couldh khill\n"+
                  "thhe ssshea monsshter.'\n";
     }
     load_chat(5, chat_str);
    }

    weapon = clone_object("/wizards/siki/lizard/eq/sword");
    move_object(weapon,this_object());
    weapon2 = clone_object("/wizards/siki/lizard/eq/sword");
    move_object(weapon2,this_object());
    init_command("wield sword");
    init_command("wield sword 2");



    if(i==0) { armour = clone_object("/wizards/siki/lizard/eq/kingtorso");
    move_object(armour,this_object());
    init_command("wear plate");
      }

    if(i==1) { 
    armour = clone_object("/wizards/siki/lizard/eq/kinglegs");
    move_object(armour,this_object());
    init_command("wear leggings");

     }

    if(i==2) { 
    armour = clone_object("/wizards/siki/lizard/eq/kingtorso");
    move_object(armour,this_object());
    init_command("wear plate");
    armour2 = clone_object("/wizards/siki/lizard/eq/kinglegs");
    move_object(armour2,this_object());
    init_command("wear leggings");
     }
}
catch_tell(str) {
   string tmp1,tmp2, chat_str;
   object ob;
   ::catch_tell(str);
   
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("head", this_object());
    if (!ob->query_no_save() && this_player()->query_name() == tmp1) { /*Modified by Ahma due to the illusion abuse.*/
    destruct(ob);
    write("The lizardking looks at the head and says 'Thhanks you! I willh reshward\n");
    write("yoush!' and gives you a small medallion.\n");
    move_object(clone_object("/wizards/siki/lizard/eq/medallion"), this_player());
    this_player()->set_quest("Bring the head of the seamonster to the Lizard King");
    q = 1;
    chat_str = allocate(1);
    chat_str[0] = "The lizardking hisses '" + this_player()->query_name() +
      " killhed thhe seamonsster, now our villaghe is ssafe'.\n";
    load_chat(5, chat_str);
    set_long("An old but strong lizardman standing proudly in the middle\n"+
     "of the room. He looks releaved.\n");
   }
 }
   

}

special_move() {
 object ob;
 ob = present("queen", environment(this_object()));
 if(attacker_ob && ob) {
   tell_room(environment(this_object()), "The lizardqueen hisses and attacks "+
      attacker_ob->query_name()+".\n");
   ob->attack_object(attacker_ob);
   return 1;
 }

}




