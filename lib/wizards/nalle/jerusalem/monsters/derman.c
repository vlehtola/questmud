inherit "obj/monster";
object varjo;
reset(arg) {
   ::reset(arg);
set_name("man");
set_level(21);
set_al(30);
set_gender(1);
set_race("human");
set_short("A wounded man carrying a cross");
set_long("A wounded man sentenced to be crucified, carrying a large cross.\n");
}

init() {
    ::init();
   add_action("help", "help");
}

help(str) {
  object ob;
  if (str == "man") {
    write("You help the wounded man and heave the heavy wooden cross on your back.\n");
    say(this_player()->query_name()+" takes the cross from the wounded man and starts carrying it.\n");  
    write("The man thanks you and sits down to rest his aching bones.\n");
    write("Before you know it, soldiers start leading you towards Golgatha.\n");
    varjo = clone_object("/wizards/nalle/jerusalem/eq/varjo.c");
    varjo->start(this_player());
    ob = present("coins",this_object());
    if(ob) destruct(ob); /* fixed potential bug. //Celtron */
    destruct(this_object());
  return 1;
  } else { return; }
}
