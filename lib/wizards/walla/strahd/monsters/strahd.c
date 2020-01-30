inherit "obj/monster"; 
 
reset(arg) {
    string chat_str, a_chat_str;
    object money;
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 69);
        call_other(this_object(), "set_name", "strahd");
        call_other(this_object(), "set_alias", "vampire");
        call_other(this_object(), "set_short", "Strahd von Sarovich");
        call_other(this_object(), "set_long", "Strahd von Sarovich, the greatest immortal vampire\n" +                     
       "of all times stands majestetically here and scares the shit out of you.\n");
       call_other(this_object(), "set_al", -21);
      call_other(this_object(), "set_aggressive", 0);                    
      set_spell_chance(100, "exs mir gsh");
      set_spell_chance(100, "exs sol gsh");
      set_spell_chance(100, "exs sol grs");
      set_skill("cast essence", 100);
      set_skill("cast mirror image", 100);
      set_skill("cast major protection", 100);
      set_skill("cast earth", 100);
      set_skill("cast grasp", 69);
      set_skill("critical", 100);
      set_skill("kick", 100);
      set_skill("reflect spell", 100);
      set_skill("attack", 100);
      set_skill("dodge", 100);
      set_skill("parry", 100);
      set_skill("tumble", 100);
   
if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Strahd performs a shapeshift trick and transforms himself to a wolf.\n";
        chat_str[1] =
          "Strahd leaps forward, and bites you, sucking some of your blood.\n";
        chat_str[2] =
          "Strahd says: I'm the ruler of Barovia. No one can do anything about it.\n";
        chat_str[3]=
          "Strahd says: I have killed more men, that you could even count. But the greatest will be you.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Strahd says: very well, we'll have it your way.\n";
    }
 load_chat(30, chat_str);   
    load_a_chat(15, a_chat_str);
 
    money = clone_object("obj/money");
    call_other(money, "set_money", random(1000)+1230);
    move_object(money, this_object());
 
   
        armour = clone_object("/wizards/walla/strahd/armour/coh");
        move_object(armour, this_object());
        init_command("wear cloak");
 
        armour = clone_object("/wizards/walla/strahd/armour/strhood");
        move_object(armour, this_object());
        init_command("wear hood");
 
        armour = clone_object("/wizards/walla/strahd/armour/sleeves");
        move_object(armour, this_object());
        init_command("wear sleeves");
 
        weapon = clone_object("/wizards/walla/strahd/weapons/dagger");
        move_object(weapon, this_object());
        init_command("wield dagger");
 

}
 
catch_tell(str) {
  object ob,player;
  string tmp,tmp2;
  if(sscanf(str,"%s gives %s to "+cap_name+".",tmp,tmp2) == 2) {
    if(ob = present(tmp2,this_object())) {
      if(ob == find_object("/wizards/walla/eku")) {
        player = find_player(tmp);
        /* quest completed */
        player->add_exp(1);
        player->add_money(1);
        tell_object(player,cap_name+" gives you staff.\n");
        move_object(clone_object("/wizards/walla/area/weapons/rstaff2"), player);
        return 1;
      } else {
        say(cap_name+" says: 'Thanks!'\n");
        return 1;
    }
  }
 }
} 

