inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    object axe;
    ::reset(arg);
    if(arg) { return; }
    set_level(32+random(4));
    set_name("tarahandag");
    set_alias("dwarf");
    set_alias("guard");
    set_block_dir("down");
    set_short("Tarahandag the dwarf");
    set_long("Before you stands a bearded fellow, just over 5 feet tall, and stout\n"+
             "as a barrel. The good man's beard is over one foot long, and it is tied\n"+
             "to a knot at the end. The dwarf is leaning on a huge battle axe.\n");
    set_race("dwarf");
    set_gender(1);
    set_al(-8);
    set_aggressive(0);
 
    axe = clone_object("/wizards/walla/northern/stuph/basic_axe");
    move_object(axe, this_object());
    init_command("wield axe");
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Tarahandag intones: 'Were I just a little bit taller, I'd part your head from your body in a single swing'.\n";
        chat_str[1] =
          "Tarahandag states: 'These damp floors give me a rheumatism. Soon i'll be getting a bottle of dwarf spirits'.\n";
        chat_str[2] =
          "Tarahandag exclaims: 'By the mane of a griffon! You are the biggest person I have ever seen'.\n";
 
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Tarahandag yells: 'Ah, my creaky old carcass isn't what it used to, but it can still cut you in two'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
 
}
