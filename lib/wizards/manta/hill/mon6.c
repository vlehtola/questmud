inherit "obj/monster";

reset(arg) {
        string chat_str;
      object money,weapon,armour;
        ::reset(arg);
        if(arg) { return; }
        call_other(this_object(), "set_level", 35);
        call_other(this_object(), "set_name", "guard");
        call_other(this_object(), "set_alias", "human");
        call_other(this_object(), "set_short", "A scared guard");
        call_other(this_object(), "set_long", "You found guard who somehow is still alive\n");
        call_other(this_object(), "set_al", 30);
          call_other(this_object(), "set_aggressive", 0);

          if (!chat_str) {
          chat_str = allocate(3);
          chat_str[0] = "Please don't hurt me!!!\n";
          chat_str[1] = "have they gone already?\n";
          chat_str[2] = "They are horrrible you know\n";
          }
          load_chat(10, chat_str);

          weapon = clone_object("/wizards/manta/hill/wea1");
          move_object(weapon, this_object());
init_command("wield sword");

          armour = clone_object("wizards/manta/hill/arm1");
          move_object(armour, this_object());
init_command("wear plate");
}
