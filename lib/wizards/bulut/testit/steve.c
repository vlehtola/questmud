inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
shout ("Steve shouts 'Muahahha.. whatta stoopid looking place..\n");
    ::reset(arg);
    if(arg) { return; }
set_level(32);
    set_name("steve");
    set_alias("man");
    set_short("A grinning man");
    set_long("A grinning man, annoying people.\n");
    set_al(0);
    set_spell_chance(20, "exs fla blt");
    set_skill("cast essence", 20);
    set_skill("cast fire", 50);
    set_skill("cast grasp", 50);
    set_skill("mana control", 20);
    set_aggressive(0);
    set_move_at_random(0);

    if (!chat_str) {
        chat_str = allocate(3);
         chat_str[0] =
          "Man says: Wanna die, fucker?\n";
        chat_str[1] =
          "Man says: I Hate this damn place....\n";
        chat_str[2] =
"Man grins evilly.\n";
load_chat(30, chat_str);

}
}

