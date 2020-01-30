inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object axe,axe2;
    ::reset(arg);
    if(arg) { return; }
    set_level(52+random(17));
    set_name("sinakgalun");
    set_alias("dwarf");
    set_alias("guard");
    set_short("Sinakgalun the dwarf");
    set_long("Before you stands a bearded fellow, just over 5 feet tall, and stout\n"+
             "as a barrel. The good man's beard is over one foot long, and it is tied\n"+
             "to a knot at the end. Sinakgalun is leaning on a huge battle axe.\n");
    set_race("dwarf");
    set_gender(1);
    set_al(-8);
    set_str(486);
    set_con(519);
    set_aggressive(0);
    set_block_dir("west"); 
    set_skill("axes",100);
    set_skill("cut",90);
    set_skill("find weakness", 85);
    set_skill("doublehit", 70);
    set_skill("weapon parry", 100);


    axe = clone_object("/wizards/walla/northern/stuph/better_axe");
    move_object(axe, this_object());
    init_command("wield axe");

    axe2 = clone_object("/wizards/walla/northern/stuph/better_axe");
    move_object(axe2, this_object());
    init_command("wield axe");
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Sinakgalun kicks you in the kneecap with deadly accuracy.\n";
        chat_str[1] =
          "Sinakgalun states: 'What the fuck are you doing here, boy?'.\n";
        chat_str[2] =
          "Sinakgalun exclaims: 'Get the fuck out of here, punk!'\n";
 
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Sinakgalun yells: 'Very well, if that is your custom!'.\n";
    }
       load_chat(6, chat_str);
       load_a_chat(7, a_chat_str);
 
}
