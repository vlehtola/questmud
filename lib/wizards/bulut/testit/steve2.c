inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(34);
    set_name("steve");
    set_alias("man");
    set_short("A grinning man");
    set_long("A grinning man, annoying people.\n");
    set_al(0);
    set_spell_chance(60, "exs fla blt");
    set_skill("cast essence", 20);
    set_skill("cast fire", 50);
    set_skill("cast grasp", 60);
    set_skill("mana control", 20);
    set_aggressive(0);
    set_move_at_random(0);

    if (!chat_str) {
        chat_str = allocate(4);
         chat_str[0] =
          "Man says: Wanna die, fucker?\n";
        chat_str[1] =
          "Man says: I Hate this damn place....\n";
        chat_str[2] =
          "Man grins evilly.\n";
        chat_str[3] =
          "Man says: You sure look dumb!\n";
load_chat(30, chat_str);
                   }

catch_tell(str) {
  object ob,player;
  string tmp,tmp2;
  if(sscanf(str,"%s gives %s to "+cap_name+".",tmp,tmp2) == 2) {
        player = find_player(tmp);
        tell_object(player,cap_name+" perarrg.\n");
        return 1;

        say(cap_name+" says: 'Thanks!'\n");
        return 1;
    }
  }
}

}

