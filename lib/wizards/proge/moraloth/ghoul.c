inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 13);
    call_other(this_object(), "set_name", "ghoul");
    call_other(this_object(), "set_short", "Ghoul of the haunted forest");
    call_other(this_object(), "set_long",
"In front of you stands this huge grey and white ghoul. Its a\n"+
"nasty looking undead. This is the creature of the dark, raised\n"+
"by evil powers within this forest. It is swinging its horrid\n"+
"limbs in the air and seems hostile.\n");
    call_other(this_object(), "set_al", -8);
    call_other(this_object(), "set_aggressive", 1);
    call_other(this_object(), "set_undead", 1);
}

