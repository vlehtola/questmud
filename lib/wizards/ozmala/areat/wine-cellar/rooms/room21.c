inherit "room/room";
object ob;
int bottle;

reset(status arg) {
  if(arg) return;
  add_exit("north","/wizards/ozmala/areat/wine-cellar/rooms/room20");
  add_exit("west","/wizards/ozmala/areat/wine-cellar/rooms/room22");
  short_desc = "shotdesc";
  long_desc =
"You are standing in a large wine cellar, there are several torches on\n" +
"the wall's lighting up the place. There is a sour odor in here, it must\n" +
"be coming out of those several oaken barrels all around the room. Poorly\n" +
"builded wall's surround you, you can see some loosened tiles here and there.\n";
  property = allocate(1);
  property[0] = "no_summon";
  set_not_out();
  set_light(3);
}

search_finished(str) {
        if(bottle == 0 && str == "bottle") {
                write("You find an old bottle\n");
                say(this_player()->query_name()+ " finds an old vintage wine bottle\n");
                ob = clone_object("/wizards/ozmala/questobj/bottle");
                move_object(ob,environment(this_player()));
                bottle = 1;
                return 1;

        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}