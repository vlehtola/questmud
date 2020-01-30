inherit "obj/monster";


reset(arg) {
   object ball;
   string chat_str;
   ::reset(arg);

    set_name("Gnome Child");
    set_level(1);
    set_al(60);
    set_alias("gnome");
    set_alt_name("child");
    set_race("gnome");

       set_short("Gnome child");
       set_long("Why does this little Gnome Child look so sad ? maybe it because he has \n"+
                       "nobody to play ball with. Instead he just sits here kicking the dust.\n");
  
  ball = clone_object("/wizards/phoebus/private/ball");
  move_object(ball, this_object());

    if(!chat_str) {
         chat_str = allocate(3);
         chat_str[0] = "Child says: I've got no friends, will you play with me?\n";
         chat_str[1] = "Child crys: People just ignore me.\n";
         chat_str[2] = "Child says: Those mean old trolls, I'm gonna beat then up.\n";
   }
    load_chat(50, chat_str);
}
