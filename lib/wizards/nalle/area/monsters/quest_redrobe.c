inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 22);
    set_mage(1);
    call_other(this_object(), "set_name", "Mage");
    call_other(this_object(), "set_alias", "mage");
    call_other(this_object(), "set_short", "A red-robed mage is guarding the door leading to west.");
    call_other(this_object(), "set_long", "This seems to be one of Darvox's apprentices. He is\n" +
                                          "wearing red robes, which conceal even his face.\n");
    call_other(this_object(), "set_al", 0);
    call_other(this_object(), "set_aggressive", 0);

    chat_str = allocate(2);
    chat_str[0] = "Mage mutters: 'If you could give a an recommendation, maybe then.. maybe then..'\n";
    chat_str[1] = "Mage says: 'Know Sorian, huh? Ask him, yes.. ask for a recommendation.'\n";

    load_chat(30,chat_str);

    armour = clone_object("/wizards/nalle/area/eq/magcloak");
    move_object(armour, this_object());
    init_command("wear armour");

    weapon = clone_object("/wizards/nalle/area/eq/magstaff");
    move_object(weapon, this_object());
    init_command("wield staff");
}

init() {
  ::init();
  add_action("west", "west");
}

west() {
  if(!this_player()->query_guild_level("Illusionists") &&
     !this_player()->query_guild_level("electricity school") &&
     !this_player()->query_quests("mage_recommendation")) {
    say("Mage hisses: 'No.. no, you cannot pass, you're not a member..'\n");
    return 1;
  }
  say("Mage mutters: 'Yes yes.. you may pass..'\n");
}

gived_you(ob) {
  if (ob->query_recommendation()) {
    write("Mage says 'Ah.. you brought me a recommendation.. you may pass.'\n");
    this_player()->set_quest("mage_recommendation");
  }
}
