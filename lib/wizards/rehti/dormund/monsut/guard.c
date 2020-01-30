inherit "obj/monster";

string str;

reset(arg) {
    string chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_name ("guard");
    set_level (30);
    set_gender(1);
    set_al(20);
    set_alias("guard");
    set_race("human");
    set_short("Guard is here watching the castle looking rather bored.");
    set_long("This guard seems to be bored since every attack is blockked by front gate.\n");
    set_aggressive(0);
}

ask_question(str) {
    if(str == "sign") {
         say("Guard says: 'That sign has been there since we got here. No one can say what it means'\n");
         return 1;
}

}