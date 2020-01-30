inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 75);
    call_other(this_object(), "set_name", "mummy");
    call_other(this_object(), "set_alias", "mummy");
    call_other(this_object(), "set_short", "A Strange Mummy (undead)");
    call_other(this_object(), "set_long", "This mummy is wearing a\n"+
                                          "strange wrapping...\n"+
                                          "He seems to be undead\n");
    call_other(this_object(), "set_al", 0);
    set_block_message("Mummy blocks your attempt.");
    call_other(this_object(), "set_aggressive", 0);
}
