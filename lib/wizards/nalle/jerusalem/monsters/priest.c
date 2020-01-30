inherit "obj/monster";

reset(arg) {
    string chat_str;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_race("human");
    call_other(this_object(), "set_level", 39);
    call_other(this_object(), "set_name", "priest");
    call_other(this_object(), "set_alias", "Priest");
    call_other(this_object(), "set_short", "A priest holding a sermon");
    call_other(this_object(), "set_long", "A priest holding a sermon in latin. He seems strong.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);

   chat_str = allocate(2);
   chat_str[0] ="The priest whispers 'Pax Vobiscum' and indicates you should take a seat.\n";
   chat_str[1] ="The priest roars 'Liberate teteme ex infernis!'\n";
   load_chat(21, chat_str); 

    weapon = clone_object("/wizards/nalle/jerusalem/eq/staff");
    move_object(weapon, this_object());
    init_command("wield staff");
}
