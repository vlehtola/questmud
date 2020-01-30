inherit "/room/room";

/* 10min limit */
status check_if_idle(object user) {
  if(query_idle(user) > 600) return 1;
  return 0;
}

status move_to_tavern(object user) {
  user->move_player("east", "/world/city/tavern");
  return 1;
}

reset(status arg) {
  object idle_users;
  idle_users = filter_array(all_inventory(this_object()), "check_if_idle");
  filter_array(idle_users, "move_to_tavern");

  if(arg) return;

  add_exit("north", "/world/city/mainstr5");
  add_exit("west", "/world/city/adventurers_hall");
  add_exit("east", "/world/city/tavern");

  short_desc = "The inn of Duranghom";
long_desc =
"The inn of Duranghom is full of people from every part of Deleria.\n" +
"Above you lies a thick smoke, which makes the light coming from the\n" + 
"candles and the fireplace dimmer. You feel comfortable warmth coming\n" +
"from the fireplace, situated on the southeast corner of the hall.\n" +
"Bards are playing happy music, which fills your ears and makes\n" +
"you feel safer than outside.\n\n" +
"    Use 'safe_quit' to save 5 items.\n\n"+
"There is a glowing corridor leading to the south.\n";


    property = allocate(4);
    property[0] = "no_kill";
    property[1] = "no_skill";
    property[2] = "no_spell";
    property[3] = "no_summon";
    set_not_out(1);
    set_light(3);
}

init() {
  ::init();
  add_action("safe_quit", "safe_quit");
  add_action("south", "south");
}

south() {
    if (!this_player()->query_wiz()) { write("You are not a wizard.\n"); return 1; }
    this_player()->move_player("south#world/city/innstabl");
    return 1;
}

safe_quit() {
    object ob;
    int i;
    ob = first_inventory(this_player());
    while(ob) {
        if (!ob->query_auto_load() && ob->short() && !ob->query_no_save()) {
            i += 1;
        }
        else if(ob->query_weapon()) {
          write("You can't quit safely with damaged weapon.\n");
          return 1;
          write("Damaged weapons are not saveable.. dropped: "+ob->short()+"\n");
          say(this_player()->query_name()+" leaves "+ob->short()+" behind as "+this_player()->query_pronoun()+" enters a chamber.\n");
          move_object(ob, this_object());
        }
        if (i > 5) {
            write("You have more than 5 items, cannot safe_quit.\n");
            return 1;
        }
        ob = next_inventory(ob);
    }
    this_player()->compute_safe_str();
    if(this_player()->quit() != -1) {
      write("Safe_quitting..\n");
    }
}

                
