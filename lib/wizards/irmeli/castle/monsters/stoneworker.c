inherit "obj/monster";


reset(arg) {
  object weapon;
  string chat_str, a_chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_name("stoneworker");
  set_alias("elliot");
  set_level(90);
  set_log();
  set_gender(1);
  set_race("human");
  set_str(query_str()*2);
  set_exp(8000000);
  set_short("Elliot McArthur, the Stoneworker");
  set_long("Elliot is stoneworker like his father and grandfather was. He is a smith and he is\n" +
           "specialized in stone grinding. Elliot is keeping his workshop in the city of Asgroth.\n" +
           "His hands are strong like his whole muscular body. His short brown hair is dirty and\n"+
           "in a tangle. He seems to be calm and focused.\n");

    weapon = clone_object("/wizards/irmeli/castle/eq/hammer.c");
    move_object(weapon, this_object());
    init_command("wield hammer");

if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
"Stoneworker says: 'Type 'list' if you wan't to buy some stones. I have different sized stones available.'\n";
        chat_str[1] =
"Stoneworker asks: 'Have you seen my brother? He has one of my precious items.'\n";
        chat_str[2] =
"Stoneworker bangs his hammer against a big stone.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Elliot says: 'Taste my Hammer!'\n";
    }
    load_chat(8, chat_str);
    load_a_chat(3, a_chat_str);
}
catch_tell(str) {
 object ob;
 string filu, tmp, tmp2;
 int id;
  if(sscanf(str, "%s gives %s to you.",tmp,tmp2) == 2) {
   ob = present("cross", this_object());
   if(ob) {
   if(sscanf(file_name(ob),"%s#%d",filu,id) == 2) {
    if(filu == "/wizards/irmeli/castle/object/cross") {
     destruct(ob);
     say("Stoneworker says: 'My precious cross! Thank you!'\n");
     say("Stoneworker continues: 'Take this hammer as a gift from me! I got plenty of these.'\n");
     move_object(clone_object("/wizards/irmeli/castle/eq/hammer"), this_player());
     this_player()->set_quest("Return stoneworker's precious cross");
 }
 }
}
}
}
