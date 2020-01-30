inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object axe;
    ::reset(arg);
    if(arg) { return; }
    set_level(32+random(4));
    set_name("murbun");
    set_alias("dwarf");
    set_alias("guard");
    set_short("Murbun the dwarf");
    set_long("Before you stands a bearded fellow, just over 5 feet tall, and stout\n"+
             "as a barrel. The good man's beard is over one foot long, and it is tied\n"+
             "to a knot at the end. Hrallaug is leaning on a huge battle axe.\n");
    set_race("dwarf");
    set_gender(1);
    set_al(-8);
    set_aggressive(0);
    set_experience(1);
 
    axe = clone_object("/wizards/walla/northern/stuph/basic_axe");
    move_object(axe, this_object());
    init_command("wield axe");
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Murbun kicks you in the kneecap with deadly accuracy.\n";
        chat_str[1] =
          "Murbun states: 'If only i had a barrel to stand on, so i could spit in yer face, lad'.\n";
        chat_str[2] =
          "Murbun exclaims: 'I could probably get a nice price for yer head, laddie. Mind parting with it?'\n";
 
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Murbun yells: 'I'll hit some sense into you, maybe you'll be as smart as a gully dwarf'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
 
}
 




