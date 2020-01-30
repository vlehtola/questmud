/* Storagekeeper is a monster that wants a sack of flour. When he gets the proper sack of flour (query_real_flour() == 1)
   he thanks the player and gives a quest marker.

   Idea by Yodin. Technical additions and comments by Celtron.
*/

inherit "obj/monster";

// use start() instead of reset()
start() {
  string chat_str, a_chat_str;
  set_name("keeper");
  set_short("A dirty storage keeper.");
  set_long("A storage keeper that keeps storage full and clean.\n");
  set_level(100);
  set_gender(1);
  set_alias("human");
  set_race("human");
  set_mage(1);
  set_al(0);


if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] =
        "Keeper says: 'I have run out of flour.. Could you get some for me?'\n";
        chat_str[1] =
        "Keeper says: 'Please i need more flour so we can make more bread.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Keeper says: 'I love my job'\n";
    }

    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);

}

catch_tell(str) {
    string giver,item,tmp;
    object ob, sack;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {

      // ob is the player that gave the sack to us

      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }

      sack = present("sack", this_object()); 	// is there an object in the monsters inventory called 'sack'?
      if (!sack) { return; }			// if not, then exit
      if (!sack->query_real_flour())	{	// is the object the sack that contains the real flour?
	tell_room(environment(this_object()), "Keeper gets upset: 'That's not the proper flour!'\n");
        call_out("destroy_sack", 0, sack);  	// destroy the wrong sack from storekeepers inventory
	return 1;  				// exit and stop resolving the command
      }

      // if we got this far, then there is a sack of flour in the storagekeepers inventory, which has the proper flour.
      // keeper thanks for the sack and gives the quest

      tell_object(ob, "Keeper says: 'Thank you very mutch now we can make more bread.'\n");
      tell_object(ob, "You complete the 'Help the baker' quest.\n");
      call_other(ob, "set_quest", "Help the baker");

      // destroy the flour sack for good so that the next player has also to give a sack of proper flour
      call_out("destroy_sack", 0, sack);
    }
}

// we have to use call_out to prevent give-command from bugging. The command needs the object in order to resolve.
// after one round we can destroy the sack without causing problems

destroy_sack(object sack) {
  destruct(sack);
}
